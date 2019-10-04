// Given a Binary Search Tree and a target number, return true if there exist two elements in the BST such that their sum is equal to the given target.
//
// Example 1:
//
//
// Input: 
//     5
//    / \
//   3   6
//  / \   \
// 2   4   7
//
// Target = 9
//
// Output: True
//
//
//  
//
// Example 2:
//
//
// Input: 
//     5
//    / \
//   3   6
//  / \   \
// 2   4   7
//
// Target = 28
//
// Output: False
//
//
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
    bool findTarget(TreeNode* root, int k) {
        if(root==NULL) return false;
        unordered_set<int> values;
        return helper(values,root,k);
    }
    
    bool helper(unordered_set<int>& values,TreeNode* root,int k){
        if(root==NULL) return false;
        if(values.count(k-root->val)) return true;
        values.insert(root->val);
        return helper(values,root->left,k)||helper(values,root->right,k);
    }
};
