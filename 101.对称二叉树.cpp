/*
 * @Author: TwilightZrui
 * @Date: 2023-05-12 22:19:29
 */
/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
 *
 * https://leetcode.cn/problems/symmetric-tree/description/
 *
 * algorithms
 * Easy (58.71%)
 * Likes:    2421
 * Dislikes: 0
 * Total Accepted:    826.4K
 * Total Submissions: 1.4M
 * Testcase Example:  '[1,2,2,3,4,4,3]'
 *
 * 给你一个二叉树的根节点 root ， 检查它是否轴对称。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：root = [1,2,2,3,4,4,3]
 * 输出：true
 *
 *
 * 示例 2：
 *
 *
 * 输入：root = [1,2,2,null,3,null,3]
 * 输出：false
 *
 *
 *
 *
 * 提示：
 *
 *
 * 树中节点数目在范围 [1, 1000] 内
 * -100 <= Node.val <= 100
 *
 *
 *
 *
 * 进阶：你可以运用递归和迭代两种方法解决这个问题吗？
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
    // 递归
    // bool isSymmetric(TreeNode *root) {
    //     return check(root, root);
    // }
    // bool check(TreeNode *l, TreeNode *r) {
    //     if (l == nullptr)
    //         return r == nullptr;
    //     return r != nullptr && l->val == r->val && check(l->left, r->right) && check(l->right, r->left);
    // }
    //  迭代

    // bool isSymmetric(TreeNode *root) {
    //     if (root == nullptr)
    //         return true;
    //     if ((root->left == nullptr || root->right == nullptr) && (root->left != nullptr && root->right != nullptr))
    //         return false;
    //     queue<TreeNode *> q;
    //     q.push(root->left);
    //     q.push(root->right);
    //     while (!q.empty()) {
    //         auto l1 = q.front();
    //         q.pop();
    //         auto l2 = q.front();
    //         q.pop();
    //         if (l1 == nullptr && l2 == nullptr)
    //             continue;
    //         if (l1 == nullptr || l2 == nullptr)
    //             return false;
    //         if (l1->val != l2->val)
    //             return false;
    //         q.push(l1->left);
    //         q.push(l2->right);
    //         q.push(l1->right);
    //         q.push(l2->left);
    //     }
    //     return true;
    //     // return check(root, root);
    // }

    // 递归
    bool isSymmetric(TreeNode *root) {
        if (root == nullptr)
            return true;
        return check(root->left, root->right);
    }
    bool check(TreeNode *left, TreeNode *right) {
        if ((left == nullptr) && (right == nullptr))
            return true;
        if ((left != nullptr) ^ (right != nullptr))
            return false;
        if (left->val == right->val)
            return (check(left->left, right->right) && check(left->right, right->left));
        else
            return false;
    }

    // // 迭代
    // bool isSymmetric(TreeNode *root) {
    //     if (root == nullptr)
    //         return true;

    //     queue<TreeNode *> q;
    //     q.push(root);
    //     q.push(root);
    //     while (!q.empty()) {
    //         auto left = q.front();
    //         q.pop();
    //         auto right = q.front();
    //         q.pop();
    //         if ((left == nullptr) && (right == nullptr))
    //             continue; // important
    //         if ((left == nullptr) ^ (right == nullptr))
    //             return false;
    //         if (left->val != right->val)
    //             return false;
    //         q.push(left->left);
    //         q.push(right->right);
    //         q.push(left->right);
    //         q.push(right->left);
    //     }
    //     return q.empty();
    // }
};
// @lc code=end
