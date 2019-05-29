// Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
//
// For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
//
// Example:
//
//
// Given the sorted linked list: [-10,-3,0,5,9],
//
// One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:
//
//       0
//      / \
//    -3   9
//    /   /
//  -10  5
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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head) return NULL;
        if(!head->next) return new TreeNode(head->val);
        //用快慢指针找到中间节点作为root
        ListNode *slow = head,*fast = head, *pre = head;
        while(fast->next && fast->next->next) {
            pre = slow;  //中间节点的上一个节点，便于断开list
            slow = slow->next;
            fast = fast->next->next;
        }
        fast = slow->next;
        pre->next = NULL;  //断开list
        TreeNode* root = new TreeNode(slow->val);
        //当head不等于slow时，保持左节点为空，不再重复添加
        if(head != slow) root->left = sortedListToBST(head);
        root->right = sortedListToBST(fast);
        return root;
    }
};
