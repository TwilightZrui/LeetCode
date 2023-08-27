#include <algorithm>
#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <vector>

using namespace std;
using namespace cv;

// Structure to represent a point
struct MyPoint {
    int x, y;
};

MyPoint p0;
// Function to find orientation of triplet (p, q, r)
/*
orientation 函数用于确定三个点的方向关系。它接受三个点作为参数，分别是 p、q 和 r，并根据这些点的位置关系返回一个值。

具体来说，orientation 函数返回以下三种值之一：

0：表示三个点 p、q 和 r 是共线的（Collinear）。
1：表示三个点 p、q 和 r 形成顺时针方向（Clockwise）。
2：表示三个点 p、q 和 r 形成逆时针方向（Counterclockwise）。
根据这个返回值，我们可以判断这三个点的位置关系，这在 Graham's scan 算法中非常重要。
*/

int orientation(MyPoint p, MyPoint q, MyPoint r) {
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);

    if (val == 0)
        return 0;             // Collinear
    return (val > 0) ? 1 : 2; // Clockwise or Counterclockwise
}

// Function to compare two points based on polar angle
bool compareMy(MyPoint p1, MyPoint p2) {
    // int o = orientation(p0, p1, p2);
    // if (o == 0)
    //     return (p0.x * p0.x + p0.y * p0.y) < (p1.x * p1.x + p1.y * p1.y);
    // return (o == 2);

    int o = orientation(p0, p1, p2);
    if (o == 0)
        return (p0.x * p0.x + p0.y * p0.y) < (p1.x * p1.x + p1.y * p1.y);
    return (o == 2);
}

// Function to compute convex hull using Graham's scan algorithm
vector<MyPoint> convexHull(vector<MyPoint> points, int n) {
    // Find the bottommost point
    int ymin = points[0].y, min = 0;
    for (int i = 1; i < n; i++) {
        int y = points[i].y;

        // Pick the bottom-most or chose the left-most point in case of tie
        if ((y < ymin) || (ymin == y && points[i].x < points[min].x))
            ymin = points[i].y, min = i;
    }

    // Place the bottom-most point at first position
    swap(points[0], points[min]);

    p0 = points[0]; // 最底部的点

    // Sort remaining points based on their polar angle wrt the first point

    std::sort(points.begin() + 1, points.end(), compareMy);

    // If two or more points make same angle with p0, remove all but the one that is farthest from p0
    int m = 1; // Initialize size of modified vector
    for (int i = 1; i < n; i++) {
        // Keep removing i while angle of i and i+1 is same with respect to p0
        while (i < n - 1 && orientation(p0, points[i], points[i + 1]) == 0)
            i++;

        points[m] = points[i];
        m++; // Update size of modified vector
    }

    // If modified array of points has less than 3 points, return empty vector
    if (m < 3)
        return vector<MyPoint>();

    // Create an empty stack and push first three points to it
    vector<MyPoint> hull;
    hull.push_back(points[0]);
    hull.push_back(points[1]);
    hull.push_back(points[2]);

    // Process remaining n-3 points
    for (int i = 3; i < m; i++) {
        // Keep removing top while the angle formed by points next-to-top, top, and points[i] makes a non-left turn
        while (hull.size() > 1 && orientation(hull[hull.size() - 2], hull[hull.size() - 1], points[i]) != 2)
            hull.pop_back();

        hull.push_back(points[i]);
    }

    return hull;
}

int main() {
    vector<MyPoint> points{
        {100, 100},
        {200, 250},
        {300, 100},
        {400, 150},
        {450, 250},
        {350, 300},
        {200, 350},
        {150, 300},
        // {100, 250},
    };

    int n = points.size();

    // Find convex hull
    vector<MyPoint> hull = convexHull(points, n);

    // Display original points and convex hull
    Mat img(500, 500, CV_8UC3, Scalar(255, 255, 255));

    // visualization
    for (int i = 0; i < n; i++) {
        Point2f point;
        point.x = points[i].x;
        point.y = img.rows - points[i].y;
        circle(img, point, 3, Scalar(0, 0, 255), FILLED);

        // circle(img, point, 2, Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255)),
        //        FILLED, LINE_AA);
    }

    for (int i = 1; i < hull.size(); i++) {
        Point2f point1;
        point1.x = hull[i - 1].x;
        point1.y = img.rows - hull[i - 1].y;

        Point2f point2;
        point2.x = hull[i].x;
        point2.y = img.rows - hull[i].y;
        // line(img, point1, point2, Scalar(255, 0, 0), 2);
    }
    Point2f point3(hull[hull.size() - 1].x, img.rows - hull[hull.size() - 1].y);
    Point2f point4(hull[0].x, img.rows - hull[0].y);
    // line(img, point3, point4, Scalar(255, 0, 0), 2);

    imshow("Convex Hull", img);
    waitKey(0);

    return 0;
}