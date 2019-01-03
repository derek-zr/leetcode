// Given a singly linked list, determine if it is a palindrome.
//
// Example 1:
//
//
// Input: 1->2
// Output: false
//
// Example 2:
//
//
// Input: 1->2->2->1
// Output: true
//
// Follow up:
// Could you do it in O(n) time and O(1) space?
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
    bool isPalindrome(ListNode* head) {
        if(head==NULL||head->next==NULL) return true;
        //find mid
        ListNode* slow =head;
        ListNode* fast =head;
        while(fast->next&&fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* mid = slow->next;
        slow->next = NULL;
        //reverse
        ListNode* tmp1 = NULL;
        while(mid){
            ListNode* tmp2 = mid->next;
            mid->next = tmp1;
            tmp1 = mid;
            mid = tmp2;
        }
        //一个指向链表的头，一个指向reverse后的链表头
        slow = head;
        mid = tmp1;
        while(slow && mid){
            if(slow->val != mid->val) return false;
            slow = slow->next;
            mid = mid->next;
        }
        return true;
        
    }
};
