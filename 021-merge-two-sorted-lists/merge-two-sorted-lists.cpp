// Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
//
// Example:
//
// Input: 1->2->4, 1->3->4
// Output: 1->1->2->3->4->4
//
//


/*
 * [21] Merge Two Sorted Lists
 *
 * https://leetcode.com/problems/merge-two-sorted-lists/description/
 *
 * algorithms
 * Easy (42.85%)
 * Total Accepted:    397.2K
 * Total Submissions: 926.6K
 * Testcase Example:  '[1,2,4]\n[1,3,4]'
 *
 * Merge two sorted linked lists and return it as a new list. The new list
 * should be made by splicing together the nodes of the first two lists.
 * 
 * Example:
 * 
 * Input: 1->2->4, 1->3->4
 * Output: 1->1->2->3->4->4
 * 
 * 
 */
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==NULL) return l2;
        if(l2==NULL) return l1; 
        ListNode* root=NULL;
        if(l1->val>l2->val){root=l2;l2=l2->next;}
        else {root=l1;l1=l1->next;}
        ListNode* head=root;
        while(l1&&l2){
            if(l1->val>l2->val) {root->next=l2;l2=l2->next;}
            else {root->next=l1;l1=l1->next;}
            //cout<<root->val;
            root=root->next;
        }
        if(l1==NULL) root->next=l2;
        if(l2==NULL) root->next=l1;
        return head;
    }
};

