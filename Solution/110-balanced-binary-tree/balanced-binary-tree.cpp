// Given a binary tree, determine if it is height-balanced.
//
// For this problem, a height-balanced binary tree is defined as:
//
//
// a binary tree in which the left and right subtrees of every node differ in height by no more than 1.
//
//
//  
//
// Example 1:
//
// Given the following tree [3,9,20,null,null,15,7]:
//
//
//     3
//    / \
//   9  20
//     /  \
//    15   7
//
// Return true.
//
// Example 2:
//
// Given the following tree [1,2,2,3,3,null,null,4,4]:
//
//
//        1
//       / \
//      2   2
//     / \
//    3   3
//   / \
//  4   4
//
//
// Return false.
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
    bool isBalanced(TreeNode* root) {
        //dfs,如果不是平衡的，则返回高度-1
        return dfs(root) != -1;
    }
    
    int dfs(TreeNode* root) {
        if(root == NULL) return 0;
        
        int leftH = dfs(root->left);
        if(leftH == -1) return -1;  //有一个subtree不符合条件就为false
        int rightH = dfs(root->right);
        if(rightH == -1) return -1;
        
        if(abs(leftH-rightH) > 1) return -1;
        return max(leftH,rightH) + 1;
    }
};
