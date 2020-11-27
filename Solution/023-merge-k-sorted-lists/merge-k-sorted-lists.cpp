// You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
//
// Merge all the linked-lists into one sorted linked-list and return it.
//
//  
// Example 1:
//
//
// Input: lists = [[1,4,5],[1,3,4],[2,6]]
// Output: [1,1,2,3,4,4,5,6]
// Explanation: The linked-lists are:
// [
//   1->4->5,
//   1->3->4,
//   2->6
// ]
// merging them into one sorted list:
// 1->1->2->3->4->4->5->6
//
//
// Example 2:
//
//
// Input: lists = []
// Output: []
//
//
// Example 3:
//
//
// Input: lists = [[]]
// Output: []
//
//
//  
// Constraints:
//
//
// 	k == lists.length
// 	0 <= k <= 10^4
// 	0 <= lists[i].length <= 500
// 	-10^4 <= lists[i][j] <= 10^4
// 	lists[i] is sorted in ascending order.
// 	The sum of lists[i].length won't exceed 10^4.
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
