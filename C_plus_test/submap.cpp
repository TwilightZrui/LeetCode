/***
 * @Author       : TwilightZrui
 * @Date         : 2022-11-20 14:04:37
 * @LastEditTime : 2022-11-20 14:10:30
 * @FilePath     : /src/home/twilight/project/LeetCode/submap.cpp
 * @Description  :
 * @Copyright (c) 2022, All Rights Reserved.
 */
#include <iostream>

#include <Eigen/Core>
#include <Eigen/Dense>
#include <Eigen/Geometry>

#include <cstdlib>
#include <ctime>
#include <iostream>
#define random(x) rand() / double(RAND_MAX)

float randomNumFloat_0_to_1() {
    float num;
    num = random(1);
    return num;
}

int randomNumInt_0_or_1() {
    double num;
    num = random(1);
    // printf("%0.3f ",num);
    if (num < 0.2)
        num = 0;
    else
        num = 1;
    return int(num);
}
using namespace std;
using namespace Eigen;

const int COL = 3;
const int ROW = 3;

int main() {
    Eigen::Matrix<int, COL, ROW> m;
    cout << "   ";
    for (int i = 0; i < 10; i++)
        cout << i << "  ";
    cout << endl;
    for (int i = 0; i < COL; i++) {
        cout << i << "  ";
        for (int j = 0; j < ROW; j++) {
            m(i, j) = randomNumInt_0_or_1();
            cout << m(i, j) << "  ";
        }
        cout << endl;
    }

    // cout << "sub matrix:" << endl;
    // Eigen::Vector2i LF(2, 0);
    // Eigen::Vector2i RF(0, 2);
    // Eigen::Vector2i LH(5, 3);
    // Eigen::Vector2i RH(3, 5);
    // int col = (LH(0) - LF(0) + 1); // 4
    // int row = (RF(1) - LF(1) + 1); // 3
    // Eigen::Matrix<int, 4, 3> msub;

    // for (int i = LF(0); i < col; i++) {
    //     for (int j = LF(1); j < row; j++) {
    //         // msub << m(i, j);
    //         cout << m(i, j) << " ";
    //     }
    //     cout << endl;
    // }
}
