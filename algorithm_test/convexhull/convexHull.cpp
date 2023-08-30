/*
 * @Author: TwilightZrui 1193882630@qq.com
 * @Date: 2022-10-27 16:26:19
 * @LastEditors: TwilightZrui 1193882630@qq.com
 * @LastEditTime: 2023-02-20 22:09:15
 * @FilePath: /LeetCode/convexHull.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/***
 * @Author       : TwilightZrui
 * @Date         : 2022-10-27 16:26:19
 * @LastEditors  : TwilightZrui
 * @LastEditTime : 2022-10-27 16:26:20
 * @FilePath     : /LeetCode/convexHull.cpp
 * @Description  :
 * @Copyright (c) 2022, All Rights Reserved.
 */

#include "opencv2/opencv.hpp"
#include <iostream>
#include <math.h>
#include <stack>

using namespace std;
using namespace cv;

int main() {

    // 随机生成测试点集
    Mat img = Mat::zeros(500, 500, CV_8UC3);
    RNG rng(getTickCount());
    vector<Point2f> points;
    for (int i = 0; i < 50; i++) {
        Point2f point;
        point.x = rng.uniform(cvRound(img.cols / 4), cvRound(img.cols * 3 / 4));
        point.y = rng.uniform(cvRound(img.rows / 4), cvRound(img.rows * 3 / 4));
        circle(img, point, 2,
               Scalar(rng.uniform(0, 255), rng.uniform(0, 255),
                      rng.uniform(0, 255)),
               FILLED, LINE_AA);
        points.push_back(point);
    }

    // 创建一个容器存放函数返回的凸包顶点
    vector<Point2f> Hull;
    // 调用凸包函数
    convexHull(points, Hull, true);

    // 凸包绘制
    for (int i = 0; i < Hull.size(); i++) {
        line(img, Hull[i], Hull[(i + 1) % Hull.size()], Scalar(255, 0, 0), 2,
             LINE_AA);
    }

    namedWindow("Convex", WINDOW_AUTOSIZE);
    imshow("Convex", img);
    waitKey(0);
}
