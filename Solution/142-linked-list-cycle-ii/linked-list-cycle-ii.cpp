// Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
//
// To represent a cycle in the given linked list, we use an integer pos which represents the position (0-indexed) in the linked list where tail connects to. If pos is -1, then there is no cycle in the linked list.
//
// Note: Do not modify the linked list.
//
//  
//
// Example 1:
//
//
// Input: head = [3,2,0,-4], pos = 1
// Output: tail connects to node index 1
// Explanation: There is a cycle in the linked list, where tail connects to the second node.
//
//
//
//
// Example 2:
//
//
// Input: head = [1,2], pos = 0
// Output: tail connects to node index 0
// Explanation: There is a cycle in the linked list, where tail connects to the first node.
//
//
//
//
// Example 3:
//
//
// Input: head = [1], pos = -1
// Output: no cycle
// Explanation: There is no cycle in the linked list.
//
//
//
//
//  
//
// Follow-up:
// Can you solve it without using extra space?
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
    ListNode *detectCycle(ListNode *head) {
        if (!head || !head->next) return NULL;
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) break;
        }
        
        if (!fast || !fast->next) return NULL;    //为NULL相等，说明不存在环
        slow = head;
        /*
        Assume the distance from head to the start of the loop is x1
        the distance from the start of the loop to the point fast and slow meet is x2
        the distance from the point fast and slow meet to the start of the loop is x3
        What is the distance fast moved? What is the distance slow moved? And their relationship?

        x1 + x2 + x3 + x2
        x1 + x2
        x1 + x2 + x3 + x2 = 2 (x1 + x2)
        Thus x1 = x3
        */
        slow = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        
        return slow;
        
        /*
        if(!head || !head->next) return NULL;
        ListNode* slow = head, *fast = head;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) break;
        }
        if(!fast || !fast->next) return NULL;  //为NULL时两者相等，即不存在环
        slow = head;
        while(slow != fast) {
            slow = slow->next;
            fast = fast->next;  //一个从头走，一个从相遇点走。两者相遇时即环的头
        }
        
        return slow;
        */
    }
};
