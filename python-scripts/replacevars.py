import os

# write_replacevars
# -----------------
# Description:  Writes replacement variable array to source/${OS}/replacevars.rst.inc
#
# Parameters: app          - Application calling this Python function
#             replacevars  - Input hash table of replacevars that will be converted into
#                            "replace" directives in the replacevars.rst.inc file

def write_replacevars(app, replacevars):
    replacevarsfile= os.environ.get('ROOTDIR') + "/source/" + "_replacevars.rst"
    replacevarstext = ["\n"]
    for key, val in replacevars.items():
        replacevarstext.append(f".. |{key}| replace:: {val}\n")
    with open(replacevarsfile, 'w', encoding='utf-8') as vars_file:
        replacevarstext.append("\n")
        vars_file.write("\n".join(replacevarstext))
