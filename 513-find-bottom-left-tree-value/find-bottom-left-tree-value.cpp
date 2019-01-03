//
// Given a binary tree, find the leftmost value in the last row of the tree. 
//
//
// Example 1:
//
// Input:
//
//     2
//    / \
//   1   3
//
// Output:
// 1
//
//
//
//   Example 2: 
//
// Input:
//
//         1
//        / \
//       2   3
//      /   / \
//     4   5   6
//        /
//       7
//
// Output:
// 7
//
//
//
// Note:
// You may assume the tree (i.e., the given root node) is not NULL.
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
    int findBottomLeftValue(TreeNode* root) {
        int height=0;
        int ans=root->val;
        dfs(root,0,height,ans);
        return ans;
    }
    void dfs(TreeNode*root,int depth,int& height,int& ans){
        if(root==NULL) return;
        if(depth>height){height=depth;ans=root->val;}
        dfs(root->left,depth+1,height,ans);
        dfs(root->right,depth+1,height,ans);
    }
};
