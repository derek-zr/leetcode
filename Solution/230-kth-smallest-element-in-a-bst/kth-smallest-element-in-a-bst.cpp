// Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.
//
// Note: 
// You may assume k is always valid, 1 ≤ k ≤ BST's total elements.
//
// Example 1:
//
//
// Input: root = [3,1,4,null,2], k = 1
//    3
//   / \
//  1   4
//   \
//    2
// Output: 1
//
// Example 2:
//
//
// Input: root = [5,3,6,2,4,null,null,1], k = 3
//        5
//       / \
//      3   6
//     / \
//    2   4
//   /
//  1
// Output: 3
//
//
// Follow up:
// What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?
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
    int kthSmallest(TreeNode* root, int k) {
        /*
        BST的中序遍历是有序的，所以可以利用这个性质判断k的位置
        */
        int nodeCnt = count(root->left);
        
        if(k <= nodeCnt) {
            return kthSmallest(root->left,k);
        }
        else if(k > nodeCnt+1) {
            return kthSmallest(root->right,k-nodeCnt-1);
        }
        return root->val;
    }
    
    int count(TreeNode* root) {
        if(!root) return 0;
        return 1+count(root->left)+count(root->right);
    }
};
