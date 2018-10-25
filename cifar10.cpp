#include "pch.h"
#include "cifar10.h"

#include <fstream>

cifar10::cifar10()
{
	
}


cifar10::~cifar10()
{
}

void cifar10::ReadBatch(std::string pFileName, std::vector<Mat>& pImg, std::vector<int>& pLabel)
{
	std::ifstream file(pFileName, std::ios::binary);
	if (file.is_open())
	{
		int number_of_images = 10000;
		int n_rows = 32;
		int n_cols = 32;
		for (int i = 0; i < number_of_images; ++i)
		{
			unsigned char tplabel = 0;
			file.read((char*)&tplabel, sizeof(tplabel));
			std::vector<Mat> channels;
			Mat fin_img = Mat::zeros(n_rows, n_cols, CV_8UC3);
			for (int ch = 0; ch < 3; ++ch) {
				Mat tp = Mat::zeros(n_rows, n_cols, CV_8UC1);
				for (int r = 0; r < n_rows; ++r) {
					for (int c = 0; c < n_cols; ++c) {
						unsigned char temp = 0;
						file.read((char*)&temp, sizeof(temp));
						tp.at<uchar>(r, c) = (int)temp;
					}
				}
				channels.push_back(tp);
			}
			merge(channels, fin_img);
			pImg.push_back(fin_img);
			pLabel.push_back((int)tplabel);
		}
	}
}

void cifar10::ReadBatch(int pIndex)
{
	std::string path = "../cifar-10-batches-bin/data_batch_";
	
	switch (pIndex)
	{
		case 1:
		{
			path += "1.bin";

			std::vector<Mat> img;
			std::vector<int> label; // change to byte
			ReadBatch(path, img, label);

			for (int i = 0; i < img.size(); i++) {
				imshow("cifar10-32x32", img[i]);
				PrintResizeImg(&img[i], label[i]);
			}

			break;
		}
		case 2:
		{
			path += "2.bin";
			break;
		}
		case 3:
		{
			path += "3.bin";
			break;
		}
		case 4:
		{
			path += "4.bin";
			break;
		}
		case 5:
		{
			path += "5.bin";
			break;
		}
		default:
			std::cout << "Batch " << pIndex << " does not exist" << std::endl;
			break;
	}
		
}

void cifar10::PrintResizeImg(Mat * pImg, int pLabel)
{
	Mat imgResized;
	resize(*pImg, imgResized, Size(227, 227));
	imshow("cifar10-227x227", imgResized);
	std::cout << _labelNames[pLabel] << std::endl;
	waitKey(10);
}


