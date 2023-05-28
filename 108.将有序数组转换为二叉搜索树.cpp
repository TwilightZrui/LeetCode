// /*
//  * @lc app=leetcode.cn id=108 lang=cpp
//  *
//  * [108] 将有序数组转换为二叉搜索树
//  *
//  * https://leetcode.cn/problems/convert-sorted-array-to-binary-search-tree/description/
//  *
//  * algorithms
//  * Easy (77.38%)
//  * Likes:    1302
//  * Dislikes: 0
//  * Total Accepted:    354.9K
//  * Total Submissions: 458.5K
//  * Testcase Example:  '[-10,-3,0,5,9]'
//  *
//  * 给你一个整数数组 nums ，其中元素已经按 升序 排列，请你将其转换为一棵 高度平衡 二叉搜索树。
//  *
//  * 高度平衡 二叉树是一棵满足「每个节点的左右两个子树的高度差的绝对值不超过 1 」的二叉树。
//  *
//  *
//  *
//  * 示例 1：
//  *
//  *
//  * 输入：nums = [-10,-3,0,5,9]
//  * 输出：[0,-3,9,-10,null,5]
//  * 解释：[0,-10,5,null,-3,null,9] 也将被视为正确答案：
//  *
//  *
//  *
//  * 示例 2：
//  *
//  *
//  * 输入：nums = [1,3]
//  * 输出：[3,1]
//  * 解释：[1,null,3] 和 [3,1] 都是高度平衡二叉搜索树。
//  *
//  *
//  *
//  *
//  * 提示：
//  *
//  *
//  * 1 <= nums.length <= 10^4
//  * -10^4 <= nums[i] <= 10^4
//  * nums 按 严格递增 顺序排列
//  *
//  *
//  */

// // @lc code=stEart
// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */
// <<<<<<< HEAD
// class Solution
// {
// public:
//     TreeNode *sortedArrayToBST(vector<int> &nums)
//     {
//         return DFS(nums, 0, nums.size() - 1);
//     }
//     TreeNode *DFS(vector<int> &nums, int startIndex, int endIndex)
//     {
//         if (startIndex > endIndex)
//             return nullptr;
//         int mid = (startIndex + endIndex) / 2;
// =======
// class Solution {
//   public:
//     // TreeNode *sortedArrayToBST(vector<int> &nums) {
//     //     return DFS(nums, 0, nums.size() - 1);
//     // }
//     // TreeNode *DFS(vector<int> &nums, int startIndex, int endIndex) {
//     //     if (startIndex > endIndex)
//     //         return nullptr;
//     //     int mid = (startIndex + endIndex) / 2;
// >>>>>>> d221c2a399c34ecb71f7d062a6ba6350a15096a4

//     //     TreeNode *root = new TreeNode;
//     //     root->val = nums[mid];
//     //     root->left = DFS(nums, startIndex, mid - 1);
//     //     root->right = DFS(nums, mid + 1, endIndex);
//     //     return root;
//     // }

// <<<<<<< HEAD
//     TreeNode *sortedArrayToBST(vector<int> &nums)
//     {
//         if (nums.size() == 0)
//             return nullptr;
// =======
//     // TreeNode *sortedArrayToBST(vector<int> &nums) {
//     //     if (nums.size() == 0)
//     //         return nullptr;
// >>>>>>> d221c2a399c34ecb71f7d062a6ba6350a15096a4

//     //     int left = 0;
//     //     int right = nums.size() - 1;
//     //     int mid = (left + right) / 2;

//     //     stack<TreeNode *> stk;
//     //     TreeNode *root = new TreeNode(nums[mid]);
//     //     stk.push(root);

//     //     while (!q.empty()) {
//     //         auto temp = stk.top();
//     //         stk.pop();
//     //         while (left <= right) {
//     //             temp->left;
//     //         }
//     //     }
//     // }

// <<<<<<< HEAD
//         while (!q.empty())
//         {
//             auto temp = stk.top();
//             stk.pop();
//             while (left <= right)
//             {
//                 temp->left;
//             }
//         }
// =======
//     TreeNode *sortedArrayToBST(vector<int> &nums) {
//         return DFS(nums, 0, nums.size() - 1);
//     }
//     TreeNode *DFS(vector<int> &nums, int) {
//         int mid = nums.size() / 2;
//         TreeNode *root = new TreeNode(nums[mid]);
// >>>>>>> d221c2a399c34ecb71f7d062a6ba6350a15096a4
//     }
// };
// // @lc code=end
