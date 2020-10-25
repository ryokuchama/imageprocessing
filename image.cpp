#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;

int main() {
    cout << "start" << endl;

    int red, green, blue;

    cv::Mat img = cv::imread("./images/dog.jpg");
    if(img.empty()) return -1;

    cv::namedWindow("dog", cv::WINDOW_AUTOSIZE);
    cv::imshow("dog", img);
    // サイズ
    int width = img.rows;
    int height = img.cols;
    cout << width << height << endl;

    // 引数の値に応じてキーボードの入力を受け付ける(単位はミリ秒)
    cv::waitKey(0);

    // ウィンドウ消去
    cv::destroyAllWindows();

    // 画像出力
    cv::imwrite("./result/result.jpg", img);
    cout << "Finnish" << endl;

    return 0;
}