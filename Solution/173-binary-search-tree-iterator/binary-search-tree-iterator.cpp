// Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.
//
// Calling next() will return the next smallest number in the BST.
//
//  
//
//
//
//
// Example:
//
//
//
//
// BSTIterator iterator = new BSTIterator(root);
// iterator.next();    // return 3
// iterator.next();    // return 7
// iterator.hasNext(); // return true
// iterator.next();    // return 9
// iterator.hasNext(); // return true
// iterator.next();    // return 15
// iterator.hasNext(); // return true
// iterator.next();    // return 20
// iterator.hasNext(); // return false
//
//
//  
//
// Note:
//
//
// 	next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.
// 	You may assume that next() call will always be valid, that is, there will be at least a next smallest number in the BST when next() is called.
//
//


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    //BST的中序遍历就是有序的
    //这道题主要是用非递归方法进行中序遍历，用辅助栈
    BSTIterator(TreeNode* root) {
        while(root) {
            s.push(root);
            root = root->left; //压入左节点
        }
    }
    
    /** @return the next smallest number */
    int next() {
        TreeNode* tmp = s.top();
        s.pop();
        int ans = tmp->val;
        if(tmp->right) {
            tmp = tmp->right;
            while(tmp) {
                s.push(tmp);  //压入底层右节点的左孩子
                tmp = tmp->left;
            }
        }
        return ans;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !s.empty();  //栈内是否还有其他元素
    }
private:
    stack<TreeNode*> s;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
