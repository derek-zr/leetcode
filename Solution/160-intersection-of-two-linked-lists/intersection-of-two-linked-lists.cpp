// Write a program to find the node at which the intersection of two singly linked lists begins.
//
// For example, the following two linked lists:
//
//
// begin to intersect at node c1.
//
//  
//
// Example 1:
//
//
//
// Input: intersectVal = 8, listA = [4,1,8,4,5], listB = [5,0,1,8,4,5], skipA = 2, skipB = 3
// Output: Reference of the node with value = 8
// Input Explanation: The intersected node's value is 8 (note that this must not be 0 if the two lists intersect). From the head of A, it reads as [4,1,8,4,5]. From the head of B, it reads as [5,0,1,8,4,5]. There are 2 nodes before the intersected node in A; There are 3 nodes before the intersected node in B.
//
//  
//
// Example 2:
//
//
//
// Input: intersectVal = 2, listA = [0,9,1,2,4], listB = [3,2,4], skipA = 3, skipB = 1
// Output: Reference of the node with value = 2
// Input Explanation: The intersected node's value is 2 (note that this must not be 0 if the two lists intersect). From the head of A, it reads as [0,9,1,2,4]. From the head of B, it reads as [3,2,4]. There are 3 nodes before the intersected node in A; There are 1 node before the intersected node in B.
//
//
//  
//
// Example 3:
//
//
//
// Input: intersectVal = 0, listA = [2,6,4], listB = [1,5], skipA = 3, skipB = 2
// Output: null
// Input Explanation: From the head of A, it reads as [2,6,4]. From the head of B, it reads as [1,5]. Since the two lists do not intersect, intersectVal must be 0, while skipA and skipB can be arbitrary values.
// Explanation: The two lists do not intersect, so return null.
//
//
//  
//
// Notes:
//
//
// 	If the two linked lists have no intersection at all, return null.
// 	The linked lists must retain their original structure after the function returns.
// 	You may assume there are no cycles anywhere in the entire linked structure.
// 	Your code should preferably run in O(n) time and use only O(1) memory.
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        //考虑将两个链表连成环.用两个指针遍历，到达一个链表的末尾时候，跳到另一个链表头
        //两个指针最终要么相等于交点，要么都为NULL，分别在两个链表末尾
        
        if(!headA || !headB) return NULL;
        ListNode* tmp1 = headA, *tmp2 = headB;
        
        while(tmp1 != tmp2) {
            tmp1 = tmp1? tmp1->next : headB;
            tmp2 = tmp2? tmp2->next : headA;
            //cout<<tmp1->val<<tmp2->val<<endl;
        }
        return tmp1;
        
        /*
        //考虑要O(N).这里我们先得到两个链表的长度，再把长的链表向后移动到等长。接着再依次对应比较两个链表即可
        int len1 = getListLen(headA), len2 = getListLen(headB);
        ListNode* tmp1 = headA, *tmp2 = headB;
        if(len1 < len2) {
            for(int i = 0; i < len2-len1; ++i) tmp2 = tmp2->next;
        }
        else {
            for(int i = 0; i < len1-len2; ++i) tmp1 = tmp1->next;
        }
        
        while(tmp1 && tmp2 && tmp1 != tmp2){
            tmp1 = tmp1->next;
            tmp2 = tmp2->next;
        }
        
        return tmp1;
        */
    }
    
    int getListLen(ListNode* head){
        int len = 0;
        while(head){
            ++len;
            head = head->next;
        }
        return len;
    }
};
