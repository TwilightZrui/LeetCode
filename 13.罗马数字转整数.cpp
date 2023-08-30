/*
 * @Author: TwilightZrui 1193882630@qq.com
 * @Date: 2023-04-24 22:04:01
 * @LastEditors: TwilightZrui 1193882630@qq.com
 * @LastEditTime: 2023-04-25 11:48:36
 * @FilePath: /LeetCode/13.罗马数字转整数.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 */

// @lc code=start
using namespace std;
class Solution {
  private:
    unordered_map<char, int> table = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000},
    };

  public:
    int romanToInt(string s) {
        int a = s.length();
        int sum = 0;
        for (int i = 0; i < a; i++) {
            if (i < a - 1 && table[s[i]] < table[s[i + 1]]) {
                sum -= table[s[i]];
            } else {
                sum += table[s[i]];
            }
        }
        return sum;
    }
};
// @lc code=end
