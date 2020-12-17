#include <opencv2/opencv.hpp>
#include <opencv2/features2d.hpp>

using namespace std;
using namespace cv;

/*
 the class is for matching feature
 Akaze algorithm is used
*/
class MatchingFeature {

    // Akaze object(for detect)
    Ptr<AKAZE> akaze;
    // Brute-Force object(for matcher)
    Ptr<DescriptorMatcher> matcher;
    // keypoint
    vector<KeyPoint> srcKey, targetKey;
    // matching
    vector<DMatch> dMatch;
    // output features on image
    Mat dstSrc, dstTarget;
    // output matching features on image
    Mat result;
    
    // constructor
    public: MatchingFeature() {
        akaze = AKAZE::create();
        matcher = DescriptorMatcher::create("BruteForce");
    }

    // detect features and match
    public: Mat detectAndMatch(Mat src, Mat target) {
        // detect keypoints
        akaze->detect(src, srcKey);
        akaze->detect(target, targetKey);

        // draw features on image
        drawKeypoints(
            src, srcKey, dstSrc, Scalar::all(-1), DrawMatchesFlags::DRAW_RICH_KEYPOINTS
            );
        drawKeypoints(
            target, targetKey, dstTarget, Scalar::all(-1), DrawMatchesFlags::DRAW_RICH_KEYPOINTS
            );

        
    }
};