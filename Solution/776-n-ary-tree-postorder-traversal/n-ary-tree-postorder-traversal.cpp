// Given an n-ary tree, return the postorder traversal of its nodes' values.
//
// For example, given a 3-ary tree:
//
//  
//
//
//
//  
//
// Return its postorder traversal as: [5,6,3,2,4,1].
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
    vector<int> postorder(Node* root) {
        vector<int> results;
        stack<Node*> nodes;
        nodes.push(root);
        while(!nodes.empty()&& root){
            Node* tmp=nodes.top();
            nodes.pop();
            results.insert(results.begin(),tmp->val);
            for(Node* child:tmp->children){nodes.push(child);}
        }
        return results;
    }
};
