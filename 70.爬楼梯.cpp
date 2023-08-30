/*
 * @Author: TwilightZrui 1193882630@qq.com18: error: bracket
 * @Date: 2023-04-25 23:48:09
 * @LastEditors: TwilightZrui 1193882630@qq.com
 * @LastEditTime: 2023-04-26 10:53:09
 * @FilePath: /LeetCode/70.爬楼梯.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
// 1
// class Solution {
//   public:
//     int climbStairs(int n) {
//         if (n <= 2) {
//             return n;
//         }

//         int *dp = new int[n + 1];
//         dp[0] = 0;
//         dp[1] = 1;
//         dp[2] = 2;

//         for (int i = 3; i <= n; i++)
//             dp[i] = dp[i - 1] + dp[i - 2];

//         int result = dp[n];
//         delete[] dp;
//         return result;
//     }
// };
// 2
class Solution {
  public:
    int climbStairs(int n) {
        if (n <= 2) {
            return n;
        }

        int *dp = new int[4];
        dp[2] = 2;
        dp[0] = 0;
        dp[1] = 1;

        for (int i = 3; i <= n; i++) {
            dp[3] = dp[2] + dp[1];
            dp[1] = dp[2];
            dp[2] = dp[3];
        }

        int result = dp[3];
        delete[] dp;
        return result;
    }
};

// @lc code=end
