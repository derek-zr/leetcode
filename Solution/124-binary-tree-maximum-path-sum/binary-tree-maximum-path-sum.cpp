// Given a non-empty binary tree, find the maximum path sum.
//
// For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path must contain at least one node and does not need to go through the root.
//
// Example 1:
//
//
// Input: [1,2,3]
//
//        1
//       / \
//      2   3
//
// Output: 6
//
//
// Example 2:
//
//
// Input: [-10,9,20,null,null,15,7]
//
//    -10
//    / \
//   9  20
//     /  \
//    15   7
//
// Output: 42
//
//


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int ans  = INT_MIN;
        dfs(root, ans);
        return ans;
    }
    
    int dfs(TreeNode* root, int& ans) {
        if(root == NULL) return 0;
        int left_sum =  max(0, dfs(root->left, ans));
        int right_sum =  max(0, dfs(root->right, ans));
        ans = max(ans, left_sum + right_sum + root->val);  //要考虑不经过顶层根节点的情况
        return max(left_sum, right_sum) + root->val;   //回溯到上层根节点时，只能选择左右子树中的一个
    }
};
