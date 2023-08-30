/*
 * @Author: TwilightZrui
 * @Date: 2023-05-13 00:34:19
 */
/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
 *
 * https://leetcode.cn/problems/maximum-depth-of-binary-tree/description/
 *
 * algorithms
 * Easy (77.11%)
 * Likes:    1605
 * Dislikes: 0
 * Total Accepted:    1M
 * Total Submissions: 1.3M
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定一个二叉树，找出其最大深度。
 *
 * 二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。
 *
 * 说明: 叶子节点是指没有子节点的节点。
 *
 * 示例：
 * 给定二叉树 [3,9,20,null,null,15,7]，
 *
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 *
 * 返回它的最大深度 3 。
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
    // dfs
    // int maxDepth(TreeNode *root) {
    //     return root == nullptr ? 0 : max(maxDepth(root->left), maxDepth(root->right)) + 1;
    // }

    // // bfs
    // int maxDepth(TreeNode *root) {
    //     if (root == nullptr)
    //         return 0;
    //     queue<TreeNode *> q;
    //     int depth = 0;
    //     q.push(root);
    //     while (!q.empty()) {
    //         int length = q.size();
    //         while (length > 0) {
    //             root = q.front();
    //             q.pop();
    //             if (root->left != nullptr)
    //                 q.push(root->left);
    //             if (root->right != nullptr)
    //                 q.push(root->right);
    //             length -= 1;
    //         }
    //         depth++;
    //     }
    //     return depth;
    // }

    // // dfs
    // int maxDepth(TreeNode *root) {
    //     if (root == nullptr)
    //         return 0;
    //     return (max(maxDepth(root->left), maxDepth(root->right)) + 1);
    // }

    // bfs
    int maxDepth(TreeNode *root) {
        if (root == nullptr)
            return 0;
        queue<TreeNode *> q;
        q.push(root);
        int depth = 0;
        while (!q.empty()) {
            int sz = q.size();
            while (sz > 0) {
                TreeNode *cur = q.front();
                q.pop();
                if (cur->left != nullptr)
                    q.push(cur->left);
                if (cur->right != nullptr)
                    q.push(cur->right);
                sz--;
            }
            depth++;
        }
        return depth;
    }
};
// @lc code=end
