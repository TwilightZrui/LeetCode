/*
 * @Author: TwilightZrui
 * @Date: 2023-05-13 16:05:33
 */
/*
 * @lc app=leetcode.cn id=109 lang=cpp
 *
 * [109] 有序链表转换二叉搜索树
 *
 * https://leetcode.cn/problems/convert-sorted-list-to-binary-search-tree/description/
 *
 * algorithms
 * Medium (76.46%)
 * Likes:    826
 * Dislikes: 0
 * Total Accepted:    144.9K
 * Total Submissions: 189.5K
 * Testcase Example:  '[-10,-3,0,5,9]'
 *
 * 给定一个单链表的头节点  head ，其中的元素 按升序排序 ，将其转换为高度平衡的二叉搜索树。
 *
 * 本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差不超过 1。
 *
 *
 *
 * 示例 1:
 *
 *
 *
 *
 * 输入: head = [-10,-3,0,5,9]
 * 输出: [0,-3,9,-10,null,5]
 * 解释: 一个可能的答案是[0，-3,9，-10,null,5]，它表示所示的高度平衡的二叉搜索树。
 *
 *
 * 示例 2:
 *
 *
 * 输入: head = []
 * 输出: []
 *
 *
 *
 *
 * 提示:
 *
 *
 * head 中的节点数在[0, 2 * 10^4] 范围内
 * -10^5 <= Node.val <= 10^5
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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
  public:
    // to array
    // TreeNode *sortedListToBST(ListNode *head) {
    //     vector<int> sortedVector;
    //     ListNode *listPtr = head;
    //     while (listPtr != nullptr) {
    //         listPtr = head->next;
    //         sortedVector.push_back(head->val);
    //         cout << "head->val:" << head->val << endl;
    //         head = listPtr;
    //     }

    //     return DFS(sortedVector, 0, sortedVector.size() - 1);
    // }
    // TreeNode *DFS(vector<int> &nums, int left, int right) {
    //     if (left > right)
    //         return nullptr;
    //     int mid = (left + right) / 2;
    //     TreeNode *root = new TreeNode(nums[mid]);
    //     root->left = DFS(nums, left, mid - 1);
    //     root->right = DFS(nums, mid + 1, right);
    //     return root;
    // }
    TreeNode *sortedListToBST(ListNode *head) {
        if (head == nullptr)
            return nullptr;
        if (head->next == nullptr)
            return new TreeNode(head->val);
        ListNode *midPre = getMidLideNode(head);
        TreeNode *root = new TreeNode(midPre->next->val);
        root->right = sortedListToBST(midPre->next->next);
        midPre->next = nullptr;
        root->left = sortedListToBST(head);
        return root;
    }

    ListNode *getMidLideNode(ListNode *head) {
        if (head == nullptr)
            return nullptr;
        ListNode *fast = head;
        ListNode *slow = head;
        ListNode *pre = head;
        while (fast != nullptr && fast->next != nullptr) {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        return pre;
    }
};
// @lc code=end
