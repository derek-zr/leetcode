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
        //两个链表的排序很好实现，所以这里考虑分治法，不断合并两个list，得到最终结果
        int len = lists.size();
        if(len == 0) return NULL;
        //两两合并
        while(len > 1) {
            int interval = (len+1) / 2;   //考虑奇数情况
            for(int i = 0; i < len/2; ++i) {
                lists[i] = merge2Lists(lists[i], lists[i+interval]);
            }
            len = interval;  //继续递归合并
        }
        return lists[0];
    }
    
    ListNode* merge2Lists(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* cur = dummy;
        //比较
        while(l1 && l2) {
            if(l1->val > l2->val) {
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
