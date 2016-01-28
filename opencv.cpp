#include "opencv2/opencv.hpp"
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;
using namespace std;

int main(int argc, char **argv)
{
	//wektor aby dzia³a³ zapis do png (inaczej b³ad kompilacji)
	vector<int>moja;
	moja.push_back(CV_IMWRITE_PNG_COMPRESSION);
	moja.push_back(3);
	
	//potrzebne dane do Sobel
	int scale = 1;
	int delta = 0;
	int ddepth = CV_16S;

	//wczytanie obrazka
	Mat image;
	image = imread("in.png", 1);

	if (!image.data)
		cout << "error" << endl;

	//konwersja przestrzeni barw na szaroœæ i zapis do grayscale.png
	Mat gray_image;
	cvtColor(image, gray_image, CV_BGR2GRAY);
	imwrite("grayscale.png", gray_image,moja);

	//zastosowanie filtru Gaussa 3x3 i zapis do gauss.png
	Mat gaussian_image;
	GaussianBlur(gray_image, gaussian_image, Size(3, 3), 1.5, 0);
	imwrite("gauss.png", gaussian_image,moja);

	//zastosowanie filtru Sobel i zapis do sobel.png
	Mat sobel_image;
	Mat sobelx;
	Mat sobely;
	Sobel(gaussian_image, sobelx, ddepth, 1, 0, 3, scale, delta, BORDER_DEFAULT);
	convertScaleAbs(sobelx, sobelx);
	Sobel(gaussian_image, sobely, ddepth, 0, 1, 3, scale, delta, BORDER_DEFAULT);
	convertScaleAbs(sobely, sobely);
	addWeighted(sobelx, 0.5, sobely, 0.5, 0, sobel_image);
	imwrite("sobel.png", sobel_image,moja);


	return 0;
}