// The thief has found himself a new place for his thievery again. There is only one entrance to this area, called the "root." Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that "all houses in this place forms a binary tree". It will automatically contact the police if two directly-linked houses were broken into on the same night.
//
// Determine the maximum amount of money the thief can rob tonight without alerting the police.
//
// Example 1:
//
//
// Input: [3,2,3,null,3,null,1]
//
//      3
//     / \
//    2   3
//     \   \ 
//      3   1
//
// Output: 7 
// Explanation: Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
//
// Example 2:
//
//
// Input: [3,4,5,1,3,null,1]
//
//      3
//     / \
//    4   5
//   / \   \ 
//  1   3   1
//
// Output: 9
// Explanation: Maximum amount of money the thief can rob = 4 + 5 = 9.
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
    int rob(TreeNode* root) {
        vector<int> ans;
        ans = dpRob(root);
        return max(ans[0],ans[1]);
    }
    
    // [0]中存放不rob当前点的值，[1]中存放rob当前点的值。
    // ans[0] = max左子树 + max右子树（因为不rob当前点，所以左右子树无限制）
    // ans[1] = 当前点的值 + 左子树不rob + 右子树不rob
    vector<int> dpRob(TreeNode* root){
        vector<int> ans(2,0);
        if(root==NULL) return ans;
        vector<int> left;
        vector<int> right;
        left = dpRob(root->left);
        right = dpRob(root->right);
        ans[0] = max(left[0],left[1]) + max(right[0],right[1]);
        ans[1] = root->val + left[0] + right[0];
        //cout<<ans[0]<<ans[1]<<endl;
        return ans;
    }
};
