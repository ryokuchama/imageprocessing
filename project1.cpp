#include <opencv4/opencv2/opencv.hpp>

int main() {
    cv::Mat img
    img = imread("imageprocessing/dog.png");

    cv::imshow("title", img);
    cv::waitkey(0);

    return 0;
}