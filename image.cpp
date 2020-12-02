#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include "CreateHistgram.cpp"

using namespace std;
using namespace cv;

int main() {
    Mat img = imread("./images/dog.jpg", 0);
    Mat channels[3];
    Mat img_equalized;

    if (img.empty()) return -1;

    split(img, channels);

    equalizeHist(img, img_equalized);

    Mat histgram = CreatingHistgram(channels);

}