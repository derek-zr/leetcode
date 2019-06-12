// Given a binary tree, return the postorder traversal of its nodes' values.
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
// Output: [3,2,1]
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
    vector<int> postorderTraversal(TreeNode* root) {
        //这道题很多网上解法是先序遍历后再反转，但这并不是最优解法。如果树本身存在一定的拓扑结构，这种遍历方式就会有问题
        vector<int> ans;
        if(root == NULL) return ans;
        stack<TreeNode*> s;
        TreeNode* lastProcess = NULL; //上一个处理的节点
        
        //开始遍历
        while(root || !s.empty()) {
            if(root) {
                s.push(root);
                root = root->left;  //一直找到最左的节点
            }
            else {
                TreeNode* tmp = s.top();
                if(tmp->right && lastProcess != tmp->right) {
                    //最左节点可能存在右孩子，需要先处理
                    root = tmp->right;
                }
                else {
                    //没有任何孩子了，处理当前节点
                    //cout<<tmp->val;
                    ans.push_back(tmp->val);
                    lastProcess = tmp;
                    s.pop();  //加入数组了，可以出栈了
                }
            }
        }
        return ans;
    }
};
