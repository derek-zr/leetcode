// Given a Binary Search Tree (BST), convert it to a Greater Tree such that every key of the original BST is changed to the original key plus sum of all keys greater than the original key in BST.
//
//
// Example:
//
// Input: The root of a Binary Search Tree like this:
//               5
//             /   \
//            2     13
//
// Output: The root of a Greater Tree like this:
//              18
//             /   \
//           20     13
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
    TreeNode* convertBST(TreeNode* root) {
        if(root==NULL) return NULL;
        int sum = 0;
        helper(root, sum);
        return root;
    }
    
    void helper(TreeNode* root, int& sum){
        if(root==NULL) return;
        helper(root->right,sum); //右子树均大于当前root
        root->val += sum;
        sum = root->val;
        helper(root->left,sum);   //左子树小于root及所有右子树
    }
};
