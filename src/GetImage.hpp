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
        Mat bin;
        Mat reverse;

        img = getImage(s);
        
        cvtColor(img, gray, COLOR_BGR2GRAY);
        adaptiveThreshold(gray, bin, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY, 7, 8);
        bin = ~bin;

        vector<vector<Point>> contours;
        vector<Vec4i> hierarchy;

        findContours(bin, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);

        for(int i = 0; i < contours.size(); ++i) {
            Point min = minPoint(contours.at(i));
            Point max = maxPoint(contours.at(i));

            Rect rect(min, max);

            rectangle(img, rect, Scalar(0, 255, 0), 2, 8);
        }
    }

    // max coordinate
    private: Point minPoint(vector<Point> contours) {

        double minX;
        double minY;

        for(int i = 1; i , contours.size(); ++i) {
            if (minX > contours.at(i).x) {
                minX = contours.at(i).x;
            }
            if (minY > contours.at(i).y) {
                minY = contours.at(i).y;
            }

            return Point(minX, minY);
        }
    }

    private: Point maxPoint(vector<Point> contours) {

        double maxX;
        double maxY;

        for(int i = 1; i < contours.size(); ++i) {
            if(maxX < contours.at(i).x) {
                maxX = contours.at(i).x;
            }
            if(maxY < contours.at(i).y) {
                maxY = contours.at(i).y;
            }
        }

        return Point(maxX, maxY);
    }
};