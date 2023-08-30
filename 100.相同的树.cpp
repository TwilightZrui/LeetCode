/*
 * @Author: TwilightZrui
 * @Date: 2023-05-12 20:59:06
 */
/*
 * @lc app=leetcode.cn id=100 lang=cpp
 *
 * [100] 相同的树
 *
 * https://leetcode.cn/problems/same-tree/description/
 *
 * algorithms
 * Easy (59.90%)
 * Likes:    1016
 * Dislikes: 0
 * Total Accepted:    453.6K
 * Total Submissions: 757K
 * Testcase Example:  '[1,2,3]\n[1,2,3]'
 *
 * 给你两棵二叉树的根节点 p 和 q ，编写一个函数来检验这两棵树是否相同。
 *
 * 如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：p = [1,2,3], q = [1,2,3]
 * 输出：true
 *
 *
 * 示例 2：
 *
 *
 * 输入：p = [1,2], q = [1,null,2]
 * 输出：false
 *
 *
 * 示例 3：
 *
 *
 * 输入：p = [1,2,1], q = [1,1,2]
 * 输出：false
 *
 *
 *
 *
 * 提示：
 *
 *
 * 两棵树上的节点数目都在范围 [0, 100] 内
 * -10^4
 *
 *
 */

// @lc code=start
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
    // // BFS
    // bool isSameTree(TreeNode *p, TreeNode *q) {
    //     if (p == nullptr && q == nullptr)
    //         return true;
    //     if ((p == nullptr) ^ (q == nullptr))
    //         return false;

    //     queue<TreeNode *> leftq, rightq;
    //     leftq.push(p);
    //     rightq.push(q);
    //     while ((!leftq.empty()) && (!rightq.empty())) {
    //         TreeNode *left = leftq.front();
    //         leftq.pop();
    //         TreeNode *right = rightq.front();
    //         rightq.pop();
    //         if (left->val != right->val)
    //             return false;

    //         TreeNode *left1 = left->left, *right1 = left->right;
    //         TreeNode *left2 = right->left, *right2 = right->right;

    //         if ((left1 == nullptr) ^ (left2 == nullptr))
    //             return false;
    //         if ((right1 == nullptr) ^ (right2 == nullptr))
    //             return false;
    //         if (left1 != nullptr)
    //             leftq.push(left1);
    //         if (right1 != nullptr)
    //             leftq.push(right1);

    //         if (left2 != nullptr)
    //             rightq.push(left2);
    //         if (right2 != nullptr)
    //             rightq.push(right2);
    //     }

    //     return (leftq.empty() && rightq.empty());
    // }
    // DFS
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if (p == nullptr)
            return (q == nullptr);
        if ((p == nullptr) ^ (q == nullptr))
            return false;
        if ((q != nullptr) && (p != nullptr)) {
            if (p->val == q->val) {
                return (isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
            } else
                return false;
        }
        return true;
        // return q != nullptr && p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
// @lc code=end
