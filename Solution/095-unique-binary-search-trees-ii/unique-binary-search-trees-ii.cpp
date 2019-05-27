// Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1 ... n.
//
// Example:
//
//
// Input: 3
// Output:
// [
//   [1,null,3,2],
//   [3,2,null,1],
//   [3,1,null,null,2],
//   [2,1,3],
//   [1,null,2,null,3]
// ]
// Explanation:
// The above output corresponds to the 5 unique BST's shown below:
//
//    1         3     3      2      1
//     \       /     /      / \      \
//      3     2     1      1   3      2
//     /     /       \                 \
//    2     1         2                 3
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
    vector<TreeNode*> generateTrees(int n) {
        if(n==0) return {};
        //递归法。如果i是根节点，则左子树必定为1 to i-1的点，右子树必定为i+1 to n的点。
        return helper(1,n);
    }
    
    vector<TreeNode*> helper(int start,int end) {
        vector<TreeNode*> ans;
        if(start>end) {  //不可能存在这样的数，即为空节点
            ans.push_back(NULL);
            return ans;
        }
        if(start==end) {  //只有一个符合条件的数
            ans.push_back(new TreeNode(start));
            return ans;
        }
        
        //左右子树的可能性
        vector<TreeNode*> leftTree,rightTree;
        for(int i = start; i <= end; ++i) {
            //i为根节点
            leftTree = helper(start,i-1);  
            rightTree = helper(i+1,end);
            for(TreeNode* left_t : leftTree) {
                for(TreeNode* right_t : rightTree) {
                    TreeNode* root = new TreeNode(i);
                    root->left = left_t;
                    root->right = right_t;  
                    ans.push_back(root);  //存入各种情况
                }
            }
        }
        return ans;
    }
    
};
