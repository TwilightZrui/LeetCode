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

// 计算向量 P1-P0 和向量 P2-P0 的叉积
double cross_1(point P0, point P1, point P2) {
    return (P1.x - P0.x) * (P2.y - P0.y) - (P1.y - P0.y) * (P2.x - P0.x);
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

// 计算向量 P1-P0 和向量 P2-P0 的点积
double dot(point P0, point P1, point P2) {
    return (P1.x - P0.x) * (P2.x - P0.x) + (P1.y - P0.y) * (P2.y - P0.y);
}

// 计算 P1-P0 与 P2-P0 的夹角
double angle(point P0, point P1, point P2) {
    return acos(dot(P0, P1, P2) / sqrt(dist2(P0, P1) * dist2(P0, P2)));
}

// 逆时针旋转点集，使得顶点按顺序连接起来
void rotateHull(vector<point> &hull) {
    int minIdx = 0;
    int n = hull.size();
    for (int i = 1; i < n; i++) {
        if (hull[i].x < hull[minIdx].x || (hull[i].x == hull[minIdx].x && hull[i].y < hull[minIdx].y)) {
            minIdx = i;
        }
    }
    vector<point> newHull(n);
    for (int i = 0; i < n; i++) {
        newHull[i] = hull[(minIdx + i) % n];
    }
    hull = newHull;
}

int main() {
    // 构造可行点和不可行点
    vector<point> feasiblePoints = {
        {0, 0}, {1, -1}, {1, -2}, {0, -3}, {-1, -3}, {-2, -2}, {-2, -1}, {-1, 0}};
    vector<point> blockedPoints = {
        {-0.5, -1}, {0.5, -1}, {-1, -2}, {1, -2}};

    // 构造初始凸包
    vector<point> hull = {{-1, -1}, {-1, 1}, {1, 1}, {1, -1}, {-1, -1}};
    rotateHull(hull);

    // 计算凸包面积
    double area = 0;
    int n = hull.size();
    int j = n - 1;
    for (int i = 0; i < n; i++) {
        area += (hull[j].x + hull[i].x) * (hull[j].y - hull[i].y);
        j = i;
    }
    area = fabs(area / 2.0);

    // 旋转卡壳寻找下一个凸包点
    for (int i = 0; i < n; i++) {
        int i1 = i + 1;
        if (i1 >= n)
            i1 = 0;
        double minDist2 = DBL_MAX;
        int nextIdx = -1;
        for (int j = 0; j < feasiblePoints.size(); j++) {
            bool isBlocked = false;
            for (auto bp : blockedPoints) {
                if (dist2(feasiblePoints[j], bp) < 1e-6) {
                    isBlocked = true;
                    break;
                }
            }
            if (isBlocked)
                continue;
            double dist2 = cross(hull[i], feasiblePoints[j], hull[i1]);
            if (dist2 > 0 && dist2 < minDist2) {
                minDist2 = dist2;
                nextIdx = j;
            }
        }
        if (nextIdx >= 0) {
            double curArea = minDist2 / 2.0;
            int j = i;
            while (angle(hull[i], feasiblePoints[nextIdx], hull[i1]) < M_PI - 1e-6) {
                curArea = max(curArea, cross(hull[j], feasiblePoints[nextIdx], hull[i1]) / 2.0);
                j = (j + 1) % n;
                if (j == i1)
                    break;
            }
            hull.insert(hull.begin() + i1, feasiblePoints[nextIdx]);
            area += curArea;
        }
    }
    area += cross(hull[0], hull[n - 1], hull[1]) / 2.0;

    // 将坐标映射到图像上
    int width = 400;
    int height = 400;
    Mat img(height, width, CV_8UC3, Scalar(255, 255, 255));
    for (auto p : feasiblePoints) {
        circle(img, Point(p.x * 50 + width / 2, height / 2 - p.y * 50), 3, Scalar(0, 0, 255), -1);
    }
    for (auto p : blockedPoints) {
        circle(img, Point(p.x * 50 + width / 2, height / 2 - p.y * 50), 3, Scalar(128, 128, 128), -1);
    }
    vector<Point> hullPts;
    for (auto p : hull) {
        hullPts.push_back(Point(p.x * 50 + width / 2, height / 2 - p.y * 50));
    }
    polylines(img, hullPts, true, Scalar(0, 255, 0), 2);

    // 保存结果为图片
    imwrite("convex_hull.png", img);
    namedWindow("Convex Hull", WINDOW_AUTOSIZE);
    imshow("Convex Hull", img);
    waitKey(0);
    return 0;
}
