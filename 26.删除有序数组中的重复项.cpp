/*
 * @Author: TwilightZrui 1193882630@qq.com
 * @Date: 2023-04-25 16:06:05
 * @LastEditors: TwilightZrui 1193882630@qq.com
 * @LastEditTime: 2023-04-25 17:33:40
 * @FilePath: /LeetCode/26.删除有序数组中的重复项.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
 */

// @lc code=start
class Solution {
  public:
    int removeDuplicates(vector<int> &nums) {
        int fast, slow;
        fast = slow = 1;
        int n = nums.size();
        if (n == 0)
            return 0;
        else {
            for (; fast < n; fast++)
                if (nums[fast] != nums[fast - 1]) {
                    nums[slow] = nums[fast];
                    slow++;
                }
        }
        return slow;
    }
};
// @lc code=end
