#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>

using namespace std;
using namespace cv;

// the class for read image as glay scale
class GetImage {

    // minimum coordinate
    public: void contours(Mat &img) {

        Mat gray;
        Mat equalized;

        Mat input(img.rows, img.cols, img.type());
        cvtColor(img, gray, COLOR_BGR2GRAY);
        equalizeHist(gray, equalized);
        adaptiveThreshold(equalized, input, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY, 7, 8);

        imwrite("../result/threshold.jpg", input);
        vector<vector<Point>> contours;
        vector<Vec4i> hierarchy;

        findContours(input, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);

        int maxLevel = 0;
        Mat out;
        
        for (int i = 0; i < contours.size(); ++i) {
            drawContours(img, contours, i, Scalar(255, 0, 0, 255), 3, LINE_AA, hierarchy, maxLevel);
        }

        imwrite("../images/img.jpg", img);
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