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
        //滑动窗口，并记录窗口内字符的出现次数
        vector<int> cnts(256,0);
        int left = 0 , right = 0;
        int ans = 0 , repeat_cha = 0;
        //遍历
        while(right < s.size()) {
            if(cnts[s[right++]]++ > 0) ++repeat_cha; //出现过同样的字符
            while(repeat_cha > 0) {
                //移动左窗口
                if(cnts[s[left++]]-- > 1) --repeat_cha;
            }
            ans = max(ans,right - left);
        }
        return ans;
    }
};
