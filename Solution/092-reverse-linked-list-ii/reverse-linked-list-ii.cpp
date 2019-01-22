// Reverse a linked list from position m to n. Do it in one-pass.
//
// Note: 1 ≤ m ≤ n ≤ length of list.
//
// Example:
//
//
// Input: 1->2->3->4->5->NULL, m = 2, n = 4
// Output: 1->4->3->2->5->NULL
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
    //一般链表的题目都要在head前加一个dummy节点，便于操作，返回链表头时即dummy->next
    //在这道题中要考虑到m=1的情况，这时候就需要dummy节点
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(m>=n) return head;
        ListNode* dummy = new ListNode(-1),*pre = dummy;
        dummy->next = head;
        for (int i = 0; i < m - 1; ++i) pre = pre->next;
        ListNode* cur = pre->next;

        //用三个节点 pre,cur,next. 1,2,3,4 -> 1,3,2,4
        for(int i=m;i<n;i++){
            ListNode* tmp = cur->next;
            cur->next = tmp->next;
            tmp->next = pre->next;
            pre->next = tmp;
        }
        
        return dummy->next;
    }
};
