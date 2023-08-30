
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct point {
    int x;
    int y;
};

// 叉积函数
int cross(point A, point B, point C) {
    int x1 = B.x - A.x;
    int y1 = B.y - A.y;
    int x2 = C.x - A.x;
    int y2 = C.y - A.y;
    return x1 * y2 - x2 * y1;
}

// 计算两点间距离的平方
int dist2(point A, point B) {
    int dx = A.x - B.x;
    int dy = A.y - B.y;
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

// 判断点c是否在以a和b为向量构成的半平面内
bool isInHalfspace(point a, point b, point c) {
    return cross(a, b, c) >= 0;
}

// 判断顶点p是否包含不可行点
bool containsBlockedPoint(vector<point> &blockedPoints, point p) {
    for (auto b : blockedPoints) {
        if (isInHalfspace(p, b, blockedPoints[0])) {
            return true;
        }
    }
    return false;
}

// 求解可行点集中的最大凸包面积，排除不可行点的影响
int maxConvexHullArea(vector<point> &feasiblePoints, vector<point> &blockedPoints) {
    // 构建初始的凸包
    vector<point> hull = convexHull(feasiblePoints);
    int maxArea = 0;
    // 对于凸包的每个顶点，判断是否有不可行点在其中
    for (int i = 0; i < hull.size(); i++) {
        if (containsBlockedPoint(blockedPoints, hull[i])) {
            // 在可行点中找到一个不同的点
            int j = i + 1;
            while (j != i && containsBlockedPoint(blockedPoints, hull[j])) {
                j = (j + 1) % hull.size();
            }
            if (j != i) { // 找到了一个可行点
                point tmp = hull[i];
                hull[i] = hull[j];
                hull[j] = tmp;
                // 重新构建凸包，并计算面积
                vector<point> newHull = convexHull(hull);
                int area = 0;
                for (int k = 1; k < newHull.size() - 1; k++) {
                    area += cross(newHull[0], newHull[k], newHull[k + 1]);
                }
                maxArea = max(maxArea, abs(area));
            }
        }
    }
    return maxArea / 2;
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
    int maxArea = maxConvexHullArea(feasiblePoints, blockedPoints);
    cout << "Max convex hull area: " << maxArea << endl;
    return 0;
}
