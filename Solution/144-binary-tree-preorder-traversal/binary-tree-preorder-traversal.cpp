// Given a binary tree, return the preorder traversal of its nodes' values.
//
// Example:
//
//
// Input: [1,null,2,3]
//    1
//     \
//      2
//     /
//    3
//
// Output: [1,2,3]
//
//
// Follow up: Recursive solution is trivial, could you do it iteratively?
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
    vector<int> preorderTraversal(TreeNode* root) {
        //用栈,按照顺序压入root和其左右子节点
        vector<int> ans;
        if(root == NULL) return ans;
        stack<TreeNode*> s;
        s.push(root);
        //开始迭代
        while(!s.empty()) {
            TreeNode* tmp = s.top();
            s.pop();
            ans.push_back(tmp->val);
            if(tmp->right) s.push(tmp->right); //先压的后出栈
            if(tmp->left) s.push(tmp->left);
        }
        return ans;
    }
};
