//
// Created by flye on 2022/6/18.
//

#include <iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/features2d.hpp>


int main() {
    cv::Mat image = cv::imread("image3.jpg", cv::IMREAD_COLOR);

    //Fine keypoints
    auto start = std::chrono::steady_clock::now();
    auto detector = cv::FastFeatureDetector::create();
    std::vector<cv::KeyPoint>keypoints;
    detector->detect(image, keypoints);
    std::cout<<"keypoints without threshold "<< keypoints.size() << "\n";
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> duration = end - start;
    std::cout<<"detection time without threshold "<<duration.count()<<"s\n";
    //std::cout<<(double) (end-start).count() <<"s\n"; //This won't work


    //present the keypoint on image
    cv::Mat image_with_keypoints;
    cv::drawKeypoints(image, keypoints, image_with_keypoints);
    //for visualization
    cv::namedWindow("image with keypoints", cv::WINDOW_AUTOSIZE);
    cv::imshow("image with keypoints", image_with_keypoints);
    cv::waitKey(0);

    //ORB descriptor extraction
    auto extractor = cv::ORB::create();
    cv::Mat descriptors;
    auto start2 = std::chrono::steady_clock::now();
    extractor->compute(image, keypoints, descriptors);
    auto end2 = std::chrono::steady_clock::now();
    std::chrono::duration<double> duration2 = end2 - start2;
    std::cout<<"extraction time without threshold "<<duration2.count()<<"s\n";
    cv::namedWindow("descriptor", cv::WINDOW_AUTOSIZE);
    cv::imshow("descriptor", descriptors);



    std::cout<<"default threshold"<< detector->getThreshold() << "\n";
    detector->setThreshold(20);
    std::cout<<"nomax suppression "<<detector->getNonmaxSuppression() << "\n";
    detector->setNonmaxSuppression(1);

    auto start1 = std::chrono::steady_clock::now();
    detector->detect(image, keypoints);
    auto end1 = std::chrono::steady_clock::now();
    std::chrono::duration<float> duration1 = end1 - start1;
    std::cout<<"detection time with threshold "<< duration1.count()<<"s\n";
    //std::cout<<(double) (end1 - start1).count() <<"s\n";
    std::cout<< "keypoints extracted with threshold "<<keypoints.size() << "\n";

    auto start3 = std::chrono::steady_clock::now();
    extractor->compute(image, keypoints, descriptors);
    auto end3 = std::chrono::steady_clock::now();
    std::chrono::duration<double> duration3 = end3 - start3;
    std::cout<<"extract time with threshold "<<duration3.count()<<"s\n";

    cv::drawKeypoints(image, keypoints, image_with_keypoints);
    cv::namedWindow("image with keypoints", cv::WINDOW_AUTOSIZE);
    cv::imshow("image with keypoints", image_with_keypoints);
    cv::waitKey(0);
    return 0;

}

