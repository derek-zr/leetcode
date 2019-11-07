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
        //遍历各个数字作为root的情况
        vector<TreeNode*> ans;
        if (n == 0)  return ans;
        return helper(1, n);
    }
    
    vector<TreeNode*> helper(int start, int end) {
        vector<TreeNode*> ans;
        //没有符合条件的点
        if (start > end) {
            ans.push_back(NULL);
            return ans;
        }    
        //只有一个符合条件的点
        if (start == end) {
            ans.push_back(new TreeNode(start));
            return ans;
        }
        
        //遍历各个点作为根节点
        for (int i = start; i <= end; ++i) {
            vector<TreeNode*> leftTree = helper(start, i - 1);
            vector<TreeNode*> rightTree = helper(i + 1, end);
            //连接根节点和左右子树
            for (TreeNode* l : leftTree) {
                for (TreeNode* r : rightTree) {
                    TreeNode* root = new TreeNode(i);
                    root->left = l;
                    root->right = r;
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }
    
};
