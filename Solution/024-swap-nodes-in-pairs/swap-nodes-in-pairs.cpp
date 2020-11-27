// Given a linked list, swap every two adjacent nodes and return its head.
//
// You may not modify the values in the list's nodes. Only nodes itself may be changed.
//
//  
// Example 1:
//
//
// Input: head = [1,2,3,4]
// Output: [2,1,4,3]
//
//
// Example 2:
//
//
// Input: head = []
// Output: []
//
//
// Example 3:
//
//
// Input: head = [1]
// Output: [1]
//
//
//  
// Constraints:
//
//
// 	The number of nodes in the list is in the range [0, 100].
// 	0 <= Node.val <= 100
//
//


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        //第二种用迭代的方法，先建立一个dummy结点指向头结点
        //对于链表的题目，最好先在纸上画一张图，理清节点间的关系
        ListNode* dummy = new ListNode(-1),*pre = dummy;
        pre->next = head;
        while(pre->next && pre->next->next) {
            ListNode* tmp = pre->next->next;   //这边的特点是上一个等式右边的等于下一个等式左边的
            pre->next->next = tmp->next;
            tmp->next = pre->next;
            pre->next = tmp;
            pre = tmp->next;
        }
        return dummy->next;
        /*
        //第一种递归的方法。先递归到尾部，再进行swap
        if(!head || !head->next) return head;
        ListNode* tmp = head->next;
        head->next = swapPairs(head->next->next);
        tmp->next = head;
        return tmp;
        */
    }
};
