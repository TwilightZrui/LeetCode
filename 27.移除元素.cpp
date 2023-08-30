/*
 * @Author: TwilightZrui 1193882630@qq.com
 * @Date: 2023-04-25 17:42:43
 * @LastEditors: TwilightZrui 1193882630@qq.com
 * @LastEditTime: 2023-04-25 17:55:33
 * @FilePath: /LeetCode/27.移除元素.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

// @lc code=start
class Solution {
  public:
    int removeElement(vector<int> &nums, int val) {
        int n = nums.size();
        int fast, slow;
        fast = slow = 0;
        if (n == 0)
            return 0;
        else {
            for (; fast < n; fast++) {
                if (nums[fast] != val) {
                    nums[slow] = nums[fast];
                    slow++;
                }
            }
        }
        return slow;
    }
};
// @lc code=end
