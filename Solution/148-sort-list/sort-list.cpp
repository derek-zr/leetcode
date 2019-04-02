// Sort a linked list in O(n log n) time using constant space complexity.
//
// Example 1:
//
//
// Input: 4->2->1->3
// Output: 1->2->3->4
//
//
// Example 2:
//
//
// Input: -1->5->3->4->0
// Output: -1->0->3->4->5
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
    //符合nlogn的只有 快排 归并排序 堆排序
    //链表适合用归并排序
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* pre = head, *slow = head, *fast = head;
        while(fast && fast->next) {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        pre->next = NULL;
        return merge(sortList(head),sortList(slow));
    }
    
    ListNode* merge(ListNode* p1,ListNode* p2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* cur = dummy;
        while(p1 && p2) {
            if(p1->val < p2->val){
                cur->next = p1;
                p1 = p1->next;
            }
            else {
                cur->next = p2;
                p2 = p2->next;
            }
            cur = cur->next;
        }
        
        if(p1) cur->next = p1;
        if(p2) cur->next = p2;
        return dummy->next;
    }
    
};
