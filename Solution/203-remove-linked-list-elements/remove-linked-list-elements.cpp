// Remove all elements from a linked list of integers that have value val.
//
// Example:
//
//
// Input:  1->2->6->3->4->5->6, val = 6
// Output: 1->2->3->4->5
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
    ListNode* removeElements(ListNode* head, int val) {
        if(head == NULL) return head;
        ListNode* dummy = new ListNode(-1), *cur = dummy;
        dummy->next = head;
        
        while(cur) {
            if(cur->next && cur->next->val == val) {
                cur->next = cur->next->next;
            }  //不需要移动cur，因为我们需要去除所有连续的val。
            else cur = cur->next; //这里要用else，因为需要去除连续的val。
        }
        
        return dummy->next;
    }
};
