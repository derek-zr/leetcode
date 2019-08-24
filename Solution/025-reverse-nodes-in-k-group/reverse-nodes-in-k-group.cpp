// Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
//
// k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
//
//
//
//
// Example:
//
// Given this linked list: 1->2->3->4->5
//
// For k = 2, you should return: 2->1->4->3->5
//
// For k = 3, you should return: 3->2->1->4->5
//
// Note:
//
//
// 	Only constant extra memory is allowed.
// 	You may not alter the values in the list's nodes, only nodes itself may be changed.
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(-1), *pre = dummy;
        dummy->next = head;
        ListNode* cur = head;
        int num = 0;
        //统计个数
        while(cur) {++num; cur = cur->next;}
        //翻转
        while(num >= k) {
            cur = pre->next;
            for(int i = 1; i < k; ++i) {   //反转k-1次
                ListNode* tmp = cur->next;
                cur->next = tmp->next;
                tmp->next = pre->next;
                pre->next = tmp;
            }
            num -= k;
            pre = cur;
        }
        
        return dummy->next;
            
        /*
        //以k个为一组，分组反转链表。
        //先统计链表的长度，再每次反转k个节点，并-k，一直到不能再分为一组
        ListNode* dummy = new ListNode(-1), *pre = dummy;
        pre->next = head;
        ListNode* cur = pre->next;
        int num = 0;
        while(cur) {++num; cur = cur->next;}
        while(num >= k) {
            cur = pre->next;
            for(int i =1; i <k; ++i) {  //反转k的节点，需要反转k-1次
                ListNode* tmp = cur->next;
                cur->next = tmp->next;
                tmp->next = pre->next;
                pre->next = tmp;
            }
            num -= k; //这一组已经反转完毕
            pre = cur;  //下一次循环赋值时cur=pre->next,为这一组反转后的最后一个节点
        }
        return dummy->next;
        */
    }
};
