/*
 * [58] Length of Last Word
 *
 * https://leetcode.com/problems/length-of-last-word/description/
 *
 * algorithms
 * Easy (32.08%)
 * Total Accepted:    210.4K
 * Total Submissions: 655.8K
 * Testcase Example:  '"Hello World"'
 *
 * Given a string s consists of upper/lower-case alphabets and empty space
 * characters ' ', return the length of last word in the string.
 * 
 * If the last word does not exist, return 0.
 * 
 * Note: A word is defined as a character sequence consists of non-space
 * characters only.
 * 
 * Example:
 * 
 * Input: "Hello World"
 * Output: 5
 * 
 * 
 */
class Solution {
public:
    int lengthOfLastWord(string s) {
        int len=s.size();
        int i=len-1;
        int ans=0;
        while(s[i]==' ') i--;
        for(i;i>=0;i--){
            if(s[i]!=' ') ans++;
            else break;
        }
        return ans;
    }
};
