#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include "./src/GetImage.hpp"
#include "./src/MatchingFeature.hpp"
#include "./src/FindDifferences.hpp"

using namespace std;
using namespace cv;

/*
Find the Differences
Corrct Image = src
Comparative Image = target
*/
// TODO: trim an image with contour and make it square
// TODO: equarizeHist
int main() {

    const string src_path = "./images/source.jpg";
    const string target_path = "./images/target.jpg";
    // String src_path;
    // String target_path;
    GetImage getImage = GetImage();
    MatchingFeature matchingFeature = MatchingFeature();
    FindDifferences findDifferences = FindDifferences();

    Mat src;
    Mat target;

    cout << "start" << endl;

    src = imread(src_path, 1);
    
    if (src.empty()) {
        cout << "error at line 34" << endl;
        return -1;
    }

    imshow("src", src);
    waitKey(3000);
    destroyAllWindows();
    // source image
    getImage.contours(src);
    // target image
    // target = getImage.contours(target_path);

    // detect feature point and draw
    

    // Find differences

    return 0;
}

