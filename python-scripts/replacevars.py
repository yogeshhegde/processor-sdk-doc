import os

# write_replacevars
# -----------------
# Description:  Writes replacement variable array to source/${OS}/replacevars.rst.inc
#
# Parameters: app          - Application calling this Python function
#             replacevars  - Input hash table of replacevars that will be converted into
#                            "replace" directives in the replacevars.rst.inc file

def write_replacevars(app, replacevars):
    replacevarstext = []
    replacevarsfile= os.environ.get('ROOTDIR') + "/source/" + "replacevars.rst.inc"
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
