#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>

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

    // trimming th src image
    public: void trimImege(Mat src) {

        int width = src.rows;
        int height = src.cols;

        for (int h = 0; h < height / 100; ++h) {
            for (int w = 0; w < width; ++w) {
                Rect rect = Rect();
            }
        }
    }

    public: void drawCircle() {

    }
};