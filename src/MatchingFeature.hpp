#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/features2d.hpp>

using namespace std;
using namespace cv;

/*
 the class is for matching feature
*/
class MatchingFeature {

    // Akaze object(for detect)
    Ptr<AKAZE> akaze;
    // keypoint
    vector<KeyPoint> srcKey, targetKey;
    // matching
    vector<vector<DMatch>> knnMatch;
    // compute features
    Mat descriptionSrc, descriptionTarget;
    // output features on image
    Mat dstSrc, dstTarget;
    // output matching features on image
    Mat result;

    // limen value
    const double limen = 0.6;
    // ggod match
    vector<DMatch> goodMatch;
    // keypoint -> 2D
    vector<Point2f> srcPoint;
    vector<Point2f> targetPoint;
    // distance
    double distanceSrc;
    double distanceTarget;

    // Homography matrix estimation
    Mat mask;
    // output for Homography matrix estimation
    Mat homoResult;
    // the point used by RANSAC
    vector<DMatch> inlineMatch;
    // output for corresponding point
    Mat drawMatch;
    // output for inliner corresponding point
    Mat inlinerDrawMatch;

    // output for warping perspective of src
    Mat warpedSrc;
    // output for warping perspective of target
    Mat warpedTarget;

    // constructor
    public: MatchingFeature() {
        // algorithm for detecting
        akaze = AKAZE::create();
    }

    // detect features and match
    public: Mat detectAndMatch(Mat src, Mat target) {

        // detect and compute keypoints
        akaze -> detectAndCompute(src, Mat(), srcKey, descriptionSrc);
        akaze -> detectAndCompute(target, Mat(), targetKey, descriptionTarget);

        // matching
        BFMatcher match(NORM_HAMMING);
        match.knnMatch(descriptionSrc, descriptionTarget, knnMatch, 2);

        // show image
        drawMatches(src, srcKey, target, targetKey, knnMatch, result);
        imshow("src", src);
        imshow("target", target);
        imshow("result", result);
        waitKey(10000);

        destroyAllWindows();
    
        for (size_t i = 0; i < knnMatch.size(); ++i) {
            distanceSrc = knnMatch[i][0].distance;
            distanceTarget = knnMatch[i][1].distance;

            // detect the point that is far from the second one.
            if (distanceSrc <= distanceTarget * limen) {
                goodMatch.push_back(knnMatch[i][0]);
                srcPoint.push_back(srcKey[knnMatch[i][0].queryIdx].pt);
                targetPoint.push_back(targetKey[knnMatch[i][0].trainIdx].pt);
            }
        }

        //　homography matrix
        homoResult = findHomography(
            srcPoint, targetPoint, mask, RANSAC, 3
        );

        // pick up the point used by RANSAC
        for (size_t i = 0; i < mask.rows; ++i) {
            uchar *inliner = mask.ptr<uchar>(i);
            if(inliner[0] == 1) {
                inlineMatch.push_back(goodMatch[i]);
            }
        }

        // show corresponding point
        drawMatches(
            src, srcKey, target, targetKey, goodMatch, drawMatch
        );
        imwrite("../images/match_point.jpg", drawMatch);

        // show inliner corresponding point
        drawMatches(
            src, srcKey, target, targetKey, inlineMatch, inlinerDrawMatch
            );
        imwrite("../images/match_inliner.jpg", inlinerDrawMatch);

        imshow("DrawMatch", drawMatch);
        imshow("Inliner", inlinerDrawMatch);
        waitKey(5000);
        destroyAllWindows();

        // warpPerspective
    }
};