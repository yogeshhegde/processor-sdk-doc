# Device Family is AM65X = AM65X family
fam_name = 'AM65X'

# Project name and HTML title
sdk_product = 'null' #todo: remove after the new structure is used for all device families
project = u'Processor SDK Linux for AM65X'
html_title = 'Processor SDK Linux for AM65X Documentation'

# The master toctree document.
master_doc = 'devices/AM65X/linux/index'

# List of patterns, relative to source directory, that match files and
# directories to ignore when looking for source files.
exclude_patterns = ['rtos', 'android', 'linux/index.rst', 'devices/AM335X', 'devices/AM437X', 'devices/AM64X', 'devices/J7', 'devices/J7200', 'devices/J721S2', 'devices/J784S4', 'devices/DRA821A', 'devices/AM62X', 'devices/AM62AX']

# OS for the build. Sphinx uses source/{sdk_os} when looking for doc inputs
sdk_os = 'linux'
