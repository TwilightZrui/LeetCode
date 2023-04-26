/*
 * @Author: TwilightZrui 1193882630@qq.com
 * @Date: 2023-04-25 12:31:23
 * @LastEditors: TwilightZrui 1193882630@qq.com
 * @LastEditTime: 2023-04-25 14:13:33
 * @FilePath: /LeetCode/20.有效的括号.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
class Solution {
  private:
    unordered_map<char, char> table = {
        {')', '('},
        {']', '['},
        {'}', '{'},
    };

  public:
    bool isValid(string s) {
        if (s.length() % 2 == 1)
            return false;
        stack<char> stk;
        for (const auto &num : s) {
            if (table.count(num)) {
                if (stk.empty() || table[num] != stk.top()) {
                    return false;
                }
                stk.pop();
            } else
                stk.push(num);
            cout << "stk:" << endl;
            for (const auto &temp : stk) {
                cout << temp << endl;
            }
        }
        return stk.empty();
    }
};
// @lc code=end
