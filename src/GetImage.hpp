#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

// the class for read image as glay scale
class GetImage {
 
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

        findContours(input, contours, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);

        auto maxContour = max_element(
            contours.begin(), contours.end(), [](vector<Point> x, vector<Point> y
            ){
                return contourArea(x) < contourArea(y);
        });

        vector<Point> approx;
        approxPolyDP(
            Mat(contours.begin()), approx, 0.01 * arcLength(contours[i], true), true
            );

    }
};