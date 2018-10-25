#pragma once
/*
Binary version

The binary version contains the files data_batch_1.bin, data_batch_2.bin, ..., data_batch_5.bin, as well as test_batch.bin. 
Each of these files is formatted as follows:

In other words, the first byte is the label of the first image, which is a number in the range 0-9. 
The next 3072 bytes are the values of the pixels of the image. 
The first 1024 bytes are the red channel values, the next 1024 the green, and the final 1024 the blue. 
The values are stored in row-major order, so the first 32 bytes are the red channel values of the first row of the image.

Each file contains 10000 such 3073-byte "rows" of images, although there is nothing delimiting the rows. 
Therefore each file should be exactly 30730000 bytes long.

There is another file, called batches.meta.txt. This is an ASCII file that maps numeric labels in the range 0-9 to meaningful class names. 
It is merely a list of the 10 class names, one per row. The class name on row i corresponds to numeric label i.
*/

// c++ code for reading cifar10 dataset http://eric-yuan.me/cpp-read-cifar10/

#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

#include <iostream>
#include <string>
#include <vector>

using namespace cv;

class cifar10
{
public:
	cifar10();
	~cifar10();
	void ReadBatch(std::string pFileName, std::vector<Mat> &pImg, std::vector<int> &pLabel);
	void ReadBatch(int pIndex);
	
private:

	void PrintResizeImg(Mat* pImg, int pLabel);

	std::string _labelNames[10] = { "airplane",
					"automobile",
					"bird",
					"cat",
					"deer",
					"dog",
					"frog",
					"horse",
					"ship",
					"truck" };
};

