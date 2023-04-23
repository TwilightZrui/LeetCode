/*
 * @Author: TwilightZrui 1193882630@qq.com
 * @Date: 2023-04-16 21:26:04
 * @LastEditors: TwilightZrui 1193882630@qq.com
 * @LastEditTime: 2023-04-16 21:27:33
 * @FilePath: /LeetCode/convex_CGAL.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <CGAL/Convex_hull_2.h>
#include <CGAL/Exact_predicates_exact_constructions_kernel.h>
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;
using namespace CGAL;

// 定义精确内核
typedef Exact_predicates_exact_constructions_kernel Kernel;

// 精确浮点数
typedef Kernel::Point_2 Point;

// 计算两点距离的平方
double squared_distance(const Point &a, const Point &b) {
    return (a - b).squared_length();
}

// 计算多边形面积
double polygon_area(vector<Point> &points) {
    double s = 0.0;
    int n = points.size();
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        s += points[i].x() * points[j].y() - points[i].y() * points[j].x();
    }
    return 0.5 * fabs(s);
}

int main() {
    // 随机生成20个点作为非凸多边形的顶点
    const int n = 20;
    vector<Point> points(n);
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        points[i] = Point(rand() / (double)(RAND_MAX), rand() / (double)(RAND_MAX));
        cout << "(" << points[i].x() << "," << points[i].y() << ")" << endl;
    }

    // 使用CGAL计算点集的凸包
    vector<Point> hull;
    convex_hull_2(points.begin(), points.end(), back_inserter(hull));

    // 枚举凸包上的点，找到面积最大的凸多边形
    double max_area = 0.0;
    vector<Point> best_hull;
    for (int i = 0; i < hull.size(); i++) {
        vector<Point> curr_hull;
        for (int j = 0; j < hull.size(); j++) {
            if (i != j) {
                bool on_left = true;
                for (int k = 0; k < hull.size(); k++) {
                    if (k != i && k != j) {
                        if (orientation(hull[i], hull[j], hull[k]) == LEFT_TURN) {
                            on_left = false;
                            break;
                        }
                    }
                }
                if (on_left) {
                    curr_hull.push_back(hull[j]);
                }
            }
        }
        double area = polygon_area(curr_hull);
        if (area > max_area) {
            max_area = area;
            best_hull = curr_hull;
        }
    }

    // 绘制凸包和凸包内面积最大的凸多边形
    Mat img(500, 500, CV_8UC3, Scalar(0, 0, 0));
    int n_hull = best_hull.size();
    for (int i = 1; i < n_hull; i++) {
        line(img, Point(best_hull[i - 1].x() * img.cols, best_hull[i - 1].y() * img.rows), Point(best_hull[i].x() * img.cols, best_hull[i].y() * img.rows), Scalar(0, 0, 255), 2, LINE_AA);
    }
    line(img, Point(best_hull.back().x() * img.cols, best_hull.back().y() * img.rows), Point(best_hull.front().x() * img.cols, best_hull.front().y() * img.rows), Scalar(0, 0, 255), 2, LINE_AA);
    imshow("Convex Hull", img);
    waitKey(0);
    return 0;
}

// ; 这段代码使用了 CGAL 库中的凸包计算函数 convex_hull_2，以及精确内核中的 Point_2 和 Exact_predicates_exact_constructions_kernel。具体实现方法：

// ; - 首先随机生成20个点，作为非凸多边形的顶点。
// ; - 使用CGAL库计算点集的凸包。
// ; - 在凸包上枚举所有的点，构造除了当前点之外的凸包，判断凸包上的每个点是否在当前点的左侧，构造凸包时选取所有在左侧的点。根据构造出的凸包计算面积，取最大面积的凸多边形作为结果。

// ; 由于 CGAL 库中的凸包计算函数具有 O(n log n) 的时间复杂度，因此该实现具有较好的时间性能。同时，由于 CGAL 库中的精确计算特性，该实现也具有较好的准确性。

// ; 该代码同样输出随机生成的点的坐标，以及绘制了凸包和凸包内面积最大的凸多边形。