// Given a string, find the length of the longest substring without repeating characters.
//
//
// Example 1:
//
//
// Input: "abcabcbb"
// Output: 3 
// Explanation: The answer is "abc", with the length of 3. 
//
//
//
// Example 2:
//
//
// Input: "bbbbb"
// Output: 1
// Explanation: The answer is "b", with the length of 1.
//
//
//
// Example 3:
//
//
// Input: "pwwkew"
// Output: 3
// Explanation: The answer is "wke", with the length of 3. 
//              Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
//
//
//
//
//


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       int ans=0,left=-1,len=s.size();
        unordered_map<int,int> m;
        for(int i=0;i<len;i++){
            if(m.count(s[i]) && m[s[i]]>left) left = m[s[i]]; //出现相同字符，则将left滑动到第一次出现该字符的位置
            m[s[i]] = i; //记录字符及其索引
            ans = max(ans,i-left);
        }
        
        return ans;
    }
};
