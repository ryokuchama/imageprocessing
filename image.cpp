#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

class ImageProcessing {

    int main() {
        Mat img = imread("./images/dog.jpg", 0);
        Mat channels[3];
        Mat result;
        double kernel[3][3];

        Point anchor = Point(-1, 1);
        double delta = 0;
        int ddepth = -1;

        if (img.empty()) return -1;

        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                cin >> kernel[i][j];
            }
        }

        filter2D(
            img, result, ddepth, Mat(3, 3, CV_64F, &kernel), anchor, delta, BORDER_DEFAULT
            );

        imshow("filter2D", result);
        waitKey(0);

        return 0;
    }
};