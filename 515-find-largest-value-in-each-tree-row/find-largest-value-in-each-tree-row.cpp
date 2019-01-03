// You need to find the largest value in each row of a binary tree.
//
// Example:
//
// Input: 
//
//           1
//          / \
//         3   2
//        / \   \  
//       5   3   9 
//
// Output: [1, 3, 9]
//
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
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        queue<TreeNode*> nodes;
        if(root==NULL) return ans;
        nodes.push(root);
        while(!nodes.empty()){
            int levelSize=nodes.size();
            int maxval=INT_MIN;
            for(int i=0;i<levelSize;i++){
                TreeNode* tmp=nodes.front();
                nodes.pop();
                if(tmp->left) nodes.push(tmp->left);
                if(tmp->right) nodes.push(tmp->right);
                maxval=max(maxval,tmp->val);
            }
            ans.push_back(maxval);
        }
        return ans;
    }
};
