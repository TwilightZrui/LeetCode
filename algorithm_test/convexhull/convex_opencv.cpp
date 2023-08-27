#include <iostream>
#include <vector>
#include <cmath>
#include <opencv2/opencv.hpp> // 注意头文件

using namespace std;
using namespace cv; // 注意加上命名空间

int main() {
    int n;
    cin >> n;

    // 读入每个顶点的坐标
    vector<Point2f> points;
    for (int i = 0; i < n; i++) {
        double x, y;
        cin >> x >> y;
        points.push_back(Point2f(round(x * 100), round(y * 100))); // 注意将小数乘以100并四舍五入转为整数
    }

    // 绘制原始的非凸多边形
    Mat img(600, 600, CV_8UC3, Scalar(255, 255, 255)); // 创建画布
    vector<vector<Point>> contours = {points}; // 注意OpenCV中的vector是二维的
    polylines(img, contours, true, Scalar(0, 0, 0), 2, LINE_AA); // 绘制非凸多边形

    // 计算面积最大的凸包
    vector<Point2f> convex_hull;
    cv::convexHull(points, convex_hull);
    vector<vector<Point>> hull_contours = {convex_hull};

    // 绘制面积最大的凸包
    polylines(img, hull_contours, true, Scalar(255, 0, 0), 2, LINE_AA);

    // 显示绘制结果
    namedWindow("result", WINDOW_NORMAL);
    imshow("result", img);
    waitKey(0);

    return 0;
}