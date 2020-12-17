#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

// the class for read image as glay scale
class GetImage {
 
    public: Mat getImage(string s) {

        Mat img;
        img = imread(s, 0);

        return img;
    };
};