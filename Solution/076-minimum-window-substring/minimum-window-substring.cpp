// Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).
//
// Example:
//
//
// Input: S = "ADOBECODEBANC", T = "ABC"
// Output: "BANC"
//
//
// Note:
//
//
// 	If there is no such window in S that covers all characters in T, return the empty string "".
// 	If there is such window, you are guaranteed that there will always be only one unique minimum window in S.
//
//


class Solution {
public:
    string minWindow(string s, string t) {
        //滑动窗口法
        string ans = "";
        int min_len = INT_MAX;
        int left = 0, len = s.size();
        vector<int> cnts(256, 0);
        //统计t中出现的字符次数
        for(char c : t)  ++cnts[c];
        
        int cur_len = 0;
        //滑动窗口
        for (int i = 0 ; i < len; ++i) {
            if (cnts[s[i]]-- > 0) ++cur_len;
            //找到一个valid的窗口
            while (cur_len == t.size()) {
                if (i - left + 1< min_len) {
                    min_len = i - left + 1;
                    ans = s.substr(left, min_len);
                } 
                //移动left
                if (++cnts[s[left]] > 0)  --cur_len; 
                ++left;
            }
        }
        return ans;
    }
};
