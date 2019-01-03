// Given a singly linked list L: L0→L1→…→Ln-1→Ln,
// reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…
//
// You may not modify the values in the list's nodes, only nodes itself may be changed.
//
// Example 1:
//
//
// Given 1->2->3->4, reorder it to 1->4->2->3.
//
// Example 2:
//
//
// Given 1->2->3->4->5, reorder it to 1->5->2->4->3.
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
    //first find middle node
    //divide into two list and reverse the second list
    //merge two list
    void reorderList(ListNode* head) {
        if(head==NULL || head->next==NULL) return;
        //find mid node
        ListNode* p1 = head;
        ListNode* p2 = head->next;
        while(p2 && p2->next){
            p1 = p1->next;
            p2 = p2->next->next;
        }
        //cout<<p1->val;
        //divide
        ListNode* mid = p1->next;
        p1->next = NULL;
        //reverse https://blog.csdn.net/feliciafay/article/details/6841115
        ListNode* tmp = mid->next;
        mid->next = NULL;
        while(tmp){
            ListNode* tmp2 = tmp->next;
            tmp->next = mid;
            mid = tmp;
            tmp = tmp2;
        }
        /*
        ListNode* out = mid;
        while(out){
            cout<<out->val;
            out = out->next;
        }
        */
        //merge
        p1 = head;
        while(p1){
            ListNode* first = p1->next;
            p1->next = mid;
            p1 = p1->next;
            mid = first;
        }
        
    }
};
