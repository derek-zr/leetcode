// Given a binary tree, find the length of the longest path where each node in the path has the same value. This path may or may not pass through the root.
//
// The length of path between two nodes is represented by the number of edges between them.
//
//  
//
// Example 1:
//
// Input:
//
//
//               5
//              / \
//             4   5
//            / \   \
//           1   1   5
//
//
// Output: 2
//
//  
//
// Example 2:
//
// Input:
//
//
//               1
//              / \
//             4   5
//            / \   \
//           4   4   5
//
//
// Output: 2
//
//  
//
// Note: The given binary tree has not more than 10000 nodes. The height of the tree is not more than 1000.
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
    int longestUnivaluePath(TreeNode* root) {
        int longpath = 0;
        if(root==NULL) return 0;
        dfs(root,longpath);
        return longpath;
    }
    
    int dfs(TreeNode* root, int& longpath){
        int left = root->left? dfs(root->left,longpath):0;
        int right = root->right? dfs(root->right,longpath):0;
        int realleft = root->left && root->left->val==root->val ? left+1 : 0;
        int realright = root->right && root->right->val==root->val ? right+1 : 0;
        longpath = max(longpath,realleft+realright);
        return max(realleft,realright);
    }
};
