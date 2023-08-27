/*
 * @Author: TwilightZrui 1193882630@qq.com
 * @Date: 2023-04-15 23:38:37
 * @LastEditors: TwilightZrui 1193882630@qq.com
 * @LastEditTime: 2023-04-15 23:41:49
 * @FilePath: /LeetCode/graham_2.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%A
 */
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

struct point {
    int x;
    int y;
};

// 将点集转换为 OpenCV 中的 Point2f 类型
vector<Point2f> convertToPoints(vector<point> &points) {
    vector<Point2f> pts(points.size());
    for (int i = 0; i < points.size(); i++) {
        pts[i] = Point2f((float)points[i].x, (float)points[i].y);
    }
    return pts;
}

// 绘制凸包边界
void drawConvexHull(Mat &img, vector<point> &points) {
    vector<Point2f> pts = convertToPoints(points);
    vector<vector<Point2f>> contours;
    contours.push_back(pts);
    Scalar color = Scalar(0, 0, 255); // 红色
    drawContours(img, contours, 0, color, 2);
}

int main() {
    vector<point> feasiblePoints;
    feasiblePoints.push_back({0, 0});
    feasiblePoints.push_back({4, 0});
    feasiblePoints.push_back({3, 3});
    feasiblePoints.push_back({1, 3});
    vector<point> blockedPoints;
    blockedPoints.push_back({2, 1});
    blockedPoints.push_back({1, 2});
    blockedPoints.push_back({2, 2});

    // 绘制可行点和不可行点
    Mat img(400, 400, CV_8UC3, Scalar(255, 255, 255)); // 白色背景
    Scalar feasibleColor = Scalar(0, 255, 0);          // 绿色
    Scalar blockedColor = Scalar(255, 0, 0);           // 蓝色
    for (auto p : feasiblePoints) {
        circle(img, Point(p.x * 50, (4 - p.y) * 50), 3, feasibleColor, FILLED);
    }
    for (auto p : blockedPoints) {
        circle(img, Point(p.x * 50, (4 - p.y) * 50), 3, blockedColor, FILLED);
    }

    // 绘制凸包边界
    vector<point> hullPoints = convexHull(feasiblePoints);
    drawConvexHull(img, hullPoints);

    namedWindow("Convex Hull", WINDOW_NORMAL);
    imshow("Convex Hull", img);
    waitKey(0);
    return 0;
}
