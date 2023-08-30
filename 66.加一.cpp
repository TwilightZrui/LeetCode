/*
 * @Author: TwilightZrui 1193882630@qq.com
 * @Date: 2023-04-25 22:17:35
 * @LastEditors: TwilightZrui 1193882630@qq.com
 * @LastEditTime: 2023-04-25 22:45:58
 * @FilePath: /LeetCode/66.加一.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=66 lang=cpp
 *
 * [66] 加一
 */

// @lc code=start
class Solution {
  public:
    vector<int> plusOne(vector<int> &digits) {
        int len = digits.size();
        int index = len - 1;
        for (int i = len - 1; i >= 0; i--) {
            if (digits[i] != 9) {
                digits[i]++;
                for (int j = i + 1; j < len; j++) {
                    digits[j] = 0;
                }
                return digits;
            }
        }

        vector<int> ans(len + 1, 0);
        ans[0] = 1;
        return ans;
    }
};
// @lc code=end
