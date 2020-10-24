#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;

int main() {
    cout << "start" << endl;

    int red, green, blue;

    cv::Mat img = cv::imread("./images/dog.jpg");
    if(img.empty()) return -1;

    cv::namedWindow("title", cv::WINDOW_AUTOSIZE);
    cv::imshow("title", img);
    cv::Scalar(blue, red, green);
    cv::waitKey(0);

    cv::destroyAllWindows();
    cout << "Finnish" << endl;

    return 0;
}