// Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).
//
//
// For example:
// Given binary tree [3,9,20,null,null,15,7],
//
//     3
//    / \
//   9  20
//     /  \
//    15   7
//
//
//
// return its bottom-up level order traversal as:
//
// [
//   [15,7],
//   [9,20],
//   [3]
// ]
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
    //dfs
    void dfs(vector<vector<int>> & ans,int depth,TreeNode* root){
        if(root==NULL) return;
        if(depth>=ans.size()) ans.push_back({});  //插入新一层的数组
        ans[depth].push_back(root->val);
        dfs(ans,depth+1,root->left);
        dfs(ans,depth+1,root->right);

    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        dfs(ans,0,root);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
