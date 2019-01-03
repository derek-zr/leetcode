// Given an n-ary tree, return the preorder traversal of its nodes' values.
//
// For example, given a 3-ary tree:
//
//  
//
//
//
//  
//
// Return its preorder traversal as: [1,3,5,6,2,4].
//
//  
//
// Note:
//
// Recursive solution is trivial, could you do it iteratively?
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
    vector<int> preorder(Node* root) {
        if(root==NULL) return {};
        stack<Node*> nodes;
        vector<int> ans;
        nodes.push(root);
        while(!nodes.empty()){
            Node* tmp=nodes.top();
            nodes.pop();
            //cout<<tmp->val;
            ans.push_back(tmp->val);
            for(int i=tmp->children.size()-1;i>=0;i--) nodes.push(tmp->children[i]);
        }
        return ans;
    }
};
