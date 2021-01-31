#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <errno.h>

using namespace std;
using namespace cv;

// the class for read image as glay scale
class GetImage {

    int err; // error handling

    // minimum coordinate
    public: void contours(String s) {

        Mat img;
        Mat gray;
        Mat equalized;
        Mat bin;
        Mat thres;

        img = imread(s, 1);

        if (img.empty()) {
            err = 0;
            err = errno;
            printf("Error: %s\n", strerror(err));
            }

        cvtColor(img, gray, COLOR_BGR2GRAY);
        equalizeHist(gray, equalized);
        threshold(gray, thres, 0, 255, THRESH_OTSU);
        adaptiveThreshold(equalized, bin, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY, 7, 8);

        bitwise_not(bin, bin);
        bitwise_not(thres, thres);
        imwrite("./result/adaptive.jpg", bin);
        imwrite("./result/thres.jpg", thres);

        vector<vector<Point>> contours;
        vector<Vec4i> hierarchy;

        findContours(bin, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);

        int maxLevel = 0;
        Mat drawed;
        
        for (int i = 0; i < contours.size(); ++i) {
            double area = contourArea(contours[i], false);

            if (area > 500) {
                vector<Point> approx;
                approxPolyDP(Mat(contours[i]), approx, 0.01 * arcLength(contours[i], true), true);

                if (approx.size() == 4) {
                    drawContours(img, approx, i, Scalar(255, 0, 0, 255), 3, LINE_AA, hierarchy, maxLevel);
                }               
            }
        }

        imwrite("./result/img.png", img);
        waitKey(3000);
        destroyAllWindows();

        Point2f src[4];
        Point2f dst[4];
        Mat warped;

        Mat matrix = getPerspectiveTransform(src, dst);
        warpPerspective(img, warped, matrix, img.size(), INTER_LINEAR);

        imshow("warped", warped);
        waitKey(3000);
        destroyAllWindows();
    }
};