#include<opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
	Mat image = imread("image.jpeg", IMREAD_UNCHANGED);
	if (image.empty())
	{
		cout << "error !!! no image...";
		return -1;
	}
	cout << "Enter an angle through which you want to rotate the image: " << endl;
	double input_angle;
	cin >> input_angle;
	Point2f center((image.cols - 1) / 2.0, (image.rows - 1) / 2.0);
	Mat rotate = getRotationMatrix2D(center, input_angle, 1.0);
	Rect2f bbox = RotatedRect(Point2f(), image.size(), input_angle).boundingRect2f();
	rotate.at<double>(0, 2) += bbox.width / 2.0 - image.cols / 2.0;
	rotate.at<double>(1, 2) += bbox.height / 2.0 - image.rows / 2.0;
	//show the original image
	string OriginalImage = "Original Image";
	namedWindow(OriginalImage, WINDOW_AUTOSIZE);
	imshow(OriginalImage, image);

	Mat R;
	warpAffine(image, R, rotate, bbox.size());
	imwrite("rotated_image.png", R);
	string windowName = "Rotated Image";
	namedWindow(windowName, WINDOW_NORMAL);
	imshow(windowName, R);
	waitKey(0);
	destroyWindow(windowName);
	return 0;
}

