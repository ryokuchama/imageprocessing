#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include "GetImage.hpp"
#include "MatchingFeature.hpp"

using namespace std;
using namespace cv;

int main() {

    String src_path;
    String target_path;
    GetImage getImage;
    MatchingFeature matchingFeature;

    // source image
    Mat src = getImage.getImage(src_path);
    // target image
    Mat target = getImage.getImage(target_path);

    // detect feature point and draw
    

    return 0;
}