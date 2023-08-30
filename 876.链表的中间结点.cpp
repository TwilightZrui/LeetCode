/*
 * @Author: TwilightZrui
 * @Date: 2023-05-13 16:42:47
 */
/*
 * @lc app=leetcode.cn id=876 lang=cpp
 *
 * [876] 链表的中间结点
 *
 * https://leetcode.cn/problems/middle-of-the-linked-list/description/
 *
 * algorithms
 * Easy (70.22%)
 * Likes:    885
 * Dislikes: 0
 * Total Accepted:    391K
 * Total Submissions: 557K
 * Testcase Example:  '[1,2,3,4,5]'
 *
 * 给你单链表的头结点 head ，请你找出并返回链表的中间结点。
 *
 * 如果有两个中间结点，则返回第二个中间结点。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：head = [1,2,3,4,5]
 * 输出：[3,4,5]
 * 解释：链表只有一个中间结点，值为 3 。
 *
 *
 * 示例 2：
 *
 *
 * 输入：head = [1,2,3,4,5,6]
 * 输出：[4,5,6]
 * 解释：该链表有两个中间结点，值分别为 3 和 4 ，返回第二个结点。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 链表的结点数范围是 [1, 100]
 * 1 <= Node.val <= 100
 *
 *
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
    // array
    // ListNode *middleNode(ListNode *head) {
    //     if (head == nullptr)
    //         return nullptr;
    //     vector<ListNode *> vec;
    //     while (head != nullptr) {
    //         vec.push_back(head);
    //         head = head->next;
    //     }
    //     return vec[vec.size() / 2];
    // }

    // single ptr
    // ListNode *middleNode(ListNode *head) {
    //     int sz = 0;
    //     ListNode *cur = head;
    //     while (cur != nullptr) {
    //         sz++;
    //         cur = cur->next;
    //     }
    //     cout << "sz = " << sz << endl;
    //     ListNode *cur2 = head;
    //     for (int i = 0; i < sz / 2; i++) {
    //         cur2 = cur2->next;
    //         cout << "conunt" << cur2->val << endl;
    //     }
    //     return cur2;
    // }

    // fast slow ptr
    ListNode *middleNode(ListNode *head) {
        ListNode *fast = head;
        ListNode *slow = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};
// @lc code=end
