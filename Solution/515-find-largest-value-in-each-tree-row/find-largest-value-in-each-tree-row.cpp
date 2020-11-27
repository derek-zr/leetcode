// Given the root of a binary tree, return an array of the largest value in each row of the tree (0-indexed).
//
//  
//
//  
// Example 1:
//
//
// Input: root = [1,3,2,5,3,null,9]
// Output: [1,3,9]
//
//
// Example 2:
//
//
// Input: root = [1,2,3]
// Output: [1,3]
//
//
// Example 3:
//
//
// Input: root = [1]
// Output: [1]
//
//
// Example 4:
//
//
// Input: root = [1,null,2]
// Output: [1,2]
//
//
// Example 5:
//
//
// Input: root = []
// Output: []
//
//
//  
// Constraints:
//
//
// 	The number of nodes in the tree will be in the range [0, 104].
// 	-231 <= Node.val <= 231 - 1
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
