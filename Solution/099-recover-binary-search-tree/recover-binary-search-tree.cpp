// Two elements of a binary search tree (BST) are swapped by mistake.
//
// Recover the tree without changing its structure.
//
// Example 1:
//
//
// Input: [1,3,null,null,2]
//
//    1
//   /
//  3
//   \
//    2
//
// Output: [3,1,null,null,2]
//
//    3
//   /
//  1
//   \
//    2
//
//
// Example 2:
//
//
// Input: [3,1,4,null,null,2]
//
//   3
//  / \
// 1   4
//    /
//   2
//
// Output: [2,1,4,null,null,3]
//
//   2
//  / \
// 1   4
//    /
//   3
//
//
// Follow up:
//
//
// 	A solution using O(n) space is pretty straight forward.
// 	Could you devise a constant space solution?
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
class Solution {
public:
    void recoverTree(TreeNode* root) {
        //主要思想是BST中序遍历的有序性。
        //eg. 中序遍历为1324,第一个被交换的节点是3，因为3>2,第二个被交换的节点是2，因为2<3。通过中序遍历找到应该交换的两个节点即可。
        //这道题要求O(1)的空间复杂度，而中序遍历的递归和迭代方法都需要栈空间。所以这里需要用到http://www.cnblogs.com/AnnieKim/archive/2013/06/15/morristraversal.html 
        TreeNode* first = NULL,*second = NULL,*parent = NULL;
        TreeNode* cur,*pre;
        cur = root;
        while(cur) {
            //开始遍历
            if(cur->left==NULL) {
                //这是当前中序遍历要输出的点,判断是否有序
                if(parent && parent->val > cur->val) {
                    if(!first) first = parent; //找到第一个需要交换的点，以后就不改变了
                    second = cur;  //第二个需要的节点是最后一个符合情况需要被交换的节点
                }
                parent = cur;
                cur = cur->right;  //向右节点遍历
            }
            else {
                //找cur的左子树中的中序遍历顺序的cur的上一个节点
                pre = cur->left;
                while(pre->right && pre->right != cur) pre = pre->right;
                if(pre->right == NULL) {
                    //将上一个节点的右节点连接到当前节点
                    pre->right = cur;
                    cur = cur->left;
                }
                else{
                    //恢复右节点
                    pre->right = NULL;
                    //当前点是中序遍历的输出点
                    if (parent->val > cur->val) {
                        if (!first) first = parent;
                        second = cur;
                    }
                    parent = cur;
                    cur = cur->right;
                }
            }
        }
        swap(first->val,second->val);
    }
};
