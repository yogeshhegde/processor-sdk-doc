#!/bin/bash

# Enhanced script to generate versions.json from git tags
# Features:
# - Supports multiple version patterns
# - Adds version metadata (date, commit)
# - Validates JSON output
# - Supports dry-run mode

set -e

# Configuration
OUTPUT_FILE="${1:-versions.json}"
DEV_BRANCH="${DEV_BRANCH:-master}"
DRY_RUN="${DRY_RUN:-false}"
INCLUDE_METADATA="${INCLUDE_METADATA:-false}"

# Color output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

log_info() {
    echo -e "${GREEN}[INFO]${NC} $1"
}

log_warn() {
    echo -e "${YELLOW}[WARN]${NC} $1"
}

log_error() {
    echo -e "${RED}[ERROR]${NC} $1"
}

# Check if we're in a git repository
if ! git rev-parse --git-dir > /dev/null 2>&1; then
    log_error "Not a git repository"
    exit 1
fi

log_info "Generating versions.json from git tags..."

# Get all tags matching version pattern
# Supports: v11.01.05.03, v1.2.3, 11.01.05.03
TAGS=$(git tag -l | grep -E '^v?[0-9]+\.[0-9]+\.[0-9]+(\.[0-9]+)?$' | sort -V -r)

if [ -z "$TAGS" ]; then
    log_error "No version tags found"
    log_info "Available tags:"
    git tag -l
    exit 1
fi

# Get the latest (stable) version
STABLE_VERSION=$(echo "$TAGS" | head -n1)

# Ensure stable version has 'v' prefix
if [[ ! "$STABLE_VERSION" =~ ^v ]]; then
    STABLE_VERSION="v${STABLE_VERSION}"
fi

log_info "Stable version: $STABLE_VERSION"
log_info "Found $(echo "$TAGS" | wc -l) version tags"

# Function to get tag metadata
get_tag_metadata() {
    local tag=$1

    if [ "$INCLUDE_METADATA" = "true" ]; then
        local commit=$(git rev-list -n 1 "$tag" 2>/dev/null || echo "unknown")
        local date=$(git log -1 --format=%ai "$tag" 2>/dev/null || echo "unknown")
        local short_commit=$(echo "$commit" | cut -c1-7)

        echo "\"commit\": \"$short_commit\", \"date\": \"$date\""
    else
        echo ""
    fi
}

# Build JSON content
JSON_CONTENT=$(cat << EOF
{
    "stable_version": "$STABLE_VERSION",
    "versions": [
        {
            "name": "dev",
            "tag": "$DEV_BRANCH",
            "is_released": false$([ "$INCLUDE_METADATA" = "true" ] && echo ", $(get_tag_metadata "$DEV_BRANCH")" || echo "")
        }
EOF
)

# Add each tag
FIRST=true
while IFS= read -r tag; do
    if [ -n "$tag" ]; then
        # Ensure tag has 'v' prefix for consistency
        if [[ ! "$tag" =~ ^v ]]; then
            tag="v${tag}"
        fi

        # Add comma
        JSON_CONTENT+=$',\n'

        # Add version entry
        metadata=""
        if [ "$INCLUDE_METADATA" = "true" ]; then
            metadata=", $(get_tag_metadata "$tag")"
        fi

        JSON_CONTENT+="        {
            \"name\": \"$tag\",
            \"tag\": \"$tag\",
            \"is_released\": true${metadata}
        }"
    fi
done <<< "$TAGS"

# Close JSON
JSON_CONTENT+=$'\n    ]\n}'

# Validate JSON if jq is available
if command -v jq &> /dev/null; then
    if ! echo "$JSON_CONTENT" | jq . > /dev/null 2>&1; then
        log_error "Generated JSON is invalid"
        exit 1
    fi
    log_info "JSON validation: OK"

    # Pretty print with jq
    JSON_CONTENT=$(echo "$JSON_CONTENT" | jq .)
fi

# Output
if [ "$DRY_RUN" = "true" ]; then
    log_warn "DRY RUN mode - not writing to file"
    echo "$JSON_CONTENT"
else
    echo "$JSON_CONTENT" > "$OUTPUT_FILE"
    log_info "Successfully generated $OUTPUT_FILE"
fi

# Summary
echo ""
log_info "Summary:"
echo "  - Stable version: $STABLE_VERSION"
echo "  - Total versions: $(echo "$TAGS" | wc -l) released + 1 dev"
echo ""

if [ "$DRY_RUN" != "true" ]; then
    log_info "Preview:"
    head -n 20 "$OUTPUT_FILE"
    if [ $(wc -l < "$OUTPUT_FILE") -gt 20 ]; then
        echo "  ... ($(wc -l < "$OUTPUT_FILE") total lines)"
    fi
fi
