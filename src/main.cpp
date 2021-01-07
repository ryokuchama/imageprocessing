#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include "MatchingFeature.hpp"
#include "FindDifferences.hpp"

using namespace std;
using namespace cv;

/*
Find the Differences
Corrct Image = src
Comparative Image = target
*/

int main() {

    const string src_path = "../images/source.jpg";
    const string target_path = "../images/target.jpg";
    // String src_path;
    // String target_path;
    MatchingFeature matchingFeature = MatchingFeature();
    FindDifferences findDifferences = FindDifferences();

    Mat src;
    Mat target;

    // source image
    src = imread(src_path);
    // target image
    target = imread(target_path);

    // detect feature point and draw
    Mat warpedTarget = matchingFeature.warpPerspect(&src, &target);

    // Find differences

    return 0;
}

