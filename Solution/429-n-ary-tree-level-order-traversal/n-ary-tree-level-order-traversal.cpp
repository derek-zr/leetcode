// Given an n-ary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).
//
// For example, given a 3-ary tree:
//
//  
//
//
//
//  
//
// We should return its level order traversal:
//
//
// [
//      [1],
//      [3,2,4],
//      [5,6]
// ]
//
//
//  
//
// Note:
//
//
// 	The depth of the tree is at most 1000.
// 	The total number of nodes is at most 5000.
//
//


/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        //bfs
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        queue<Node*> q;
        q.push(root);
        //开始遍历
        while(!q.empty()) {
            int len = q.size();
            vector<int> tmp;
            for(int i = 0; i < len; ++i) {
                Node *cur = q.front();
                q.pop();
                tmp.push_back(cur->val);
                for(auto child : cur->children) {
                    q.push(child);
                }
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};
