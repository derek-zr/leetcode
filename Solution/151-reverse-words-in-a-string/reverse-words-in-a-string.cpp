// Given an input string, reverse the string word by word.
//
//  
//
// Example 1:
//
//
// Input: "the sky is blue"
// Output: "blue is sky the"
//
//
// Example 2:
//
//
// Input: "  hello world!  "
// Output: "world! hello"
// Explanation: Your reversed string should not contain leading or trailing spaces.
//
//
// Example 3:
//
//
// Input: "a good   example"
// Output: "example good a"
// Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.
//
//
//  
//
// Note:
//
//
// 	A word is defined as a sequence of non-space characters.
// 	Input string may contain leading or trailing spaces. However, your reversed string should not contain leading or trailing spaces.
// 	You need to reduce multiple spaces between two words to a single space in the reversed string.
//
//
//  
//
// Follow up:
//
// For C programmers, try to solve it in-place in O(1) extra space.


class Solution {
public:
    string reverseWords(string s) {
        //先反转整个字符串，再对反转后字符串的每一个词反转
        int curIndex = 0,len = s.size();
        reverse(s.begin(),s.end());
        
        for(int i = 0; i < len; ++i) {
            if(s[i] != ' ') {
                if(curIndex != 0) s[curIndex++] = ' ';
                int j = i;
                while(j < len && s[j] != ' ') s[curIndex++] = s[j++];
                reverse(s.begin()+curIndex-(j-i),s.begin()+curIndex);
                i = j;
            }
        }
        
        s.resize(curIndex);
        return s;
    }
};
