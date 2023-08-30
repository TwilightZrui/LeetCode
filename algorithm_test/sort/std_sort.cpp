/*
 * @Author: TwilightZrui 1193882630@qq.com
 * @Date: 2023-04-11 15:00:23
 * @LastEditors: TwilightZrui 1193882630@qq.com
 * @LastEditTime: 2023-04-11 18:50:02
 * @FilePath: /LeetCode/std_sort.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <functional>
#include <iostream>

#include <algorithm>
#include <vector>
using namespace std;
int main() {
    std::vector<double> x{0.31, 0.11, 0, 1.34, 4.33, -0.32, -1.65, 2, 49};
    std::sort(x.begin(), x.end(), [](const double &lhs, const double &rhs) {
        return lhs < rhs;
    });
    // for (int i = 0; i < x.size(); i++) {
    //     std::cout << x[i] << std::endl;
    // }
    auto max1 = std::max_element(x.begin(), x.end());
    cout << *max1 << endl;
}