// Given a binary tree, return all root-to-leaf paths.
//
// Note: A leaf is a node with no children.
//
// Example:
//
//
// Input:
//
//    1
//  /   \
// 2     3
//  \
//   5
//
// Output: ["1->2->5", "1->3"]
//
// Explanation: All root-to-leaf paths are: 1->2->5, 1->3
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
    vector<string> binaryTreePaths(TreeNode* root) {
        /*
        vector<string> ans;
        if(!root) return ans;
        if(root->left==NULL && root->right==NULL) {
            ans.push_back(to_string(root->val));
            return ans;
        }
        vector<string> left_str;
        vector<string> right_str;
        if(root->left) left_str = binaryTreePaths(root->left);
        if(root->right) right_str = binaryTreePaths(root->right);
        
        string root_str = to_string(root->val) + "->";
        for(int i = 0; i < left_str.size(); ++i) {ans.push_back(root_str + left_str[i]);}
        for(int i = 0; i < right_str.size(); ++i) {ans.push_back(root_str + right_str[i]);}
        return ans;*/
        
        vector<string> ans;
        if(!root) return ans;
        string tmp;
        helper(root,ans,tmp);
        return ans;
    }
    
    void helper(TreeNode* root, vector<string> &ans, string tmp) {
        if(!root->left && !root->right) {
            tmp += to_string(root->val);
            ans.push_back(tmp);
        }
        tmp += to_string(root->val)+"->";
        if(root->left) helper(root->left,ans,tmp);
        if(root->right) helper(root->right,ans,tmp);
    }
};
