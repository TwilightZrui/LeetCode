/*
 * @Author: TwilightZrui
 * @Date: 2023-06-21 23:26:27
 */
#include <algorithm>
#include <cmath>
#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <vector>

using namespace std;
using namespace cv;

struct MyPoint {
    double x;
    double y;
};

// 计算向量AB和向量AC的叉积
double crossProduct(const MyPoint &A, const MyPoint &B, const MyPoint &C) {
    return (B.x - A.x) * (C.y - A.y) - (B.y - A.y) * (C.x - A.x);
}

// 判断点D是否在向量AB和向量AC之间
bool isInside(const MyPoint &A, const MyPoint &B, const MyPoint &C, const MyPoint &D) {
    double cross = crossProduct(A, B, C);
    double dot1 = (D.x - A.x) * (B.x - A.x) + (D.y - A.y) * (B.y - A.y);
    double dot2 = (D.x - A.x) * (C.x - A.x) + (D.y - A.y) * (C.y - A.y);
    return cross >= 0 && dot1 >= 0 && dot2 >= 0;
}

// 查找凸顶点
int findConvexVertex(const std::vector<MyPoint> &points) {
    int n = points.size();
    for (int i = 0; i < n; i++) {
        int prev = (i - 1 + n) % n;
        int next = (i + 1) % n;
        double cross = crossProduct(points[prev], points[i], points[next]);
        if (cross < 0) { // 如果相邻两边夹角大于180度，则是凸顶点
            return i;
        }
    }
    return -1;
}

// 计算最大的凸多边形
std::vector<MyPoint> computeConvexPolygon(const std::vector<MyPoint> &points) {
    std::vector<MyPoint> convexPolygon;
    int n = points.size();
    if (n < 3) {
        return convexPolygon;
    }

    int start = findConvexVertex(points);
    convexPolygon.push_back(points[start]);

    int current = start;
    do {
        int next = (current + 1) % n;
        for (int i = 0; i < n; i++) {
            if (i != current && i != next && crossProduct(points[current], points[next], points[i]) > 0) {
                next = i;
            }
        }
        convexPolygon.push_back(points[next]);
        current = next;
    } while (current != start && convexPolygon.size() <= n);

    return convexPolygon;
}

int main() {
    std::vector<MyPoint> points = {{20, 20}, {200, 20}, {300, 100}, {200, 200}, {20, 200}, {100, 100}};

    std::vector<MyPoint> convexPolygon = computeConvexPolygon(points);

    for (const auto &point : convexPolygon) {
        std::cout << "(" << point.x << ", " << point.y << ") ";
    }
    std::cout << std::endl;

    // Display original points and convex hull
    Mat img(500, 500, CV_8UC3, Scalar(255, 255, 255));
    int n = points.size();
    for (int i = 0; i < n; i++) {
        Point2f point;
        point.x = points[i].x;
        point.y = img.rows - points[i].y;
        circle(img, point, 3, Scalar(0, 0, 255), FILLED);
    }

    for (int i = 1; i < convexPolygon.size(); i++) {
        Point2f point1;
        point1.x = convexPolygon[i - 1].x;
        point1.y = img.rows - convexPolygon[i - 1].y;

        Point2f point2;
        point2.x = convexPolygon[i].x;
        point2.y = img.rows - convexPolygon[i].y;
        line(img, point1, point2, Scalar(255, 0, 0), 2);
    }
    // Point2f point3(convexPolygon[convexPolygon.size() - 1].x, img.rows - convexPolygon[convexPolygon.size() - 1].y);
    // Point2f point4(convexPolygon[0].x, img.rows - convexPolygon[0].y);
    // line(img, point3, point4, Scalar(255, 0, 0), 2);

    imshow("Convex Hull", img);
    waitKey(0);

    return 0;
}
