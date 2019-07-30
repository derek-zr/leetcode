// Given a string s that consists of only uppercase English letters, you can perform at most k operations on that string.
//
// In one operation, you can choose any character of the string and change it to any other uppercase English character.
//
// Find the length of the longest sub-string containing all repeating letters you can get after performing the above operations.
//
// Note:
// Both the string's length and k will not exceed 104.
//
// Example 1:
//
//
// Input:
// s = "ABAB", k = 2
//
// Output:
// 4
//
// Explanation:
// Replace the two 'A's with two 'B's or vice versa.
//
//
//  
//
// Example 2:
//
//
// Input:
// s = "AABABBA", k = 1
//
// Output:
// 4
//
// Explanation:
// Replace the one 'A' in the middle with 'B' and form "AABBBBA".
// The substring "BBBB" has the longest repeating letters, which is 4.
//
//
//  
//


class Solution {
public:
    int characterReplacement(string s, int k) {
        //转换一个思路，考虑如下问题：如果不设置替换次数，则对一个字符串，得到一个只有重复字符的串，需要的最少替换次数为len-出现最多的字母的次数
        //这道题设置了最大替换次数，则我们要找的就是一个子串，其len-出现最多的字母的次数<=k
        int len = s.size();
        vector<int> cnts(26,0);
        int maxLetterCnts = 0;  //统计目前为止遍历到的出现最多的字符次数
        int start = 0;  //左边界
        int ans = 0;
        
        for(int i = 0; i < len; ++i) {
            maxLetterCnts = max(maxLetterCnts,++cnts[s[i]-'A']);
            //找到符合条件的子串长度,len-出现最多的字母的次数<=k
            while(i-start+1-maxLetterCnts > k) {
                --cnts[s[start]-'A'];  //注意这里不需要更新maxLetterCnts，因为缩小窗口也不可能找到更大的值（因为之前已经出现过符合题意的这么大的窗口）
                ++start;
            }
            ans = max(ans,i-start+1);
        }
        return ans;
    }
};
