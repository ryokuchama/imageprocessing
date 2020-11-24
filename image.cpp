#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;

int main() {
    cout << "start" << endl;

    cv::Mat img = cv::imread("./images/dog.jpg");
    if(img.empty()) return -1;

    cv::namedWindow("dog", cv::WINDOW_AUTOSIZE);
    cv::Mat img_gray;
    cv::cvtColor(img, img_gray, cv::COLOR_RGB2GRAY);
    
    cv::imshow("dog", img);

    // 引数の値に応じてキーボードの入力を受け付ける(単位はミリ秒)
    cv::waitKey(0);

    // ウィンドウ消去
    cv::destroyAllWindows();

    cout << "finish" << endl;

    return 0;
}