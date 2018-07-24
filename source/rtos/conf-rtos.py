# Processor SDK RTOS documentation build configuration file

# The master toctree document.
master_doc = 'rtos/index'

# General information about the project.
project = u'Processor SDK RTOS'

# List of patterns, relative to source directory, that match files and
# directories to ignore when looking for source files.
exclude_patterns = ['linux', 'android', 'swtoolsdev']

# The name for this set of Sphinx documents.  If None, it defaults to
# "<project> v<release> documentation".
html_title = 'Processor SDK RTOS Documentation'

# Output file base name for HTML help builder.
htmlhelp_basename = 'ProcessorSDKRTOSdoc'

# Grouping the document tree into LaTeX files. List of tuples
# (source start file, target name, title,
#  author, documentclass [howto, manual, or own class]).
latex_documents = [
  (master_doc, 'ProcessorSDKRTOS.tex', u'Processor SDK RTOS Documentation',
   u'Texas Instruments Incorporated', u'manual'),
]

# -- Options for manual page output ---------------------------------------

# One entry per manual page. List of tuples
# (source start file, name, description, authors, manual section).
man_pages = [
    (master_doc, 'ProcessorSDKRTOS', u'Processor SDK RTOS Documentation',
     ['Texas Instruments Incorporated'], 1)
]

# If true, show URL addresses after external links.
#man_show_urls = False


# -- Options for Texinfo output -------------------------------------------

# Grouping the document tree into Texinfo files. List of tuples
# (source start file, target name, title, author,
#  dir menu entry, description, category)
texinfo_documents = [
  (master_doc, 'ProcessorSDKRTOS', u'Processor SDK RTOS Documentation',
   'Texas Instruments Incorporated', 'ProcessorSDKRTOS', 'One line description of project.',
   'Miscellaneous'),
]
