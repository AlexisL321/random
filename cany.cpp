//
// Created by flye on 2022/10/6.
//
#include <iostream>
#include <vector>
#include "opencv2/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/features2d.hpp>
//#include "canny.cpp"
#include <chrono>
int main() {
    cv::Mat image1 = cv::imread("output1_80.jpg", cv::IMREAD_COLOR);
    cv::imshow("picture1 original", image1);
    cv::Mat gray_image1;
    cv::Mat gray_image2;
    cv::Mat gray_image3;
    cv::Mat gray_image4;
    cv::Mat gray_image5;
    cv::Mat image2 = cv::imread("output2_80.jpg", cv::IMREAD_COLOR);
    cv::Mat image3 = cv::imread("output3_80.jpg", cv::IMREAD_COLOR);
    cv::Mat image4 = cv::imread("output4_80.jpg", cv::IMREAD_COLOR);
    cv::Mat image5 = cv::imread("output5_80.jpg", cv::IMREAD_COLOR);
    cvtColor( image1, gray_image1, cv::COLOR_BGR2GRAY );
    cvtColor( image2, gray_image2, cv::COLOR_BGR2GRAY );
    cvtColor( image3, gray_image3, cv::COLOR_BGR2GRAY );
    cvtColor( image4, gray_image4, cv::COLOR_BGR2GRAY );
    cvtColor( image5, gray_image5, cv::COLOR_BGR2GRAY );

    cv::Mat dst1;
    cv::Mat dst2;
    cv::Mat dst3;
    cv::Mat dst4;
    cv::Mat dst5;
    cv::Canny(image2,dst2,160, 200);
    cv::Canny(image1,dst1, 160, 200);
    cv::Canny(image3,dst3, 160, 200);
    cv::Canny(image4,dst4, 160, 200);
    cv::Canny(image5,dst5, 160, 200);

    cv::imwrite("C1_80.jpg", dst1);
    cv::imwrite("C2_80.jpg", dst2);
    cv::imwrite("C3_80.jpg", dst3);
    cv::imwrite("C4_80.jpg", dst4);
    cv::imwrite("C5_80.jpg", dst5);


}