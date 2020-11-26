#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;

int main() {
    cout << "start" << endl;

    cv::Mat img;
    cv::Mat channels[3];

    img = cv::imread("../images/dog.jpg");
    if(img.empty()) return -1;
    cv::namedWindow("dog", cv::WINDOW_AUTOSIZE);

    cv::imshow("dog", img);

    split(img, channels);

    cv::imshow("B", channels[0]);
    cv::imshow("G", channels[1]);
    cv::imshow("R", channels[2]);

    // 引数の値に応じてキーボードの入力を受け付ける(単位はミリ秒)
    cv::waitKey(0);

    // ウィンドウ消去
    cv::destroyAllWindows();

    cout << "finish" << endl;

    return 0;
}

cv::Mat CreatingHistgram(cv::Mat channels[3]){

    // 変数
    cv::Mat img_hist;
    cv::Mat R, G, B;
    int hist_size = 256;
    float range[] = {0, 256};
    const float* hist_range = range;

    // 画素数
    cv::calcHist(
        &channels[0], 1, 0, cv::Mat(), R, 1, &hist_size, &hist_range);
    cv::calcHist(
        &channels[1], 1, 0, cv::Mat(), G, 1, &hist_size, &hist_range);
    cv::calcHist(
        &channels[2], 1, 0, cv::Mat(), B, 1, &hist_size, &hist_range);

    // 正規化(画像の輝度を統一)
    //normalize(入力配列、出力配列、範囲の下限、上限、正規化種類、出力配列の型、オプションマスク)
    cv::normalize(R, R, 0.0, 1.0, cv::NORM_MINMAX, -1, cv::Mat());
    cv::normalize(G, G, 0.0, 1.0, cv::NORM_MINMAX, -1, cv::Mat());
    cv::normalize(B, B, 0.0, 1.0, cv::NORM_MINMAX, -1, cv::Mat());
}