import os

# write_replacevars
# -----------------
# Description:  Writes replacement variable array to source/${OS}/replacevars.rst.inc
#
# Parameters: app          - Application calling this Python function
#             operating_os - Operating System for the SDK (i.e. source/{op_os} for the
#                            documentation source
#             replacevars  - Input hash table of replacevars that will be converted into
#                            "replace" directives in the replacevars.rst.inc file

def write_replacevars(app, operating_os, replacevars):
    replacevarstext = []
    replacevarsfile="source" + "/" + operating_os + "/" + "replacevars.rst.inc"
    with open(replacevarsfile, 'w') as f:
        for key in replacevars:
            nextline=".. |" + key + "| replace:: " + replacevars[key]
            replacevarstext.append(nextline)
            #print(replacevarstext)
    text=''
    for key in replacevars:
        text+=".. |" + key + "| replace:: " + replacevars[key] + "\n"
    file=open(replacevarsfile, 'w')
    file.write(text)
    file.close()
