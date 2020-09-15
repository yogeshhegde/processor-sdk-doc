# Device Family is AM335X = AM335X family
fam_name = 'AM335X'

# Project name and HTML title
sdk_product = 'null' #todo: remove after the new structure is used for all device families
project = u'Processor SDK RTOS for AM335X'
html_title = 'Processor SDK RTOS for AM335X Documentation'

# The master toctree document.
master_doc = 'devices/AM335X/rtos/index'

# List of patterns, relative to source directory, that match files and
# directories to ignore when looking for source files.
exclude_patterns = ['linux', 'android', 'rtos/index.rst', 'devices/AM335X/linux', 'devices/AM64X']

# OS for the build. Sphinx uses source/{sdk_os} when looking for doc inputs
sdk_os = 'rtos'
