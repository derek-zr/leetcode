// One way to serialize a binary tree is to use pre-order traversal. When we encounter a non-null node, we record the node's value. If it is a null node, we record using a sentinel value such as #.
//
//
//      _9_
//     /   \
//    3     2
//   / \   / \
//  4   1  #  6
// / \ / \   / \
// # # # #   # #
//
//
// For example, the above binary tree can be serialized to the string "9,3,4,#,#,1,#,#,2,#,6,#,#", where # represents a null node.
//
// Given a string of comma separated values, verify whether it is a correct preorder traversal serialization of a binary tree. Find an algorithm without reconstructing the tree.
//
// Each comma separated value in the string must be either an integer or a character '#' representing null pointer.
//
// You may assume that the input format is always valid, for example it could never contain two consecutive commas such as "1,,3".
//
// Example 1:
//
//
// Input: "9,3,4,#,#,1,#,#,2,#,6,#,#"
// Output: true
//
// Example 2:
//
//
// Input: "1,#"
// Output: false
//
//
// Example 3:
//
//
// Input: "9,#,#,1"
// Output: false


class Solution {
public:
    bool isValidSerialization(string preorder) {
        //观察规律得到：最后一个一定为#，而且除去最后一个#,#的数目和数字的数目应当是相等的
        istringstream in(preorder);
        string t = "";
        int degree = 1;  //最后一个一定为#
        bool degree_zero = false;
        
        while(getline(in,t,',')) {
            if(degree_zero) return false;  //开头为#的情况，直接返回false
            if(t == "#") {
                if(--degree == 0) degree_zero = true;
            }
            else ++degree;
        }
        
        return degree == 0;
    }
};
