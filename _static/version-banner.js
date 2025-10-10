(function () {
    'use strict';

    // Wait for DOM to be ready
    if (document.readyState === 'loading') {
        document.addEventListener('DOMContentLoaded', initVersionBanner);
    } else {
        initVersionBanner();
    }

    function initVersionBanner() {
        // Get version info from sphinx-multiversion
        const versionData = getVersionInfo();

        if (versionData.isOldVersion) {
            showVersionBanner(versionData.latestUrl, versionData.latestVersion);
        }
    }

    function getVersionInfo() {
        const currentPath = window.location.pathname;
        const pathParts = currentPath.split('/').filter(p => p);

        // sphinx-multiversion creates URLs like: /v11.1.5.3/index.html or /main/index.html
        const currentVersion = pathParts[0];

        // Check if we're on main/master (latest development) or a version tag
        const isLatest = currentVersion === 'main' || currentVersion === 'master';
        const isOldVersion = currentVersion.startsWith('v') && !isLatest;

        // Construct latest URL (assuming main branch is latest)
        const latestUrl = currentPath.replace('/' + currentVersion + '/', '/main/');

        return {
            currentVersion: currentVersion,
            isOldVersion: isOldVersion,
            isLatest: isLatest,
            latestUrl: latestUrl,
            latestVersion: 'latest'
        };
    }

    function showVersionBanner(latestUrl, latestVersion) {
        // Check if user has dismissed banner
        const dismissKey = 'versionBannerDismissed_' + window.location.pathname.split('/')[1];

        if (sessionStorage.getItem(dismissKey) === 'true') {
            return; // Banner was dismissed for this session
        }

        // Create banner element
        const banner = document.createElement('div');
        banner.className = 'version-warning-banner';
        banner.setAttribute('role', 'alert');
        banner.innerHTML = `
            <div class="banner-content">
                <div class="banner-message">
                    <svg class="banner-icon" xmlns="http://www.w3.org/2000/svg" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2">
                        <path d="M10.29 3.86L1.82 18a2 2 0 0 0 1.71 3h16.94a2 2 0 0 0 1.71-3L13.71 3.86a2 2 0 0 0-3.42 0z"></path>
                        <line x1="12" y1="9" x2="12" y2="13"></line>
                        <line x1="12" y1="17" x2="12.01" y2="17"></line>
                    </svg>
                    <span>
                        You are viewing documentation for an older version.
                        <a href="${latestUrl}" class="banner-link">Switch to latest version</a>
                    </span>
                </div>
                <button class="banner-close" aria-label="Dismiss warning" title="Dismiss for this session">
                    <svg xmlns="http://www.w3.org/2000/svg" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2">
                        <line x1="18" y1="6" x2="6" y2="18"></line>
                        <line x1="6" y1="6" x2="18" y2="18"></line>
                    </svg>
                </button>
            </div>
        `;

        // Insert banner at top of content area, not body
        const contentWrap = document.querySelector('.wy-nav-content-wrap');
        if (contentWrap) {
            contentWrap.insertBefore(banner, contentWrap.firstChild);
        } else {
            // Fallback to body if structure is different
            document.body.insertBefore(banner, document.body.firstChild);
        }

        // Add dismiss functionality
        const closeButton = banner.querySelector('.banner-close');
        closeButton.addEventListener('click', function () {
            banner.remove();
            sessionStorage.setItem(dismissKey, 'true');
        });
    }
})();
