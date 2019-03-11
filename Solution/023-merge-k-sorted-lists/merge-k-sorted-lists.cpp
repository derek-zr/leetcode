// Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
//
// Example:
//
//
// Input:
// [
//   1->4->5,
//   1->3->4,
//   2->6
// ]
// Output: 1->1->2->3->4->4->5->6
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return NULL;
        int len = lists.size();
        
        while(len>1) {
            int interval = (len+1)/2; //两两匹配,如0-2
            for(int i=0;i<len/2;i++){
                lists[i] = mergeTwoLists(lists[i],lists[i+interval]);
            }
            len = interval;
        }
        
        return lists[0];
        
    }
    
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* cur = dummy;
        while(l1 && l2) {
            if(l1->val>l2->val){
                cur->next = l2;
                l2 = l2->next;
            }
            else {
                cur->next = l1;
                l1 = l1->next;
            }
            
            cur = cur->next;
        }
        
        if(l1) cur->next = l1;
        if(l2) cur->next = l2;
        
        return dummy->next;
    }
    
};
