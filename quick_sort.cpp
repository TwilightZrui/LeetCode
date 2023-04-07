/*
 * @Author: TwilightZrui 1193882630@qq.com
 * @Date: 2023-04-07 11:46:33
 * @LastEditors: TwilightZrui 1193882630@qq.com
 * @LastEditTime: 2023-04-07 14:56:51
 * @FilePath: /LeetCode/quick_sort.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "iostream"
#include "vector"
using namespace std;
// template <typename T>
// void quick_sort_recursive(T arr[], int start, int end) {
//     if (start >= end)
//         return;
//     T mid = arr[end];
//     int left = start, right = end - 1;
//     while (left < right) {
//         while (arr[left] < mid && left < right)
//             left++;
//         while (arr[right] >= mid && left < right)
//             right--;
//         std::swap(arr[left], arr[right]);
//     }
//     if (arr[left] >= arr[end])
//         std::swap(arr[left], arr[end]);
//     else
//         left++;
//     quick_sort_recursive(arr, start, left - 1);
//     quick_sort_recursive(arr, left + 1, end);
// }
struct RegionInfo {
    const double *ptr{nullptr};
    double cost = 0;
};

void quick_sort_recursive(std::vector<RegionInfo> &arr, int start, int end) {
    if (start >= end)
        return;
    double mid = arr[end].cost;
    int left = start, right = end - 1;
    while (left < right) {
        while (arr[left].cost < mid && left < right)
            left++;
        while (arr[right].cost >= mid && left < right)
            right--;
        std::swap(arr[left], arr[right]);
    }
    if (arr[left].cost >= arr[end].cost)
        std::swap(arr[left], arr[end]);
    else
        left++;
    quick_sort_recursive(arr, start, left - 1);
    quick_sort_recursive(arr, left + 1, end);
}

void quick_sort(std::vector<RegionInfo> &arr, int len) {
    quick_sort_recursive(arr, 0, len - 1);
}

int main() {
    double array1[10] = {0, 10, 20, 30, 40, 50, 60, 70, 80, 90};
    double array2[10] = {3, 7, 2, 8, 9, 6, 1, 5, 4, 0};
    std::vector<RegionInfo> regionInfoStream;
    regionInfoStream.reserve(10);
    for (int i = 0; i < 10; i++) {
        RegionInfo regionInfoTemp;
        regionInfoTemp.ptr = &array1[i];
        regionInfoTemp.cost = array2[i];
        regionInfoStream.push_back(regionInfoTemp);
        // cout << "regionInfoTemp: " << *regionInfoTemp.ptr << "," << regionInfoTemp.cost << endl;
        // cout << "regionInfoStream: " << *regionInfoStream[i].ptr << "," << regionInfoStream[i].cost << endl;
    }
    quick_sort(regionInfoStream, 10);
    for (int i = 0; i < 10; i++) {
        cout << "regionInfoStream: " << *regionInfoStream[i].ptr << "," << regionInfoStream[i].cost << endl;
    }
}