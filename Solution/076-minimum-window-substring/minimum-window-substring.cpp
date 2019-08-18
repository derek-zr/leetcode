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
        string ans = "";
        vector<int> cnts(256,0);
        int tmp_len = 0, min_len = INT_MAX, left = 0;
        
        //统计t中字符出现的次数
        for(char c : t) ++cnts[c];
        
        //遍历s字符串
        for(int i=0;i<s.size();i++) {
            if(--cnts[s[i]] >= 0) ++tmp_len; //s[i]在t中出现了
            while(tmp_len == t.size()){  //此时的窗口含有全部t的字符，下面开始滑动窗口
                //cout<<i-left+1<<endl;
                if(min_len > i-left+1) {
                    min_len = i-left+1;
                    ans = s.substr(left,min_len);
                }
                if(++cnts[s[left]] > 0) --tmp_len; //移动的left字符出现在t中，此时不valid
                ++left;
            }
        }
        
        return ans;
    }
};
