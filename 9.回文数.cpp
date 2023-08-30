/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

// @lc code=start
class Solution {
  public:
    bool isPalindrome(int x) {

        int invert = 0;
        if (x < 0 || (x % 10 == 0 && x != 0))
            return false;
        else {
            while (x > invert) {
                invert = invert * 10 + x % 10;
                x /= 10;
            }
        }

        return x == invert || x == invert / 10;
    }
};
// @lc code=end
