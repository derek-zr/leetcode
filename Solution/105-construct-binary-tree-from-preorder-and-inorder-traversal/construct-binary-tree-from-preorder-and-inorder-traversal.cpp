// Given preorder and inorder traversal of a tree, construct the binary tree.
//
// Note:
// You may assume that duplicates do not exist in the tree.
//
// For example, given
//
//
// preorder = [3,9,20,15,7]
// inorder = [9,3,15,20,7]
//
// Return the following binary tree:
//
//
//     3
//    / \
//   9  20
//     /  \
//    15   7
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
    //同106，用递归
    //preorder 根 左节点 右节点
    //inorder 左节点 根 右节点
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return helper(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1);
    }
    
    TreeNode* helper(vector<int>& preorder, int left_pr, int right_pr,vector<int>& inorder, int left_in,int right_in){
        if(left_pr>right_pr || left_in>right_in) return NULL;
        TreeNode* root = new TreeNode(preorder[left_pr]);
        int i = 0;
        for(i;i<inorder.size();++i){
            if(inorder[i] == root->val) break;
        }
        
        root->left = helper(preorder,left_pr+1,left_pr+i-1-left_in+1,inorder,left_in,i-1);
        root->right = helper(preorder,left_pr+i-left_in+1,right_pr,inorder,i+1,right_in);
        
        return root;
    }
};
