// Given a binary search tree (BST) with duplicates, find all the mode(s) (the most frequently occurred element) in the given BST.
//
// Assume a BST is defined as follows:
//
//
// 	The left subtree of a node contains only nodes with keys less than or equal to the node's key.
// 	The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
// 	Both the left and right subtrees must also be binary search trees.
//
//
//  
//
// For example:
// Given BST [1,null,2,2],
//
//
//    1
//     \
//      2
//     /
//    2
//
//
//  
//
// return [2].
//
// Note: If a tree has more than one mode, you can return them in any order.
//
// Follow up: Could you do that without using any extra space? (Assume that the implicit stack space incurred due to recursion does not count).
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
    int maxCnts = INT_MIN;
    int curCnts = 0;
    TreeNode* prev = NULL;
    vector<int> ans;
    
    
    void inorder(TreeNode* root, bool getAns) {
        if (!root)  return;
        inorder(root->left, getAns);
        
        //计算中序遍历的连续值是否相等
        if (prev && prev->val == root->val)   ++curCnts;
        else  curCnts = 1;
        //判断是找最大值还是找最后等于最大值的ans
        if (!getAns)  maxCnts = max(maxCnts, curCnts);
        else if (curCnts == maxCnts)  ans.push_back(root->val);
        prev = root;
        
        inorder(root->right, getAns);
    }
    
    vector<int> findMode(TreeNode* root) {
        //利用的特点是BST的中序遍历是有序的
        ans.clear();
        if (!root)  return ans;
        //首先找到maxCnt
        inorder(root, false);
        
        prev = NULL;
        curCnts = 0;
        //找到等于maxCnts的数
        inorder(root, true);
        
        return ans;
    }
};
