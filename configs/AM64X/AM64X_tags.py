# Device Family name 
fam_name = 'AM64X'

# The master toctree document.
master_doc = 'release_specific/AM64X/index'

# List of patterns, relative to source directory, that match files and
# directories to ignore when looking for source files.

# todo: the current AM64x ToC and sample content .rst files are including files from 'linux', 'common'
# and 'rtos' with the "include" directive, and therefore, those folders can be excluded here.
# When there is need to include 'linux', 'common', and 'rtos' RST files directly in AM64x ToC,
# remove the corresponding folder from the list below.
exclude_patterns = ['android', 'example_code', 'files', 'linux', 'common', 'rtos', 'release_specific/AM335X']

# OS for the build. Sphinx uses source/{sdk_os} when looking for doc inputs
sdk_os = 'null' #todo: remove this after the new release specific structure is used for all device families

project = u'Processor SDK for AM64X'

html_title = 'Processor SDK AM64X Documentation'
