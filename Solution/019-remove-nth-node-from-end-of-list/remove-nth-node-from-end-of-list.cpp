// Given the head of a linked list, remove the nth node from the end of the list and return its head.
//
// Follow up: Could you do this in one pass?
//
//  
// Example 1:
//
//
// Input: head = [1,2,3,4,5], n = 2
// Output: [1,2,3,5]
//
//
// Example 2:
//
//
// Input: head = [1], n = 1
// Output: []
//
//
// Example 3:
//
//
// Input: head = [1,2], n = 1
// Output: [1]
//
//
//  
// Constraints:
//
//
// 	The number of nodes in the list is sz.
// 	1 <= sz <= 30
// 	0 <= Node.val <= 100
// 	1 <= n <= sz
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
