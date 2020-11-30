#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;

int main(int argc, char *argv[]) {

    cv::Mat img;
    cv::Mat channels[3];

    img = cv::imread(argv[1]);

    if(img.empty()) return -1;

    cv::imshow("image", img);

    split(img, channels);

    cv::Mat histgram = CreatingHistgram(channels);
    cv::imshow("histgram", histgram);

    // 引数の値に応じてキーボードの入力を受け付ける(単位はミリ秒)
    cv::waitKey(0);

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

    // ヒストグラム生成用の画像を準備
    img_hist = cv::Mat(cv::Size(276, 320), CV_8UC3, cv::Scalar(255, 255, 255));

    // 背景の描画
    for(int i = 0; i < 3; i++){
        cv::rectangle(img_hist, cv::Point(10, 10 + 100 * i), 
        cv::Point(265, 100 + 100 * i), cv::Scalar(230, 230, 230), -1);
    }

    // ヒストグラム描画
    for(int i = 0; i < 256; i++){
        // R
        cv::line(img_hist, cv::Point(10 + i, 100),
            cv::Point(10 + i, 100 - (int)(R.at<float>(i) * 80)),
            cv::Scalar(0, 0, 255), 1, 8, 0
        );
        // G
        cv::line(img_hist, cv::Point(10 + i, 200),
            cv::Point(10 + i, 200 - (int)(G.at<float>(i) * 80)),
            cv::Scalar(0, 0, 255), 1, 8, 0
        );
        // B
        cv::line(img_hist, cv::Point(10 + i, 300),
            cv::Point(10 + i, 300 - (int)(B.at<float>(i) * 80)),
            cv::Scalar(0, 0, 255), 1, 8, 0
        );

        // 横軸10づつラインを引く
        if(i % 10) {
            cv::line(img_hist, cv::Point(10 + i, 100), cv::Point(10 + i, 10),
                cv::Scalar(170, 170, 170), 1, 8, 0
            );
            cv::line(img_hist, cv::Point(10 + i, 200), cv::Point(10 + i, 110),
                cv::Scalar(170, 170, 170), 1, 8, 0
            );
            cv::line(img_hist, cv::Point(10 + i, 300), cv::Point(10 + i, 120),
                cv::Scalar(170, 170, 170), 1, 8, 0
            );

        // 横軸50づつラインを引く
        if (i % 50 == 0) {
            cv::line(img_hist, cv::Point(10 + i, 100), cv::Point(10 + i, 10),
                cv::Scalar(50, 50, 50), 1, 8, 0
            );
            cv::line(img_hist, cv::Point(10 + i, 200), cv::Point(10 + i, 110),
                cv::Scalar(50, 50, 50), 1, 8, 0
            );
            cv::line(img_hist, cv::Point(10 + i, 300), cv::Point(10 + i, 120),
                cv::Scalar(50, 50, 50), 1, 8, 0
            );
        }

        }
    }
    return img_hist;
}