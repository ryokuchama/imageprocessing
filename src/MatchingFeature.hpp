#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/features2d.hpp>

using namespace std;
using namespace cv;

/*
 the class is for matching feature
*/
// TODO: trim an image with contour and make it square
class MatchingFeature {

    // Akaze object(for detect)
    Ptr<AKAZE> akaze;
    // limen value
    const double limen = 0.6;

    // constructor
    public: MatchingFeature() {
        // algorithm for detecting
        akaze = AKAZE::create();
    }

    // detect features and match
    public: Mat detectAndMatch(Mat src, Mat target) {

        // detect and compute keypoints
        vector<KeyPoint> srcKey, targetKey;
        // compute features
        Mat descriptionSrc, descriptionTarget;
        akaze -> detectAndCompute(src, Mat(), srcKey, descriptionSrc);
        akaze -> detectAndCompute(target, Mat(), targetKey, descriptionTarget);

        // matching
        BFMatcher match(NORM_HAMMING);
        vector<vector<DMatch>> knnMatch;
        match.knnMatch(descriptionSrc, descriptionTarget, knnMatch, 2);

        // output matching features on image
        Mat result;
        // show image
        drawMatches(src, srcKey, target, targetKey, knnMatch, result);
        imshow("src", src);
        waitKey(5000);
        imshow("target", target);
        waitKey(5000);
        imshow("result", result);
        waitKey(5000);
        destroyAllWindows();
   
        // distance
        double distanceSrc;
        double distanceTarget;
        // good match
        vector<DMatch> goodMatch;
        // keypoint -> 2D
        vector<Point2f> srcPoint;
        vector<Point2f> targetPoint;

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

        // Homography matrix estimation
        Mat mask;
        Mat homoResult = findHomography(
            srcPoint, targetPoint, mask, RANSAC, 3
        );

        // pick up the point used by RANSAC
        // the point used by RANSAC
        vector<DMatch> inlineMatch;
        for (size_t i = 0; i < mask.rows; ++i) {
            uchar *inliner = mask.ptr<uchar>(i);
            if(inliner[0] == 1) {
                inlineMatch.push_back(goodMatch[i]);
            }
        }

        // show corresponding point
        Mat drawMatch;
        drawMatches(
            src, srcKey, target, targetKey, goodMatch, drawMatch
        );
        imwrite("../images/match_point.jpg", drawMatch);

        // show inliner corresponding point
        Mat inlinerDrawMatch;
        drawMatches(
            src, srcKey, target, targetKey, inlineMatch, inlinerDrawMatch
            );
        imwrite("../images/match_inliner.jpg", inlinerDrawMatch);

        imshow("DrawMatch", drawMatch);
        waitKey(5000);
        imshow("Inliner", inlinerDrawMatch);
        waitKey(5000);
        destroyAllWindows();

        return homoResult;
    }

    // warp perspective
    public: Mat warpPerspect(Mat src, Mat target) {
        // output for warping perspective of src
        Mat warpedSrc;
        // output for warping perspective of target
        Mat warpedTarget;
        Mat homography = detectAndMatch(src, target);
        // warpPerspective
        warpPerspective(target, warpedTarget, homography, Size(src.rows, src.cols));

        return warpedTarget;
    }

    // pick up matched object from target
    public: Mat detectObject(Mat src, Mat target) {
        
        vector<Point2f> srcCorner(4);
        vector<Point2f> targetCorner(4);
        Mat pickedup;
        Mat homography = detectAndMatch(src, target);

        // calculate size of src
        srcCorner[0] = Point2f(.0f, .0f);
        srcCorner[1] = Point2f(static_cast<float>(src.cols), .0f);
        srcCorner[2] = Point2f(static_cast<float>(src.cols), static_cast<float>(src.rows));
        srcCorner[3] = Point2f(.0f, static_cast<float>(src.rows));

        // object detection
        perspectiveTransform(srcCorner, targetCorner, homography);

        imshow("src", src);
        waitKey(5000);
        imshow("target", targetCorner);
        waitKey(5000);
        destroyAllWindows();
    }
};