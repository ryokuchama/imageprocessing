#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include "CreateHistgram.cpp"

using namespace std;
using namespace cv;

int main() {
    Mat img = imread("./images/dog.jpg", 0);
    Mat channels[3];
    Mat bin_img;

    if (img.empty()) return -1;

    split(img, channels);

    threshold(img, bin_img, 0, 255, THRESH_OTSU);

    Mat histgram = CreatingHistgram(channels);

    return 0;
}