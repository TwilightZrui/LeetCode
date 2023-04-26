/*
 * @Author: TwilightZrui 1193882630@qq.com
 * @Date: 2023-04-25 17:56:43
 * @LastEditors: TwilightZrui 1193882630@qq.com
 * @LastEditTime: 2023-04-25 19:02:12
 * @FilePath: /LeetCode/35.搜索插入位置.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 */

// @lc code=start
class Solution {
  public:
    int searchInsert(vector<int> &nums, int target) {
        int n = nums.size();
        int left = 0, right = n - 1, mid = 0, ans = n;
        while (left <= right) {
            mid = ((right - left) / 2) + left;
            if (target <= nums[mid]) {
                ans = mid;
                right = mid - 1;
            } else
                left = mid + 1;
        }
        return ans;
    }
};
// @lc code=end
