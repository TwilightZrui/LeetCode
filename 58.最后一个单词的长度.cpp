/*
 * @Author: TwilightZrui 1193882630@qq.com
 * @Date: 2023-04-25 19:05:28
 * @LastEditors: TwilightZrui 1193882630@qq.com
 * @LastEditTime: 2023-04-25 22:13:55
 * @FilePath: /LeetCode/58.最后一个单词的长度.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=58 lang=cpp
 *
 * [58] 最后一个单词的长度
 */

// @lc code=start
class Solution {
  public:
    int lengthOfLastWord(string s) {
        int len = s.length();
        int index = len - 1;
        while (s[index] == ' ')
            index--;
        int wordLength = 0;
        while (index >= 0 && s[index] != ' ') {
            wordLength++;
            index--;
        }

        return wordLength;
    }
};
// @lc code=end
