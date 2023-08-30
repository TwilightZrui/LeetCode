/*
 * @Author: TwilightZrui 1193882630@qq.com
 * @Date: 2023-04-15 16:50:13
 * @LastEditors: TwilightZrui 1193882630@qq.com
 * @LastEditTime: 2023-04-15 17:36:48
 * @FilePath: /LeetCode/convex_com.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <cmath>
#include <iostream>
#include <vector>

struct Point {
    double x, y;
    Point(double x, double y) : x(x), y(y) {}
};

// 计算三角形的重心
Point triangleCentroid(const Point &a, const Point &b, const Point &c) {
    double x = (a.x + b.x + c.x) / 3.0;
    double y = (a.y + b.y + c.y) / 3.0;
    return Point(x, y);
}

// 计算非凸多边形的几何中心
Point polygonCentroid(const std::vector<Point> &vertices) {
    int n = static_cast<int>(vertices.size());
    double area = 0.0;
    Point centroid(0.0, 0.0);
    for (int i = 1; i < n - 1; ++i) {
        Point p1 = vertices[0], p2 = vertices[i], p3 = vertices[i + 1];
        double x1 = p2.x - p1.x, y1 = p2.y - p1.y;
        double x2 = p3.x - p2.x, y2 = p3.y - p2.y;
        double cross = x1 * y2 - x2 * y1;
        double areaPart = 0.5 * cross;
        area += areaPart;
        Point centroidPart = triangleCentroid(p1, p2, p3);
        centroid.x += areaPart * centroidPart.x;
        centroid.y += areaPart * centroidPart.y;
    }
    centroid.x /= (3.0 * area);
    centroid.y /= (3.0 * area);
    return centroid;
}

int main() {
    // std::vector<Point> vertices = {{0, 0}, {4, 0}, {3, 3}, {1, 3}, {2, 2}};
    std::vector<Point> vertices = {{0, 0}, {4, 0}, {4, 4}, {0, 4}};
    Point centroid = polygonCentroid(vertices);
    std::cout << "Centroid: (" << centroid.x << ", " << centroid.y << ")" << std::endl;
    return 0;
}