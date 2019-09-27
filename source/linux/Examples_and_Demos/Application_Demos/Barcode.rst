.. http://processors.wiki.ti.com/index.php/Processor_SDK_Barcode_Reader

Barcode Reader
==============

.. rubric:: Introduction
   :name: introduction-barcode

Detecting 1D and 2D barcodes on an image, and decoding those barcodes
are important use cases for the Machine-Vision. Processor SDK Linux has
integrated the following open source components, and examples to
demonstrate both of these features.

-  Barcode detection: OpenCV
-  Barcode Decoder/Reader: Zbar Library

OpenCV includes python wrapper to allow quick and easy prototyping. It
also includes support for OpenCL offload on devices with C66 DSP core
(currently OpenCV T-API cannot be used with python wrapper).

| 

.. rubric:: Zbar Barcode Decoder/Reader
   :name: zbar-barcode-decoderreader

`Recipes for zbar barcode
reader <http://arago-project.org/git/projects/?p=meta-processor-sdk.git;a=commit;h=b2feff4cb0c2f0fbaac44e7201784df049cad259>`__
have been added to build the zbar library and test binary. Zbar is
standalone library, which does not depend on OpenCV. Current release is
not accelerated via OpenCL dispatch (obvious candidates are
zbar\_scan\_y() and calc\_tresh() functions consuming >50% of CPU
resources).

Command to run zbar test binary:

::

    barcode_zbar [barcode_image_name]

| 

.. rubric:: Barcode Region Of Interest (ROI) Detection with OpenCV and
   Python
   :name: barcode-region-of-interest-roi-detection-with-opencv-and-python

`Detecting Barcodes in Images using Python and
OpenCV <http://www.pyimagesearch.com/2014/11/24/detecting-barcodes-images-python-opencv/>`__
provides python scripts which run with OpenCV 2.4.x. For use with
Process SDK Linux which has OpenCV 3.1, modifications have been made to
the original python scripts so that they can run with OpenCV 3.1. Below
please find the modified python scripts detect\_barcode.py.

::

    # import the necessary packages
    import numpy as np
    import argparse
    import cv2

    # construct the argument parse and parse the arguments
    ap = argparse.ArgumentParser()
    ap.add_argument("-i", "--image", required = True, help = "path to the image file")
    args = vars(ap.parse_args())

    # load the image and convert it to grayscale
    image = cv2.imread(args["image"])
    gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)

    # compute the Scharr gradient magnitude representation of the images
    # in both the x and y direction
    gradX = cv2.Sobel(gray, ddepth = cv2.CV_32F, dx = 1, dy = 0, ksize = -1)
    gradY = cv2.Sobel(gray, ddepth = cv2.CV_32F, dx = 0, dy = 1, ksize = -1)

    # subtract the y-gradient from the x-gradient
    gradient = cv2.subtract(gradX, gradY)
    gradient = cv2.convertScaleAbs(gradient)

    # blur and threshold the image
    blurred = cv2.blur(gradient, (9, 9))
    (_, thresh) = cv2.threshold(blurred, 225, 255, cv2.THRESH_BINARY)

    # construct a closing kernel and apply it to the thresholded image
    kernel = cv2.getStructuringElement(cv2.MORPH_RECT, (21, 7))
    closed = cv2.morphologyEx(thresh, cv2.MORPH_CLOSE, kernel)

    # perform a series of erosions and dilations
    closed = cv2.erode(closed, None, iterations = 4)
    closed = cv2.dilate(closed, None, iterations = 4)

    # find the contours in the thresholded image, then sort the contours
    # by their area, keeping only the largest one
    (_, cnts, _) = cv2.findContours(closed.copy(), cv2.RETR_EXTERNAL,cv2.CHAIN_APPROX_SIMPLE)
    c = sorted(cnts, key = cv2.contourArea, reverse = True)[0]

    # compute the rotated bounding box of the largest contour
    rect = cv2.minAreaRect(c)
    box = np.int0(cv2.boxPoints(rect))

    # draw a bounding box arounded the detected barcode and display the
    # image
    cv2.drawContours(image, [box], -1, (0, 255, 0), 3)
    cv2.imshow("Image", image)
    cv2.waitKey(0)

| 
| Command to run detect\_barcode.py. Before running the python scripts,
  ensure that matrxi GUI has been stopped and weston is up running. With
  successful detection, the barcode image is displayed with a green
  bounding box on the barcode detected.

::

    python detect_barcode.py --image [barcode_image_name]

| 

.. rubric:: Barcode Region Of Interest (ROI) Detection with OpenCV and
   CPP implementation
   :name: barcode-region-of-interest-roi-detection-with-opencv-and-cpp-implementation

Current version of OpenCV (3.1) Python wrapper does not support T-API
which is needed for OpenCL dispatch. So Processor SDK Linux is including
the same algorithm implemented in CPP
(http://git.ti.com/apps/barcode-roi-detection), which can be executed on
ARM platform only, or with DSP acceleration. CPP example includes more
options for various types of input and output, and run-time control of
OpenCL dispatch.

This example allows multiple command line options:

-  Using static image (JPG or PNG) as input
-  Live display or static image output (JPG or PNG)
-  Use OpenCL offload or not

Target filesystem includes detect\_barcode in "/usr/bin", and test
vector in "/usr/share/ti/image" folder. Again, after successful
detection image with barcode in green bounding box is displayed or
written to output file. Below are various use cases of detect\_barcode.

-  Static image input, no opencl dispatch, live display:
   *detect\_barcode sample\_barcode.jpg 0 1*
-  Static image input, opencl ON, live display: *detect\_barcode
   sample\_barcode.jpg 1 1*
-  Static image input, opencl ON, file output: *detect\_barcode
   sample\_barcode.jpg 1 image\_det.png*

Majority of workload is in following lines:

::

         ocl::setUseOpenCL(ocl_acc_flag);  /* Turn ON or OFF OpenCL dispatch  */

         cvtColor(im_rgb,im_gray,CV_RGB2GRAY);
         im_gray.copyTo(img_gray);

         Sobel( img_gray, gradX, CV_16S, 1, 0, -1, 1, 0, BORDER_DEFAULT ); /* Input is 8-bit unsigned, output is 16-bit signed */
         Sobel( img_gray, gradY, CV_16S, 0, 1, -1, 1, 0, BORDER_DEFAULT ); /* Input is 8-bit unsigned, output is 16-bit signed */
         subtract(gradX, gradY, gradient);
         convertScaleAbs(gradient, abs_gradient);

         // blur and threshold the image
         //GaussianBlur( abs_gradient, blurredImg, Size(7,7), 0, 0, BORDER_DEFAULT );
         GaussianBlur( abs_gradient, blurredImg, Size(3,3), 0, 0, BORDER_DEFAULT ); /* 3x3 kernel */
         threshold(blurredImg, threshImg, 225, 255, THRESH_BINARY);

         Mat elementKernel = getStructuringElement( MORPH_RECT, Size( 2*10+1, 2*3+1 ), Point(10, 3));
         ocl::setUseOpenCL(false); /* Turn OFF OpenCL dispatch */
         morphologyEx( threshImg, closedImg, MORPH_CLOSE, elementKernel );

         ocl::setUseOpenCL(ocl_acc_flag);   /* Turn ON or OFF OpenCL dispatch  */
         erode(closedImg, img_final, UMat(), Point(-1, -1), 4); /* erode, 4 iterations */
         dilate(img_final, img_ocl, UMat(), Point(-1, -1), 4);  /* dilate, 4 iteration */
         ocl::setUseOpenCL(false); /* Turn OFF OpenCL dispatch */

Not all OpenCV kernels can be dispatched to DSP via OpenCL. Please refer
to
`OpenCV#OpenCL\_C\_C66\_DSP\_kernels <Foundational_Components_OpenCV.html#opencl-c-c66-dsp-kernels>`__
for the list of kernels which are currently DSP accelerated.

In order to use OpenCL dispatch, it is necessary to:

-  Enable OpenCL use (by setting environment variables, and invoking
   ocl::setUseOpenCL(ocl\_acc\_flag))
-  Use T-API: e.g. replace Mat types with UMat types

