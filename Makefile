# Makefile for Sphinx documentation
#

default: html

# You can set these variables from the command line.
SPHINXOPTS    =
SPHINXBUILD   = sphinx-build
PAPER         =
OS            = linux

mkfile_path = $(abspath $(lastword $(MAKEFILE_LIST)))
export ROOTDIR = $(dir $(mkfile_path))
$(info ROOTDIR is $(ROOTDIR))

$(info DEVFAMILY is $(DEVFAMILY))
FAMILYSETUPFILE = python-scripts/family_setup.py

ifneq ($(DEVFAMILY), $(filter $(DEVFAMILY), GEN CORESDK))
    ifeq ($(DEVFAMILY), AM64X)
       CONFDIR  = source/devices/$(DEVFAMILY)
       TAGFILE  = configs/$(DEVFAMILY)/$(DEVFAMILY)_tags.py
    else
       CONFDIR  = source/devices/$(DEVFAMILY)/${OS}
       TAGFILE  = configs/$(DEVFAMILY)/$(DEVFAMILY)_${OS}_tags.py
    endif
    VERSION     = $(shell cat ${CONFDIR}/version.txt)
else # TODO: this is for supporting the old structure;
     # Remove the else branch after the new structure is used for all device families
    CONFDIR     = source/${OS}
    TAGFILE     = configs/$(DEVFAMILY)/$(DEVFAMILY)_tags.py
    VERSION     = $(shell cat version.txt)
    OS_CONF     = ${CONFDIR}/conf-${OS}.py
endif
$(info TAGFILE is $(TAGFILE))
$(info CONFDIR is $(CONFDIR))
export CONFDIR

BUILDDIR      = build/processor-sdk-${OS}-${DEVFAMILY}/esd/docs/${VERSION}

# User-friendly check for sphinx-build
ifeq ($(shell which $(SPHINXBUILD) >/dev/null 2>&1; echo $$?), 1)
$(error The '$(SPHINXBUILD)' command was not found. Make sure you have Sphinx installed, then set the SPHINXBUILD environment variable to point to the full path of the '$(SPHINXBUILD)' executable. Alternatively you can add the directory with the executable to your PATH. If you don't have Sphinx installed, grab it from http://sphinx-doc.org/)
endif

# Internal variables.
PAPEROPT_a4     = -D latex_paper_size=a4
PAPEROPT_letter = -D latex_paper_size=letter
CONFLOC         = -c build/
VEROPTS         = -D version=${VERSION} -D release=${VERSION}
ALLSPHINXOPTS   = -d $(BUILDDIR)/doctrees $(PAPEROPT_$(PAPER)) $(SPHINXOPTS) $(CONFLOC) $(VEROPTS) source
# the i18n builder cannot share the environment and doctrees with the others
I18NSPHINXOPTS  = $(PAPEROPT_$(PAPER)) $(SPHINXOPTS) source

.PHONY: help clean config html

help:
	@echo "Please use \`make <target>' where <target> is one of"
	@echo "  html       to make standalone HTML files"

clean:
	rm -rf $(BUILDDIR)/*
	rm -f ${CONFDIR}/replacevars.rst.inc

config:
	mkdir -pv build
	cat python-scripts/conf.py ${OS_CONF} ${TAGFILE} ${FAMILYSETUPFILE} > build/conf.py
	cp sphinx_rtd_theme_ti/patch/layout.html sphinx_rtd_theme_ti/_themes/sphinx_rtd_theme_ti/layout.html

html: 
	$(SPHINXBUILD) -b html $(ALLSPHINXOPTS) $(BUILDDIR)
	@echo
	@echo "Build finished. The HTML pages are in $(BUILDDIR)."
