# Device Family name 
fam_name = 'AM64X'

# The master toctree document.
master_doc = 'release_specific/AM64X/index'

# List of patterns, relative to source directory, that match files and
# directories to ignore when looking for source files.
exclude_patterns = ['android', 'example_code', 'files', 'linux', 'common', 'rtos', 'release_specific/AM335X']

# OS for the build. Sphinx uses source/{sdk_os} when looking for doc inputs
sdk_os = 'null' #todo: remove this after the new release specific structure is used for all device families

project = u'Processor SDK for AM64X'

html_title = 'Processor SDK AM64X Documentation'
