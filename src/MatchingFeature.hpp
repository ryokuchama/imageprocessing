#include <opencv2/opencv.hpp>
#include <opencv2/features2d.hpp>

using namespace std;
using namespace cv;

/*
 the class is for matching feature
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
    // compute features
    Mat descriptionSrc, descriptionTarget;
    // output features on image
    Mat dstSrc, dstTarget;
    // output matching features on image
    Mat result;
    
    // constructor
    public: MatchingFeature() {
        // algorithm for detecting
        akaze = AKAZE::create();
        // algorithm for matching
        matcher = DescriptorMatcher::create("BruteForce");
    }

    // detect features and match
    public: Mat detectAndMatch(Mat src, Mat target) {
        // detect keypoints
        akaze -> detect(src, srcKey);
        akaze -> detect(target, targetKey);

        // draw features on image
        drawKeypoints(
            src, srcKey, dstSrc, Scalar::all(-1), DrawMatchesFlags::DRAW_RICH_KEYPOINTS
            );
        drawKeypoints(
            target, targetKey, dstTarget, Scalar::all(-1), DrawMatchesFlags::DRAW_RICH_KEYPOINTS
            );

        // compute features
        akaze -> compute(src, srcKey, descriptionSrc);
        akaze -> compute(target, targetKey, descriptionTarget);

        // matching
        matcher -> match(descriptionSrc, descriptionTarget, dMatch);

        // show image
        drawMatches(src, srcKey, target, targetKey, dMatch, result);
        imshow("src", src);
        imshow("target", target);
        imshow("result", result);
        waitKey(10000);

        destroyAllWindows();

        
    }
};