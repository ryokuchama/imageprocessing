#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;

int main() {
    // ファイルパス
    std::string filepath = "./movies/Cosmos.mp4";
    // 動画ファイル取り込みオブジェクト
    cv::VideoCapture video;

    //動画ファイルを開く
    video.open(filepath);
    if (video.isOpened() == false) {
        return -1;
    }

    cv::Mat frame;
    double fps = video.get(cv::CAP_PROP_FPS);

    int width = video.get(cv::CAP_PROP_FRAME_WIDTH);
    int height = video.get(cv::CAP_PROP_FRAME_HEIGHT);

    int fourcc = cv::VideoWriter::fourcc('X', 'V', 'I', 'D');
    cv::VideoWriter write("./result/result.avi", fourcc, fps, cv::Size(width, height), 0);

    while(video.read(frame)){
        
    }

    return 0;
}
