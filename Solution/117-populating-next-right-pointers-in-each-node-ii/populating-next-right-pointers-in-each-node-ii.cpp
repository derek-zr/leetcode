// Given a binary tree
//
//
// struct Node {
//   int val;
//   Node *left;
//   Node *right;
//   Node *next;
// }
//
//
// Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.
//
// Initially, all next pointers are set to NULL.
//
//  
//
// Example:
//
//
//
//
// Input: {"$id":"1","left":{"$id":"2","left":{"$id":"3","left":null,"next":null,"right":null,"val":4},"next":null,"right":{"$id":"4","left":null,"next":null,"right":null,"val":5},"val":2},"next":null,"right":{"$id":"5","left":null,"next":null,"right":{"$id":"6","left":null,"next":null,"right":null,"val":7},"val":3},"val":1}
//
// Output: {"$id":"1","left":{"$id":"2","left":{"$id":"3","left":null,"next":{"$id":"4","left":null,"next":{"$id":"5","left":null,"next":null,"right":null,"val":7},"right":null,"val":5},"right":null,"val":4},"next":{"$id":"6","left":null,"next":null,"right":{"$ref":"5"},"val":3},"right":{"$ref":"4"},"val":2},"next":null,"right":{"$ref":"6"},"val":1}
//
// Explanation: Given the above binary tree (Figure A), your function should populate each next pointer to point to its next right node, just like in Figure B.
//
//
//  
//
// Note:
//
//
// 	You may only use constant extra space.
// 	Recursive approach is fine, implicit stack space does not count as extra space for this problem.
//


/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/
class Solution {
public:
    Node* connect(Node* root) {
        //层序遍历。迭代解决：遍历某一层时，连接其下一层的节点们
        //dummy指向一层的头结点，cur为当前遍历到的节点
        if(!root) return root;
        Node* dummy = new Node(0,NULL,NULL,NULL),*cur = dummy, *head = root;
        
        while(root) {
            //连接下一层的节点
            if(root->left) {
                cur->next = root->left;
                cur = cur->next;
            }
            if(root->right) {
                cur->next = root->right;
                cur = cur->next;
            }
            root = root->next; //指向next，如果next为NULL，说明该层已经遍历完了
            if(!root) {  //下一层的节点全部连接完毕
                cur = dummy;  //开始遍历下一层（连接下下层）
                root = cur->next; 
                cur->next = NULL;  //断开与上一层的连接，避免死循环
            }
        }
        return head;
    }
};
