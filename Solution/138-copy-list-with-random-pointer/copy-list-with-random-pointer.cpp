// A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.
//
// Return a deep copy of the list.
//
//  
//
// Example 1:
//
//
//
//
// Input:
// {"$id":"1","next":{"$id":"2","next":null,"random":{"$ref":"2"},"val":2},"random":{"$ref":"2"},"val":1}
//
// Explanation:
// Node 1's value is 1, both of its next and random pointer points to Node 2.
// Node 2's value is 2, its next pointer points to null and its random pointer points to itself.
//
//
//  
//
// Note:
//
//
// 	You must return the copy of the given head as a reference to the cloned list.
//
//


/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
    //http://fisherlei.blogspot.com/2013/11/leetcode-copy-list-with-random-pointer.html
    //这种方法更加节省内存。首先在原链表后面各加一个拷贝的新节点
    //下一步通过 cur->next->random = cur->random->next将random关系拷贝进新的节点间
    //最后断开两个链表
        
        if(!head) return NULL;
        Node* cur = head;
        //拷贝新节点
        while(cur){
            Node* tmp = new Node(cur->val,NULL,NULL);
            tmp->next = cur->next;
            cur->next = tmp;
            cur = tmp->next;
        }
        //拷贝random节点
        cur = head;
        while(cur) {
            if(cur->random){
                cur->next->random = cur->random->next;
            }
            cur = cur->next->next;
        }
        
        //拆分链表
        cur = head;
        Node* ans = head->next;
        while(cur){
            Node* tmp = cur->next;
            cur->next = tmp->next;
            if(tmp->next) tmp->next = tmp->next->next;
            cur = cur->next;
        }
        
        return ans;
        
        
    /*
    //这道题主要难点在random指针的拷贝上，如果每拷贝一次就要遍历一次链表查询位置，会超时
    //用map存储新旧节点的对应关系，这样在查找时候为O(1)
        if(!head) return NULL;
        Node* ans = new Node(head->val,NULL,NULL); //注意函数接口，必须要加上两个指针的初始值
        Node* newhead = ans;
        Node* old = head->next;
        unordered_map<Node*,Node*> m;
        m[head] = ans;
        while(old){
            Node* tmp = new Node(old->val,NULL,NULL);
            newhead->next = tmp;
            m[old] = tmp;
            old = old->next;
            newhead = tmp;
        }
        
        newhead = ans;
        old = head;
        while(old){
            newhead->random = m[old->random];
            newhead = newhead->next;
            old = old->next;
        }
        return ans;
        */
    }
};
