Processor SDK Documentation in Sphinx
=====================================

## Instructions to build the project on Ubuntu

### Install tools on Ubuntu

    $ sudo apt-get install python-sphinx

OR use the following command in a python virtual environment for a known working
config as of 2023/09/05:

    # python3 -m pip install -r requirements.txt

OR you can use a docker container like the following:
    - [psdk-doc-docker](https://github.com/StaticRocket/psdk-doc-docker/pkgs/container/psdk-doc-docker)

### Clone the Git Repo

    $ git clone ssh://git@bitbucket.itg.ti.com/processor-sdk/processor-sdk-doc.git

### Install the theme files from swtoolsdev

Update submodule:

    $ cd processor-sdk-doc
    $ git submodule init
    $ git submodule update

### Build on Ubuntu

#### Build linux documentatin

    $ make clean DEVFAMILY=<FAMILY> OS=linux
    $ make config DEVFAMILY=<FAMILY> OS=linux
    $ make DEVFAMILY=<FAMILY> OS=linux

#### Build rtos documentation

    $ make clean DEVFAMILY=<FAMILY> OS=rtos
    $ make config DEVFAMILY=<FAMILY> OS=rtos
    $ make DEVFAMILY=<FAMILY> OS=rtos

#### Build android (available for J721E and GEN):

    $ make clean DEVFAMILY=<FAMILY> OS=android
    $ make config DEVFAMILY=<FAMILY> OS=android
    $ make DEVFAMILY=<FAMILY> OS=android

### Build am64x documentation

    $ make config DEVFAMILY=AM64X
    $ make DEVFAMILY=AM64X


**Note**: that DEVFAMILY represents the Device Family.
      Possible values for <FAMILY> are

* "AM335X" (representing AM335X family)
* "AM437X" (representing AM437X family)
* "AM57X" (representing AM57X family)
* "AM64X" (representing AM64X family)
* "AM62X" (representing AM62X family)
* "AM62AX" (representing AM62AX family)
* "AM62PX" (representing AM62PX family)
* "AM65X" (representing AM65X family)
* "DRA821A" (representing DRA821A)
* "J721E" (representing Jacinto 7 ES)
* "J7200" (representing Jacinto 7 VCL)
* "J721S2" (representing Jacinto 7 AEP)
* "J784S4" (representing Jacinto 7 AHP)
* "GEN" (representing General family not listed above)
* "CORESDK" (representing CORESDK)

**Note**: Please use script `bin/check-warn.sh` to check for new build warnings
          and fix them before submitting pull-requests.

### HTML Page Output

Open the index page in a web browser

**AM64X**:

    ./build/processor-sdk-AM64X/esd/docs/[version]/index.html

**GEN family** (TODO: to be migrated to the new structure):

    linux:   ./build/processor-sdk-linux/esd/docs/[version]/index.html
    rtos:    ./build/processor-sdk-rtos/esd/docs/[version]/index.html
    android: ./build/processor-sdk-android/esd/docs/[version]/index.html

**Others**:

    linux: ./build/processor-sdk-linux-<FAMILY>/esd/docs/[version]/index.html
    rtos:  ./build/processor-sdk-rtos-<FAMILY>/esd/docs/[version]/index.html
