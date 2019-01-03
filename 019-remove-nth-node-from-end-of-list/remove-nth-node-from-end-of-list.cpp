// Given a linked list, remove the n-th node from the end of list and return its head.
//
// Example:
//
//
// Given linked list: 1->2->3->4->5, and n = 2.
//
// After removing the second node from the end, the linked list becomes 1->2->3->5.
//
//
// Note:
//
// Given n will always be valid.
//
// Follow up:
//
// Could you do this in one pass?
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* tmp = head;
        int len = 1;
        while(tmp->next){
            len++;
            tmp = tmp->next;
        }
        int target = len-n;
        if(target==0) return head->next;
        
        tmp = head;
        while(--target){
            tmp = tmp->next;
        }
        if(tmp->next->next==NULL){
            tmp->next = NULL;
            return head;
        }
        tmp->next = tmp->next->next;
        return head;
        
    }
};
