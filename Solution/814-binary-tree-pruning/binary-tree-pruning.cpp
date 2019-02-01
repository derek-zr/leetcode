// We are given the head node root of a binary tree, where additionally every node's value is either a 0 or a 1.
//
// Return the same tree where every subtree (of the given tree) not containing a 1 has been removed.
//
// (Recall that the subtree of a node X is X, plus every node that is a descendant of X.)
//
//
// Example 1:
// Input: [1,null,0,0,1]
// Output: [1,null,0,null,1]
//
// Explanation: 
// Only the red nodes satisfy the property "every subtree not containing a 1".
// The diagram on the right represents the answer.
//
//
//
//
//
// Example 2:
// Input: [1,0,1,0,0,0,1]
// Output: [1,null,1,null,1]
//
//
//
//
//
//
// Example 3:
// Input: [1,1,0,1,1,0,1,0]
// Output: [1,1,0,1,1,null,1]
//
//
//
//
//
// Note: 
//
//
// 	The binary tree will have at most 100 nodes.
// 	The value of each node will only be 0 or 1.
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
    int remove0(TreeNode* root){
        if(root==NULL) return 0;
        int left0=remove0(root->left);
        int right0=remove0(root->right);
        if(left0==0) root->left=NULL;
        if(right0==0) root->right=NULL;
        if(root->val==0&&left0==0&&right0==0) return 0;
        else return 1;
    }
    TreeNode* pruneTree(TreeNode* root) {
        remove0(root);
        return root;
    }
};
