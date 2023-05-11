#include <cmath>
#include <iostream>
#include <vector>

// 三次样条插值
class CubicSplineInterpolator {
  public:
    CubicSplineInterpolator(const std::vector<double> &x, const std::vector<double> &y);

    double Interpolate(double x) const;
    void tridiag(const std::vector<double> &sub, const std::vector<double> &diag,
                 const std::vector<double> &sup, const std::vector<double> &b, std::vector<double> &x);

  private:
    // 三次样条的参数
    struct SplineParams {
        double a, b, c, d; // y = a + b(x - xi) + c(x - xi)^2 + d(x - xi)^3
    };

    std::vector<double> m_x;            // 数据点的 x 坐标
    std::vector<double> m_y;            // 数据点的 y 坐标
    std::vector<SplineParams> m_params; // 三次样条的参数
};

// 构造函数
CubicSplineInterpolator::CubicSplineInterpolator(const std::vector<double> &x, const std::vector<double> &y)
    : m_x(x), m_y(y) {
    int n = x.size();
    m_params.resize(n);

    // 初始化 h 和 f
    std::vector<double> h(n);
    std::vector<double> f(n);
    for (int i = 0; i < n - 1; ++i) {
        h[i] = x[i + 1] - x[i];
        f[i] = (y[i + 1] - y[i]) / h[i];
    }

    // 构造三对角矩阵
    std::vector<double> sub(n - 1), diag(n), sup(n - 1);
    for (int i = 0; i < n - 2; ++i) {
        sub[i] = h[i];
        diag[i + 1] = 2.0 * (h[i] + h[i + 1]);
        sup[i + 1] = h[i + 1];
    }
    diag[0] = diag[n - 1] = 1.0;
    sub[n - 2] = sup[0] = 0.0;

    // 解线性方程组
    std::vector<double> c(n);
    tridiag(sub, diag, sup, f, c);

    // 计算三次样条的参数
    for (int i = 0; i < n - 1; ++i) {
        double ai = y[i];
        double bi = (y[i + 1] - y[i]) / h[i] - (h[i] * c[i] + h[i] * c[i + 1]) / 3.0;
        double ci = c[i];
        double di = (c[i + 1] - c[i]) / (3.0 * h[i]);
        m_params[i] = {ai, bi, ci, di};
    }
}

// 插值函数
double CubicSplineInterpolator::Interpolate(double x) const {
    int n = m_x.size();

    // 找到 x 所在的区间
    int i;
    for (i = 0; i < n - 1; ++i) {
        if (x <= m_x[i + 1])
            break;
    }

    // 边界情况
    if (i == n - 1) {
        return m_y[n - 1];
    } else if (i == 0) {
        double h = m_x[1] - m_x[0];
        double a = m_y[0];
        double b = (m_y[1] - m_y[0]) / h - h * m_params[0].c / 3.0 - h * m_params[0].d / 2.0;
        double c = m_params[0].c;
        double d = m_params[0].d / (3.0 * h);
        return a + b * (x - m_x[0]) + c * std::pow(x - m_x[0], 2.0) + d * std::pow(x - m_x[0], 3.0);
    }

    // 计算插值
    double h = x - m_x[i];
    double a = m_params[i - 1].a;
    double b = m_params[i - 1].b;
    double c = m_params[i - 1].c;
    double d = m_params[i - 1].d;
    return a + b * h + c * std::pow(h, 2.0) + d * std::pow(h, 3.0);
}

// 解三对角线性方程组
void CubicSplineInterpolator::tridiag(const std::vector<double> &sub, const std::vector<double> &diag,
                                      const std::vector<double> &sup, const std::vector<double> &b, std::vector<double> &x) {
    int n = sub.size();
    std::vector<double> sub_(n - 1), diag_(n), sup_(n - 1);
    std::vector<double> b_(n);

    sub_[0] = sub[0] / diag[0];
    diag_[0] = diag[0];
    for (int i = 1; i < n - 1; ++i) {
        sub_[i] = sub[i] / diag_[i - 1];
        diag_[i] = diag[i] - sub_[i] * sup[i - 1];
    }
    sup_[n - 2] = sup[n - 2] / diag_[n - 2];
    for (int i = n - 3; i >= 0; --i) {
        sup_[i] = sup[i] / diag_[i + 1];
    }

    b_[0] = b[0] / diag_[0];
    for (int i = 1; i < n; ++i) {
        b_[i] = (b[i] - sub_[i - 1] * b_[i - 1]) / diag_[i];
    }
    for (int i = n - 2; i >= 0; --i) {
        b_[i] -= sup_[i] * b_[i + 1];
    }

    x = b_;
}

int main() {
    // 数据点
    std::vector<double> x = {0.0, 0.2, 0.4, 0.6, 0.8, 1.0};
    std::vector<double> y = {0.0, 3.0, 1.5, 2.7, 2.0, 4.0};
    // 插值
    CubicSplineInterpolator interp(x, y);
    double x_new = 0.5;
    double y_new = interp.Interpolate(x_new);
    std::cout << "f(" << x_new << ") = " << y_new << std::endl;
    return 0;
}