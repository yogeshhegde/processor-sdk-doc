#############################################
# Device family build setup
#############################################
import pprint
import replacevars
import sectinc
import interpretvalues

# List of Inclusion TOC files to use
family_tocfiles = [fam_name + '/' + fam_name + '_' + sdk_os + '_toc.txt']
# Family Configuration file to use
family_config_inputfile = fam_name + '/' + fam_name + '_' + sdk_os + '_config.txt'
# Hash table for Replacement Variables
family_replacevars = {}
# Hash table for Configuration Values
family_configvals = {}

# Setup Function does the following:
#     1. Reads all the replacement variables and configuration values in <fam_name>_<sdk_os>_config.txt
#     2. Traverses toctree files to create master list of all possible included .rst files
#     3. Create exclusion list based on the files included in the defined family_tocfiles
#     4. Update exclude_patterns so that these files are excluded from the build
#     5. Write to the Linux folder's replacevars.rst.inc for all the substitution variables

def setup(app):
    app.add_stylesheet("theme_overrides.css")
    # Read the replacement variables and the configuration values
    print("Device Family Build setup started")
    interpretvalues.read_familyvals(app, family_config_inputfile, family_replacevars, family_configvals)
    print("Build setup: Filled Replacement Variables (family_replacevars) and Configuration Values (family_configvals) hash tables")
    print("family_replacevars = ")
    pprint.pprint(family_replacevars)
    print("family_configvals = ")
    pprint.pprint(family_configvals)
    # Determine which sections need to be excluded
    sectinc.create_master_rst_list(app, sdk_os)
    sectinc.fill_docs_to_keep(app, family_tocfiles, 0)
    sectinc.set_excluded_docs(app, exclude_patterns)
    print(fam_name + " exclude_patterns is:")
    print('[')
    for elem in exclude_patterns:
        print(elem)
    print(']')
    # Write to the replacevars.rst.inc file for usage by Sphinx
    replacevars.write_replacevars(app, sdk_os, family_replacevars)
    print("Device Family Build setup completed")
