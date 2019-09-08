// Given a linked list, rotate the list to the right by k places, where k is non-negative.
//
// Example 1:
//
//
// Input: 1->2->3->4->5->NULL, k = 2
// Output: 4->5->1->2->3->NULL
// Explanation:
// rotate 1 steps to the right: 5->1->2->3->4->NULL
// rotate 2 steps to the right: 4->5->1->2->3->NULL
//
//
// Example 2:
//
//
// Input: 0->1->2->NULL, k = 4
// Output: 2->0->1->NULL
// Explanation:
// rotate 1 steps to the right: 2->0->1->NULL
// rotate 2 steps to the right: 1->2->0->NULL
// rotate 3 steps to the right: 0->1->2->NULL
// rotate 4 steps to the right: 2->0->1->NULL
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
    ListNode* rotateRight(ListNode* head, int k) {
        //把链表首尾相连，根据k找到应该断开的位置即可
        ListNode* dummy = new ListNode(-1), *cur = dummy;
        dummy->next = head;
        //统计链表长度，并且首尾相连
        int len = 0;
        while(cur->next) {cur = cur->next; ++len;}
        cur->next = head;
        if(len == 0) return dummy->next;
        //找k的断开位置
        k = k % len;
        if(k == 0) {
            cur->next = NULL;
            return dummy->next;
        }
        else {
            //找到断开位置的节点
            for(int i = 0; i < len-k; ++i) {
                cur = cur->next;
            }
            dummy->next = cur->next;
            cur->next = NULL;
            return dummy->next;
        }
    }
};
