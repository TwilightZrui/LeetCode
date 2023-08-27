/*
 * @Author: TwilightZrui 1193882630@qq.com
 * @Date: 2023-03-03 12:22:24
 * @LastEditors: TwilightZrui 1193882630@qq.com
 * @LastEditTime: 2023-03-03 15:33:11
 * @FilePath: /LeetCode/Inter.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <Eigen/Core>
#include <Eigen/Dense>
#include <Eigen/Geometry>
#include <algorithm>
#include <iostream>
#include <math.h>
#include <stack>
#include <vector>

using namespace std;
double Interpolation(double x, pair<double, double> data0, pair<double, double> data1);
Eigen::Vector4d StateInterpolation(double queryTime, Eigen::Vector4d state1, Eigen::Vector4d state2);
int main() {
    int NUM = 21;
    std::vector<Eigen::Vector4d> traj;
    traj.reserve(NUM);
    cout << "trajectory RAW: " << endl;
    for (int i = 0; i < NUM; i++) {
        Eigen::Vector4d pointTemp;
        pointTemp << 0.1 * i, 1 * i, 2 * i, 3 * i;
        traj.emplace_back(pointTemp);
        cout << pointTemp(0) << ", " << pointTemp(1) << ", " << pointTemp(2) << ", " << pointTemp(3) << endl;
    }
    cout << endl;

    double queryTime = 0.9;
    Eigen::Vector4d pointYES;
    if (queryTime < traj[0](0)) {
        pointYES = traj[0];
        cout << "小于最小的一个" << endl;
    } else if (queryTime > traj[NUM - 1](0)) {
        pointYES = traj[NUM - 1];
        cout << "大于最大的一个" << endl;
    } else {
        for (int i = 0; i < NUM; i++) {
            if (abs(queryTime - traj[i](0)) < 1e-3) {
                cout << "等于其中一个" << endl;
                pointYES = traj[i];
                break;
            } else if (((queryTime - traj[i](0)) > 0) && ((queryTime - traj[i + 1](0)) < 0)) {
                cout << "被插值了" << endl;
                pointYES = StateInterpolation(queryTime, traj[i], traj[i + 1]);
                break;
            }
        }
    }
    cout << "pointYES: " << pointYES(0) << ", " << pointYES(1) << ", " << pointYES(2) << ", " << pointYES(3) << endl;
    return 0;
}

Eigen::Vector4d StateInterpolation(double queryTime, Eigen::Vector4d state1, Eigen::Vector4d state2) {
    Eigen::Vector4d state;
    state(0) = queryTime;
    state(1) = Interpolation(queryTime, make_pair(state1(0), state1(1)), make_pair(state2(0), state2(1)));
    state(2) = Interpolation(queryTime, make_pair(state1(0), state1(2)), make_pair(state2(0), state2(2)));
    state(3) = Interpolation(queryTime, make_pair(state1(0), state1(3)), make_pair(state2(0), state2(3)));
    return state;
}
double Interpolation(double queryTime, pair<double, double> data0, pair<double, double> data1) {
    double value;
    double k = (data1.second - data0.second) / (data1.first - data0.first + 1e-6);
    double b = (data1.first * data0.second - data1.second * data0.first) / (data1.first - data0.first + 1e-6);

    value = k * queryTime + b;

    return value;
}