// Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).
//
//
// For example:
// Given binary tree [3,9,20,null,null,15,7],
//
//     3
//    / \
//   9  20
//     /  \
//    15   7
//
//
//
// return its zigzag level order traversal as:
//
// [
//   [3],
//   [20,9],
//   [15,7]
// ]
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
    //bfs
    //用两个stack或者queue分别存放相邻两层的节点，方向相反
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL) return ans;
        stack<TreeNode*> s1;
        stack<TreeNode*> s2;
        s1.push(root);
        while(!s1.empty() || !s2.empty()) {
            vector<int> level;
            while(!s1.empty()) {
                TreeNode* tmp = s1.top();
                s1.pop();
                level.push_back(tmp->val);
                if(tmp->left) s2.push(tmp->left);
                if(tmp->right) s2.push(tmp->right);
            }
            if(!level.empty()) ans.push_back(level);
            level.clear();
            
            while(!s2.empty()) {
                TreeNode* tmp = s2.top();
                s2.pop();
                level.push_back(tmp->val);
                if(tmp->right) s1.push(tmp->right);
                if(tmp->left) s1.push(tmp->left);
            }
            if(!level.empty()) ans.push_back(level);
        }
        
        return ans;
    }
};
