/*
 * @Author: TwilightZrui 1193882630@qq.com
 * @Date: 2023-04-15 23:47:51
 * @LastEditors: TwilightZrui 1193882630@qq.com
 * @LastEditTime: 2023-04-15 23:49:20
 * @FilePath: /LeetCode/graham_3.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <opencv2/opencv.hpp>
#include <vector>

using namespace cv;
using namespace std;

struct point {
    double x;
    double y;
};

// 叉积函数
double cross(point A, point B, point C) {
    double x1 = B.x - A.x;
    double y1 = B.y - A.y;
    double x2 = C.x - A.x;
    double y2 = C.y - A.y;
    return x1 * y2 - x2 * y1;
}

// 计算两点间距离的平方
double dist2(point A, point B) {
    double dx = A.x - B.x;
    double dy = A.y - B.y;
    return dx * dx + dy * dy;
}

// 返回一个非凸多边形的顶点集
vector<point> convexHull(vector<point> &points) {
    int n = points.size();
    vector<int> indices(n);
    for (int i = 0; i < n; i++)
        indices[i] = i;
    sort(indices.begin(), indices.end(), [&points](int i, int j) {
        return points[i].x < points[j].x ||
               (points[i].x == points[j].x && points[i].y < points[j].y);
    });

    vector<point> hull;
    int k = 0;
    for (int i = 0; i < n; i++) {
        while (k >= 2 && cross(hull[k - 2], hull[k - 1], points[indices[i]]) <= 0) {
            hull.pop_back();
            k--;
        }
        hull.push_back(points[indices[i]]);
        k++;
    }
    for (int i = n - 2, t = k + 1; i >= 0; i--) {
        while (k >= t && cross(hull[k - 2], hull[k - 1], points[indices[i]]) <= 0) {
            hull.pop_back();
            k--;
        }
        hull.push_back(points[indices[i]]);
        k++;
    }
    if (hull.size() > 1)
        hull.pop_back();
    return hull;
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
    vector<point> hull = convexHull(feasiblePoints);

    // 将坐标映射到图像上
    int width = 400;
    int height = 400;
    Mat img(height, width, CV_8UC3, Scalar(255, 255, 255));
    for (auto p : feasiblePoints) {
        circle(img, Point(p.x * 1000, height - p.y * 1000), 5, Scalar(0, 0, 255), -1);
    }
    for (auto p : blockedPoints) {
        circle(img, Point(p.x * 1000, height - p.y * 1000), 5, Scalar(128, 128, 128), -1);
    }
    for (int i = 0; i < hull.size() - 1; i++) {
        line(img, Point(hull[i].x * 1000, height - hull[i].y * 1000),
             Point(hull[i + 1].x * 1000, height - hull[i + 1].y * 1000),
             Scalar(0, 255, 0), 2);
    }

    namedWindow("Convex", WINDOW_AUTOSIZE);
    imshow("Convex", img);
    waitKey();
    return 0;
}