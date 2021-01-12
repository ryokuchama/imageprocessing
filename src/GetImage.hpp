#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>

using namespace std;
using namespace cv;

// the class for read image as glay scale
class GetImage {

    const int square = 10000;
 
    public: Mat getImage(string s) {

        Mat img;
        Mat equalized;

        img = imread(s);
        equalizeHist(img, equalized);

        return img;
    };

    // minimum coordinate
    public: Mat contours(string s) {

        Mat img;
        Mat gray;

        img = getImage(s);

        Mat input(img.rows, img.cols, img.type());
        cvtColor(img, gray, COLOR_BGR2GRAY);
        adaptiveThreshold(gray, input, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY, 7, 8);

        vector<vector<Point>> contours;
        vector<Vec4i> hierarchy;

        findContours(input, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);

        int maxLevel = 0;
        Mat out;
        
        // for (int i = 0; i < contours.size(); ++i) {
        //     double area = contourArea(contours[i], false);

        //     if (area > square) {
        //         vector<Point> approx;
        //         approxPolyDP(
        //             Mat(contours[i]), approx, 0.01 * arcLength(contours[i], true), true
        //             );
        //         if (approx.size() == 4) {
        //             drawContours(img, out, i, Scalar(255, 0, 0, 255), 3, LINE_AA, hierarchy, maxLevel);
        //         }
        //     }
        // }
    }

    public: Mat warpPerspect(Mat img) {
        Point2f src[4];
        Point2f dst[4];
        Mat warped;

        Mat matrix = getPerspectiveTransform(src, dst);
        warpPerspective(img, warped, matrix, img.size(), INTER_LINEAR);

        return warped;
    }
};