#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include "GetImage.hpp"

using namespace std;
using namespace cv;

int main() {

    String s1;
    String s2;
    GetImage getImage;
    // 正解画像
    Mat img_1 = getImage.getImage(s1);
    // 比較画像
    Mat img_2 = getImage.getImage(s2);

    return 0;
}