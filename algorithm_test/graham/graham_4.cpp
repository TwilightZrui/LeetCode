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
vector<point> convexHull(vector<point>& points) {
    int n = points.size();
    vector<int> indices(n);
    for (int i = 0; i < n; i++) indices[i] = i;
    sort(indices.begin(), indices.end(), [&points](int i, int j) {
        return points[i].x < points[j].x ||
            (points[i].x == points[j].x && points[i].y < points[j].y);
    });

    vector<point> hull;
    int k = 0;
    for (int i = 0; i < n; i++) {
        while (k >= 2 && cross(hull[k-2], hull[k-1], points[indices[i]]) <= 0) {
            hull.pop_back();
            k--;
        }
        hull.push_back(points[indices[i]]);
        k++;
    }
    for (int i = n - 2, t = k + 1; i >= 0; i--) {
        while (k >= t && cross(hull[k-2], hull[k-1], points[indices[i]]) <= 0) {
            hull.pop_back();
            k--;
        }
        hull.push_back(points[indices[i]]);
        k++;
    }
    if (hull.size() > 1) hull.pop_back();
    return hull;
}

int main() {
    // 可行点和不可行点的坐标
    vector<point> feasiblePoints = {{0, 0}, {4, 0}, {3, 3}, {1, 3}};
    vector<point> blockedPoints = {{2, 1}, {1, 2}, {2, 2}};

    // 从可行点中取出能够构成凸包的点
    vector<point> hullPoints;
    for (auto p : feasiblePoints) {
        bool isBlocked = false;
        for (auto bp : blockedPoints) {
            if (dist2(p, bp) < 1e-6) {  // 坐标相等
                isBlocked = true;
                break;
            }
        }
        if (!isBlocked) {
            hullPoints.push_back(p);
        }
    }

    // 计算凸包
    vector<point> hull = convexHull(hullPoints);

    // 将坐标映射到图像上
    int width = 400;
    int height = 400;
    Mat img(height, width, CV_8UC3, Scalar(255, 255, 255));
    for (auto p : feasiblePoints) {
        circle(img, Point(p.x * 100, height - p.y * 100), 5, Scalar(0, 0, 255), -1);
    }
    for (auto p : blockedPoints) {
        circle(img, Point(p.x * 100, height - p.y * 100), 5, Scalar(128, 128, 128), -1);
    }
    for (int i = 0; i < hull.size() - 1; i++) {
        line(img, Point(hull[i].x * 100, height - hull[i].y * 100),
             Point(hull[i+1].x * 100, height - hull[i+1].y * 100),
             Scalar(0, 255, 0), 2);
    }

    // 保存结果为图片
    imwrite("convex_hull.png", img);
    namedWindow("Convex Hull", WINDOW_AUTOSIZE);
    imshow("Convex Hull", img);
    waitKey(0);
    return 0;
}