#include <opencv2/opencv.hpp>
#include <opencv2/features2d.hpp>

using namespace std;
using namespace cv;

// 特徴点マッチングを行うクラス
class DetectFeature {

    // AKAZEオブジェクト
    Ptr<AKAZE> akaze;
    // 特徴点情報を格納する変数
    vector<KeyPoint> keyPoint1, keypoint2;

    // コンストラクタ
    DetectFeature(Mat img1, Mat img2) {
        akaze = AKAZE::create();
    }

    

};