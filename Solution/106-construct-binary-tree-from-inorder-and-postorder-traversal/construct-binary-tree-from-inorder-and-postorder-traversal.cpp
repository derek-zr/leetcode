// Given inorder and postorder traversal of a tree, construct the binary tree.
//
// Note:
// You may assume that duplicates do not exist in the tree.
//
// For example, given
//
//
// inorder = [9,3,15,20,7]
// postorder = [9,15,7,20,3]
//
// Return the following binary tree:
//
//
//     3
//    / \
//   9  20
//     /  \
//    15   7
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
    /*根据：后序数组的顺序是左·右·根
    得到性质1：通过简单观察后序数组的最后一个元素，我们就能知道树的根节点是什么。

    OK那我现在想知道这个根节点的左节点和右节点分别是什么？
    我们都知道左节点可以看做是左侧子树的根，右节点可以看做是右侧子树的根。那我只需要找到代表左侧子树的后序子数组，以及代表右侧子树的后序数组就好了，通过观察这两个后序子数组，就能知道左节点和右节点是什么。

    这时候引入另一个前提：

    根据：中序数组的顺序是左·根·右
    得到性质2：中序数组中，根左侧的元素均属于左数组，根右侧的元素均属于右数组。

    既然我们知道根元素是哪一个，利用中序数组，我们就知道了左子树有多少个元素，右子树有多少个元素。
    拿着这两个数据，回到后序数组，我们就能把后序数组分为三个部分：

    [左子树的节点们][右子树的节点们][根]

    这样，根据性质1，你就找到了根节点的左右子节点。
    重复上述步骤，你就得到了一棵二叉树。*/
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return helper(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1);
    }
    
    TreeNode* helper(vector<int>& inorder,int left_in,int right_in, vector<int>& postorder,int left_po,int right_po){
        if(left_in>right_in || left_po>right_po) return NULL;
        TreeNode* root = new TreeNode(postorder[right_po]);
        int i = 0;
        for(i;i<inorder.size();i++){
            if(inorder[i] == root->val) break;
        }
        root->left = helper(inorder,left_in,i-1,postorder,left_po,left_po+i-1-left_in);
        root->right = helper(inorder,i+1,right_in,postorder,left_po+i-left_in,right_po-1);
        return root;
    }
};
