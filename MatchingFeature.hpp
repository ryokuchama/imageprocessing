#include <opencv2/opencv.hpp>
#include <opencv2/features2d.hpp>

using namespace std;
using namespace cv;

/*
 特徴点マッチングを行うクラス
 アルゴリズムはA-KAZEを使用する
*/
class MatchingFeature {

    // AKAZEオブジェクト
    Ptr<AKAZE> akaze;
    // 特徴点情報を格納する変数
    vector<KeyPoint> keyAkaze;
    // 出力
    Mat dstAkaze;

    // コンストラクタ
    MatchingFeature() {
        akaze = AKAZE::create();
    }

    // 特徴点を検出して画像上に描画
    public: Mat detect(Mat img) {
        // キーポイントの検出
        akaze->detect(img, keyAkaze);

        // 画像上にキーポイントの場所を描画
        drawKeypoints(
            img, keyAkaze, dstAkaze, Scalar::all(-1), DrawMatchesFlags::DRAW_RICH_KEYPOINTS
            );

        return dstAkaze;
    }

    // 特徴点を算出して特徴点をマッチング
    public: Mat matching(Mat img1, Mat img2) {

    }
};