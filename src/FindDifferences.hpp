#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include "MatchingFeature.hpp"

using namespace std;
using namespace cv;

class FindDifferences {

    // trimmed image
    Mat trimmedSrc;
    // 

    // constructor
    public: FindDifferences() {

    }

    public: void findDifferences() {

    }

    // trimming the src image
    public: void trimImege(Mat src, Mat target) {

        int width = src.rows;
        int height = src.cols;

        for (int h = 0; h < height; h+=100) {
            for (int w = 0; w < width; w+=100) {
                Rect rect = Rect(h, w, h + 100, w + 100);
                Mat trimmed(src, rect);

                
            }
        }
    }

    public: void drawCircle() {

    }
};