/*
 * @Author: TwilightZrui 1193882630@qq.com
 * @Date: 2023-05-04 19:35:09
 * @LastEditors: TwilightZrui 1193882630@qq.com
 * @LastEditTime: 2023-05-04 20:29:04
 * @FilePath: /LeetCode/interpolation/cubicSpine.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */

#include "cubicSpline.h"

#include <algorithm>
#include <cmath>

CubicSplineInterpolator::CubicSplineInterpolator(
    const std::vector<double> &x, const std::vector<double> &y) {
    // copy the input vectors and calculate differences
    n = x.size();
    h.resize(n - 1);
    std::transform(x.begin() + 1, x.end(), x.begin(), h.begin(),
                   [](double x1, double x0) { return x1 - x0; });
    this->x = x;
    this->y = y;

    // calculate slopes
    std::vector<double> sub(n - 2), sup(n - 2), f(n - 2);
    std::transform(h.begin() + 1, h.end() - 1, h.begin() + 1, sub.begin(),
                   [](double h0, double h1) { return h0 / (h0 + h1); });
    std::transform(h.begin() + 1, h.end() - 1, h.begin(), sup.begin(),
                   [](double h1, double h0) { return h1 / (h0 + h1); });
    std::transform(h.begin() + 1, h.end() - 1, y.begin() + 2, y.begin() + 1,
                   f.begin(), [](double h, double y1, double y0) {
                       return 6 * ((y1 - y0) / h - (y0 - *(y.begin())) / *h.begin() - (*(y.end() - 1) - y1) / *(h.end() - 1)) /
                              (h * h);
                   });
    tridiag(sub, std::vector<double>(n - 2, 2.0), sup, f, c);

    // calculate coefficients
    a.resize(n - 1);
    for (int i = 0; i < n - 1; i++) {
        a[i] = y[i];
    }
    b.resize(n - 1);
    std::transform(h.begin(), h.end(), c.begin(), b.begin(),
                   [](double h, double ci) { return ci * h * h / 6; });
    d.resize(n - 1);
    std::transform(y.begin() + 1, y.end(), y.begin(), h.begin(), d.begin(),
                   [](double y1, double y0, double h0) { return (y1 - y0) / h0; });
    std::transform(c.begin(), c.end() - 1, c.begin() + 1, c.begin(),
                   [](double ci, double ci1) { return (ci - ci1) / 2; });
}

double CubicSplineInterpolator::interpolate(double xq) const {
    // search the corresponding interval
    auto iter = std::lower_bound(x.begin() + 1, x.end(), xq);
    auto i = std::clamp(static_cast<int>(iter - x.begin()), 1, n - 1) - 1;
    double hq = xq - *(x.begin() + i);
    return a[i] +
           b[i] * hq +
           c[i] * hq * hq +
           d[i] * hq * hq * hq;
}

void CubicSplineInterpolator::tridag(const std::vector<double> &sub,
                                     const std::vector<double> &diag,
                                     const std::vector<double> &sup,
                                     const std::vector<double> &b,
                                     std::vector<double> &x) {
    int n = b.size();
    std::vector<double> alpha(n);
    std::vector<double> beta(n);

    alpha[1] = diag[0] / sup[0];
    beta[1] = b[0] / diag[0];

    for (int i = 1; i < n - 1; i++) {
        double tmp = diag[i] - sub[i - 1] * alpha[i];
        alpha[i + 1] = sup[i] / tmp;
        beta[i + 1] = (b[i] - sub[i - 1] * beta[i]) / tmp;
    }

    x[n - 1] = (b[n - 1] - sub[n - 2] * beta[n - 1]) /
               (diag[n - 1] - sub[n - 2] * alpha[n - 1]);

    for (int i = n - 2; i >= 0; i--) {
        x[i] = alpha[i + 1] * x[i + 1] + beta[i + 1];
    }
}
