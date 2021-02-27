#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

/*
* the class for find differences
*/
class FindDifferences {

    MatchingFeature mFeature = MatchingFeature();
    // trimmed image
    Mat trimmedSrc;

    // constructor
    public: FindDifferences() {
        
    }

    public: void findDifferences(Mat src, Mat target) {
        
        Mat srcChannels[3];
        Mat targetChannels[3];
        Mat red, green, blue;

        split(src, srcChannels);
        split(target, targetChannels);
        
        absdiff(srcChannels[0], targetChannels[0], red);
        absdiff(srcChannels[1], targetChannels[1], green);
        absdiff(srcChannels[2], targetChannels[2], blue);

        medianBlur(red, red, 5);
        medianBlur(green, green, 5);
        medianBlur(blue, blue, 5);

        Mat wiseMat;
        bitwise_or(red, green, wiseMat);
        bitwise_or(wiseMat, blue, wiseMat);
    }

    // trimming the src image
    public: void trimImage(Mat src, Mat target) {

        int width = src.rows;
        int height = src.cols;

        for (int h = 0; h < height; h+=100) {
            for (int w = 0; w < width; w+=100) {
                Rect rect = Rect(h, w, h + 100, w + 100);
                Mat trimmed(src, rect);

                // detect and crop the target
                Mat cropped = mFeature.detectObject(trimmed, target);
                findDifferences(trimmed, cropped);
            }
        }
    }

    public: void drawCircle() {

    }
};