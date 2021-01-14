# Week1-project
## IMAGE ROTATION
This project implements Image Processing in C++ using Open CV.
Rotating images by a given angle is a common image processing task. Although it seems little bit complicated, OpenCV provides some built-in functions making it easy to do it. 

#### PROGRAMMING LANGUAGE USED: C++
#### PLATFORM USED: MICROSOFT VISUAL STUDIO 2019
#### TECHNOLOGY USED: OPEN SOURCE COMPUTER VISION (OPEN CV LIBRARY)
#### MODULES:
* Mat imread(const String& filename, int flags = IMREAD_COLOR) - This function loads an image from the specified file and return is as a Mat object. If the function cannot read   the file, it will return an empty Mat object.
* void namedWindow(windowName,int flag) - This function creates a window which can be used to place images and track bars. If a window already exists with the given name, this   function does nothing.
* void imshow(windowName, image) - This function shows the image in a window specified by winname. If the window is created with WINDOW_AUTOSIZE flag, image   will be displayed   in its original size. Otherwise image may be scaled to the size of the window. If the window has not been created by calling to namedWindow() function, this   function will     create a window with the WINDOW_AUTOSIZE flag.
* Mat getRotationMatrix2D(Point(iImageWidth, iImageHieght), (angle - 180), 1) - This function returns 2x3 affine transformation matrix for the 2D rotation.
* void warpAffine( img, imgRotated, matRotation, img.size() )- This OpenCV function applies affine transformation to an image.
* waitKey(0) - function waits for a key press forever. When any key is pressed, this function returns the ASCII value of the key and your program will continue.
