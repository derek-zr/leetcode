// Given a string s, find the length of the longest substring without repeating characters.
//
//  
// Example 1:
//
//
// Input: s = "abcabcbb"
// Output: 3
// Explanation: The answer is "abc", with the length of 3.
//
//
// Example 2:
//
//
// Input: s = "bbbbb"
// Output: 1
// Explanation: The answer is "b", with the length of 1.
//
//
// Example 3:
//
//
// Input: s = "pwwkew"
// Output: 3
// Explanation: The answer is "wke", with the length of 3.
// Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
//
//
// Example 4:
//
//
// Input: s = ""
// Output: 0
//
//
//  
// Constraints:
//
//
// 	0 <= s.length <= 5 * 104
// 	s consists of English letters, digits, symbols and spaces.
//
//


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //hashmap建立字符与出现下标间的映射关系，每次更新最长长度即可
        int start = -1, ans = 0;
        vector<int> m(256, -1);
        for (int i = 0; i < s.size(); ++i) {
            //计算当前无重复的最大起始位置, start和上一次这个字符出现的位置比较
            start = max(start, m[s[i]]);
            //更新当前字符的位置
            m[s[i]] = i;
            ans = max(ans, i - start);
        }
        return ans;
        
        /*
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
        */
    }
};
