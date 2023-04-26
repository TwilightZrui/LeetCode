/*
 * @Author: TwilightZrui 1193882630@qq.com
 * @Date: 2023-04-26 13:25:11
 * @LastEditors: TwilightZrui 1193882630@qq.com
 * @LastEditTime: 2023-04-26 13:37:47
 * @FilePath: /LeetCode/206.反转链表.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
  public:
    ListNode *reverseList(ListNode *head) {
        ListNode *current = head, prev = current->next;
        while (prev->next != nullptr) {
            prev.next = current;
            current++;
        }
        return
    }
};
// @lc code=end
