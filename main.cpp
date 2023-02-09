#include <iostream>
#include <vector>
#include "opencv2/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <opencv2/features2d.hpp>
#include <chrono>

int main() {
    // load image
    cv::Mat image = cv::imread("image3.jpg", cv::IMREAD_COLOR);
    cv::imshow("picture1 original", image);
    // detect keypoint from the image
    auto start = std::chrono::steady_clock::now();
    auto detector = cv::SiftFeatureDetector::create(0, 4, 1,
                                                    5);
    std::vector<cv::KeyPoint>keypoints;
    detector->detect(image, keypoints);
    int num_featurepoints = keypoints.size();
    std::cout<<"# of keypoints "<<num_featurepoints<<"\n";
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;
    std::cout << "elapsed time:detection " << elapsed_seconds.count() << "s\n";
    //present the keypoint on image
    cv::Mat image_with_keypoints;
    cv::drawKeypoints(image, keypoints, image_with_keypoints);
    //extract sift descriptor
    auto start2 = std::chrono::steady_clock::now();
    auto extractor = cv::SiftDescriptorExtractor::create();
    cv::Mat descriptors;
    extractor->compute(image, keypoints, descriptors);
    auto end2 = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds2 = end2-start2;
    std::cout << "elapsed time:extraction " << elapsed_seconds2.count() << "s\n";
//    std::FILE *fout;
//    fout = fopen("SiftContrast0.04.csv", "w+");
//
//    for (int i = 0; i < keypoints.size(); i++) {
//        std::fprintf(fout, "%d, %d,%d\n",i, keypoints[i].pt.x, keypoints[i].pt.y,"\n");
//    }
    for (int i = 0; i < keypoints.size(); i++) {
        std::cout<<i<<" "<<keypoints[i].pt<<"\n";
    }

    //for visualization
//    cv::namedWindow("image with keypoints", cv::WINDOW_AUTOSIZE);
//    cv::imshow("image with keypoints", image_with_keypoints);
//    cv::namedWindow("sift vector as image", cv::WINDOW_AUTOSIZE);
//    cv::imshow("sift vector as image", descriptors);
//    cv::waitKey(0);

    //std::cout << "Hello, World!" << std::endl;
    return 0;
}
