#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <climits>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <bits/stdc++.h>
#include <queue>
#include <string>
#include <cstring>
using namespace std;
int countSubstring(const std::string& str, const std::string& sub) {
    int count = 0;
    size_t pos = 0;
    while ((pos = str.find(sub, pos)) != std::string::npos) { //find函数来查找子字符串在原字符串中的位置
        count++;//如果找到了子字符串，则将计数器加一
        pos += sub.length(); //将起始搜索位置更新为子字符串后的位置，继续寻找下一个匹配
    }
    return count;
}
std::string reverseString(const std::string& str) {//反转字符串
    std::string reversedStr = str;
    size_t left = 0;
    size_t right = str.length() - 1;
    while (left < right) {
        std::swap(reversedStr[left], reversedStr[right]);
        left++;
        right--;
    }
    return reversedStr;
}
int main() {
    std::string str;
    std::cout << "input: ";
    std::getline(std::cin, str);
    std::string sub;
    std::cout << "sub: ";
    std::getline(std::cin, sub);
    int count = countSubstring(str, sub);
    std::cout << "num: " << count << std::endl;

    if (count % 2 == 1) { //如果个数是奇数个，则将将子字符串颠倒放回
        std::string reversedSub = reverseString(sub);
        size_t pos = str.find(sub);
        while (pos != std::string::npos) { //
            str.replace(pos, sub.length(), reversedSub);
            pos = str.find(sub, pos + reversedSub.length());
        }
        std::cout << "inverse: " << str << std::endl;
    }else { //若偶数个则删去子字符串
        std::string::size_type pos;
        while ((pos = str.find(sub)) != std::string::npos) {
            str.erase(pos, sub.length()); //将子字符串在原字符串中的所有位置都删除
        }
        std::cout << "delete: " << str << std::endl; //输出删去子字符串后的字符串。
    }
    return 0;
}


// 题目的三个功能：
// 1.是否包含指定子字符串。如包含，输出包含的个数。
// 2.如果个数是奇数个，则将将子字符串颠倒放回；
// 3.若偶数个则删去子字符串

// 思路：
// 功能1：是否包含指定子字符串。如包含，输出包含的个数。
// 使用std::string::find函数来查找子字符串在原字符串中的位置。如果找到了子字符串，则将计数器加一，并将起始搜索位置更新为子字符串后的位置，继续寻找下一个匹配。如果没有找到子字符串，则返回std::string::npos，循环结束。最后输出计数器的值作为包含的个数。

// 功能2：如果个数是奇数个，则将将子字符串颠倒放回；
// 在计算子字符串个数后，根据结果进行判断。
// 如果个数为奇数，通过std::string::replace函数将原字符串中的子字符串替换为颠倒后的字符串。然后继续查找下一个子字符串，直到所有子字符串都被替换完毕。这样，就能实现将颠倒后的字符串放回原字符串中。

// 功能3：若偶数个则删去子字符串

// 如果个数为偶数，则使用std::string::erase函数将子字符串在原字符串中的所有位置都删除，输出删去子字符串后的字符串。

