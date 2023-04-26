/*
 * @Author: TwilightZrui 1193882630@qq.com
 * @Date: 2023-04-25 11:52:02
 * @LastEditors: TwilightZrui 1193882630@qq.com
 * @LastEditTime: 2023-04-25 12:28:08
 * @FilePath: /LeetCode/14.最长公共前缀.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */

// @lc code=start
class Solution {
  public:
    string longestCommonPrefix(vector<string> &strs) {
        if (!strs.size())
            return "";
        string prefix = strs[0];
        for (int i = 1; i < strs.size(); i++) {
            prefix = longestCommonPrefix(prefix, strs[i]);
            if (!prefix.size())
                break;
        }

        return prefix;
    }
    string longestCommonPrefix(string &prefix, const string strs) {
        int index = 0;
        while ((index < min(prefix.size(), strs.size())) && (prefix[index] == strs[index])) {
            index++;
        }

        prefix = strs.substr(0, index);
        return prefix;
    }
};
// @lc code=end
