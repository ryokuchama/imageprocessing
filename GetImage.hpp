#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

// 画像をグレースケールで読み込むクラス
class GetImage {
 
    public: Mat getImage(string s) {

        Mat img;
        img = imread(s, 0);

        return img;
    };
};