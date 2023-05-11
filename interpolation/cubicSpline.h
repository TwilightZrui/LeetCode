/*
 * @Author: TwilightZrui 1193882630@qq.com
 * @Date: 2023-05-04 20:21:41
 * @LastEditors: TwilightZrui 1193882630@qq.com
 * @LastEditTime: 2023-05-04 20:26:57
 * @FilePath: /LeetCode/interpolation/cubicSpline.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */

#include <vector>
#ifndef CUBIC_SPLINE_H
#define CUBIC_SPLINE_H
#include <cmath>
#include <iostream>
class CubicSplineInterpolator {
  public:
    // Default constructor
    CubicSplineInterpolator() = default;

    // Constructor with input vectors
    CubicSplineInterpolator(const std::vector<double> &x,
                            const std::vector<double> &y);

    // Interpolation function
    double interpolate(double xq) const;

  private:
    int n;                 // number of data points
    std::vector<double> x; // x-data points
    std::vector<double> y; // y-data points
    std::vector<double> a; // coefficients a
    std::vector<double> b; // coefficients b
    std::vector<double> c; // coefficients c
    std::vector<double> d; // coefficients d
    std::vector<double> h; // differences between x-values

    // Helper function to solve the tridiagonal system
    static void tridag(const std::vector<double> &sub,
                       const std::vector<double> &diag,
                       const std::vector<double> &sup,
                       const std::vector<double> &b,
                       std::vector<double> &x);
};

#endif // CUBIC_SPLINE_H