// Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.
//
// Example 1:
//
//
// Input: "babad"
// Output: "bab"
// Note: "aba" is also a valid answer.
//
//
// Example 2:
//
//
// Input: "cbbd"
// Output: "bb"
//
//


class Solution {
public:
    string longestPalindrome(string s) {
        int len=s.size();
        string ans;
        string curMax;
        if(len==0) return ans;
        if(len==1) return s;
        for(int i=1;i<len;i++){
            int j=i-1,k=i+1;
            curMax+=s[i];
            while(s[j]==s[i]&&j>=0){curMax+=s[j];j--;}
            while(s[k]==s[i]&&k<len){curMax+=s[k];k++;}
            while(s[j]==s[k]&&j>=0&&k<len){
                curMax=s[j]+curMax+s[k];
                j--;
                k++;
            }
            if(curMax.size()>ans.size()) ans=curMax;
            curMax.clear();
        }
        return ans;
    }
};
