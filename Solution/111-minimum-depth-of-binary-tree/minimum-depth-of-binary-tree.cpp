// Given a binary tree, find its minimum depth.
//
// The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
//
// Note: A leaf is a node with no children.
//
// Example:
//
// Given binary tree [3,9,20,null,null,15,7],
//
//
//     3
//    / \
//   9  20
//     /  \
//    15   7
//
// return its minimum depth = 2.
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
    int minDepth(TreeNode* root) {
        if(root==NULL) return 0;
        //若其中一个子树为空，则只计算其中一个(必须处理这种情况，否则[1,2]这种例子会出错)
        if(root->left==NULL) return 1+minDepth(root->right);
        if(root->right==NULL) return 1+minDepth(root->left);
        int leftH = minDepth(root->left);
        int rightH = minDepth(root->right);
        return min(leftH,rightH)+1;
    }
};
