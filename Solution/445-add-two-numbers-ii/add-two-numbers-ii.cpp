// You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
//
// You may assume the two numbers do not contain any leading zero, except the number 0 itself.
//
// Follow up:
// What if you cannot modify the input lists? In other words, reversing the lists is not allowed.
//
//
//
// Example:
//
// Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
// Output: 7 -> 8 -> 0 -> 7
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //不允许反转链表，但我们又需要知道链表的prev节点
        //所以将之前的节点压栈，然后逐步出栈得到新的链表
        stack<int> s1, s2;
        while(l1) {
            s1.push(l1->val);
            l1 = l1->next;
        }
        while(l2) {
            s2.push(l2->val);
            l2 = l2->next;
        }
        int sum = 0;
        ListNode *ans = new ListNode(0);
        while(!s1.empty() || !s2.empty()) {
            if(!s1.empty()) {
                sum += s1.top();
                s1.pop();
            }
            if(!s2.empty()) {
                sum += s2.top();
                s2.pop();
            }
            ans->val = sum%10;
            //处理进位
            ListNode *carry = new ListNode(sum / 10);
            carry->next = ans;
            ans = carry;
            sum /= 10;   //进位参与上一位的加
        }
        //去除高位的0
        return ans->val==0 ? ans->next : ans;
    }
};
