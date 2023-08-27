/***
 * @Author       : TwilightZrui
 * @LastUpdateTime: Do not edit
 * @FilePath     : /LeetCode/transform.cpp
 * @Description  :
 * @Institute    : CSE ZJU
 */
#include <Eigen/Core>
#include <Eigen/Dense>
#include <Eigen/Geometry>

#include <cstdlib>
#include <ctime>
#include <iostream>
#define random(x) rand() / double(RAND_MAX)

float randomNumFloat_0_to_1() {
    float num;
    return num = random(1);
}

using namespace std;

const int COL = 20;
const int ROW = 3;

int main() {
    srand((int)time(0)); // 产生随机种子  把0换成NULL也行
    Eigen::Matrix<float, COL, ROW> mapb;
    for (int i = 0; i < COL; i++) {
        for (int j = 0; j < ROW; j++) {
            if (j == 0)
                mapb(i, j) = i;
            if (j == 1)
                mapb(i, j) = j;
            if (j == 2)
                mapb(i, j) = 0;
            cout << mapb(i, j) << "  ";
        }
        cout << endl;
    }
    // cout << mapb << endl
    //      << endl;
    // cout << mapb.transpose() << endl;
    // Eigen::Quaterniond q1 =
    //     Eigen::AngleAxisd(3.141593 / 2.0, Eigen::Vector3d::UnitZ()) * // yaw
    //     Eigen::AngleAxisd(0.0, Eigen::Vector3d::UnitY()) *
    //     Eigen::AngleAxisd(0.0, Eigen::Vector3d::UnitX());

    // Eigen::Vector3d t1 = Eigen::Vector3d(2, 2, 0.0);

    // Eigen::Matrix<float, ROW, COL> maptransformed;
    // maptransformed = q1 * mapb.transpose() + t1;
    // Eigen::Matrix<Eigen::Vector3f, COL, ROW> mapW;
    // Eigen::Matrix<float, 8, 6> mapB;

    // for (int i = 0; i < COL; i++)
    //     for (int j = 0; j < ROW; j++) {
    //         float num = randomNumFloat_0_to_1();
    //         mapW(i, j, 0) = i;
    //     }
    //
    // Eigen::Matrix<Eigen::Matrix<float, 2, 1>, COL, ROW> mapw;
    // // Eigen::Matrix<float, 2, 1> p;
    // for (int i = 0; i < COL; i++) {
    //     for (int j = 0; j < ROW; j++) {
    //         mapw(i, j) << i, j;
    //         cout << mapw(i, j) << "  ";
    //     }
    //     cout << endl
    //          << endl;
    // }
    // mapw.resize(1, 20);
    // Eigen::Map<Eigen::MatrixXf> M2(mapw.data(), 2, 10);

    // Eigen::Matrix<float, 2, ROW> transed;
    // transed = q1 * mapw + t1;
    // cout << transed << endl;
    // cout << randomNumInt_0_or_1() << " ";
}

// Eigen::Vector3d l1 = Eigen::Vector3d(3, 1, 0);
// Eigen::Quaterniond q1 =
//     Eigen::AngleAxisd(3.141593 / 2.0, Eigen::Vector3d::UnitZ()) * // yaw
//     Eigen::AngleAxisd(0.0, Eigen::Vector3d::UnitY()) *
//     Eigen::AngleAxisd(0.0, Eigen::Vector3d::UnitX());

// Eigen::Vector3d t1 = Eigen::Vector3d(2, 2, 0.0);

// Eigen::Vector3d output;
// output = q1 * l1 + t1;
// cout << "output : " << output << endl;