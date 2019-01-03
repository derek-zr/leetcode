// Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.
//
// Design an algorithm to serialize and deserialize a binary search tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary search tree can be serialized to a string and this string can be deserialized to the original tree structure.
//
// The encoded string should be as compact as possible.
//
// Note: Do not use class member/global/static variables to store states. Your serialize and deserialize algorithms should be stateless.
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
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans;
        preOrder(root,ans);
        return ans;
    }
    
    void preOrder(TreeNode* root, string& ans){
        if(!root) return;
        char buf[4];   //32bit,可以表示任何int
        memcpy(buf,&(root->val),sizeof(int));
        for(int i=0;i<4;i++) {ans.push_back(buf[i]);}
        preOrder(root->left,ans);
        preOrder(root->right,ans);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int pos = 0;
        return dePreOrder(data,pos,INT_MIN,INT_MAX);
    }
    
    TreeNode* dePreOrder(string data,int& pos,int minvalue,int maxvalue){
        if(pos>=data.size()) return NULL;
        int value;
        memcpy(&value,&data[pos],sizeof(int));
        if(value < minvalue || value > maxvalue) return NULL;  //二叉树的性质，不满足则不在当前子树
        TreeNode* node = new TreeNode(value);
        pos += sizeof(int);
        node->left = dePreOrder(data,pos,minvalue,value);   //左子树小于root
        node->right = dePreOrder(data,pos,value,maxvalue);   //右子树大于root

        return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
