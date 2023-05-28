/*
 * @Author: TwilightZrui
 * @Date: 2023-05-20 23:25:10
 */
/*
 * @lc app=leetcode.cn id=125 lang=cpp
 *
 * [125] 验证回文串
 *
 * https://leetcode.cn/problems/valid-palindrome/description/
 *
 * algorithms
 * Easy (46.45%)
 * Likes:    636
 * Dislikes: 0
 * Total Accepted:    469K
 * Total Submissions: 1M
 * Testcase Example:  '"A man, a plan, a canal: Panama"'
 *
 * 如果在将所有大写字符转换为小写字符、并移除所有非字母数字字符之后，短语正着读和反着读都一样。则可以认为该短语是一个 回文串 。
 *
 * 字母和数字都属于字母数字字符。
 *
 * 给你一个字符串 s，如果它是 回文串 ，返回 true ；否则，返回 false 。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入: s = "A man, a plan, a canal: Panama"
 * 输出：true
 * 解释："amanaplanacanalpanama" 是回文串。
 *
 *
 * 示例 2：
 *
 *
 * 输入：s = "race a car"
 * 输出：false
 * 解释："raceacar" 不是回文串。
 *
 *
 * 示例 3：
 *
 *
 * 输入：s = " "
 * 输出：true
 * 解释：在移除非字母数字字符之后，s 是一个空字符串 "" 。
 * 由于空字符串正着反着读都一样，所以是回文串。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= s.length <= 2 * 10^5
 * s 仅由可打印的 ASCII 字符组成
 *
 *
 */

// @lc code=start
class Solution {
  public:
    // // 筛选+判断
    // bool isPalindrome(string s) {
    //     string s1;
    //     for (const auto &ch : s) {
    //         if (isalnum(ch))
    //             s1 += tolower(ch);
    //     }
    //     string s2(s1.size(), ' ');
    //     reverse_copy(s1.begin(), s1.end(), s2.begin());

    //     return s2 == s1;
    // }

    // 双指针
    bool isPalindrome(string s) {
        string s1;
        for (const auto &ch : s) {
            if (isalnum(ch))
                s1 += tolower(ch);
        }

        int sz = s1.size();
        int left = 0, right = sz - 1;
        while (left < right) {
            if (s1[left] != s1[right])
                return false;
            else {
                left++;
                right--;
            }
        }
        return true;
    }
};
// @lc code=end
