#include <opencv2/opencv.hpp>
#include <opencv2/features2d.hpp>

using namespace std;
using namespace cv;

// 特徴点マッチングを行うクラス
class FindFeature {

    // コンストラクタ
    FindFeature(Mat img_1, Mat img_2) {
        Ptr<FeatureDetector> detector = FeatureDetector::create("AKAZE");
    }


};