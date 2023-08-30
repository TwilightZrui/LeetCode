/*
 * @Author: TwilightZrui 1193882630@qq.com
 * @Date: 2023-04-23 11:37:41
 * @LastEditors: TwilightZrui 1193882630@qq.com
 * @LastEditTime: 2023-04-23 12:10:19
 * @FilePath: /LeetCode/394.字符串解码.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=394 lang=cpp
 *
 * [394] 字符串解码
 */
#include <iostream>
#include <stack>
#include <string>
using namespace std;
// @lc code=start
class Solution {
  public:
    string src;
    size_t ptr;

    int getDigits() {
        int ret = 0;
        while (ptr < src.size() && isdigit(src[ptr])) {
            ret = ret * 10 + src[ptr++] - '0';
        }
        return ret;
    }

    string getString() {
        if (ptr == src.size() || src[ptr] == ']') {
            // String -> EPS
            return "";
        }

        char cur = src[ptr];
        int repTime = 1;
        string ret;

        if (isdigit(cur)) {
            // String -> Digits [ String ] String
            // 解析 Digits
            repTime = getDigits();
            // 过滤左括号
            ++ptr;
            // 解析 String
            string str = getString();
            // 过滤右括号
            ++ptr;
            // 构造字符串
            while (repTime--)
                ret += str;
        } else if (isalpha(cur)) {
            // String -> Char String
            // 解析 Char
            ret = string(1, src[ptr++]);
        }

        return ret + getString();
    }

    string decodeString(string s) {
        src = s;
        ptr = 0;
        return getString();
    }
};
// @lc code=end
