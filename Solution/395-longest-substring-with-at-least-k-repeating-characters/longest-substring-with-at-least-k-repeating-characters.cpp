//
// Find the length of the longest substring T of a given string (consists of lowercase letters only) such that every character in T appears no less than k times.
//
//
// Example 1:
//
// Input:
// s = "aaabb", k = 3
//
// Output:
// 3
//
// The longest substring is "aaa", as 'a' is repeated 3 times.
//
//
//
// Example 2:
//
// Input:
// s = "ababbc", k = 2
//
// Output:
// 5
//
// The longest substring is "ababb", as 'a' is repeated 2 times and 'b' is repeated 3 times.
//
//


class Solution {
public:
    int longestSubstring(string s, int k) {
        //用递归的方法去做
        int len = s.size();
        if(len < k) return 0;
        int cnts[26] = {0};
        for(char c : s) ++cnts[c-'a'];
        
        int left = 0, right = len-1;
        //先过滤头尾字符中出现次数小于k的
        while(left < len && cnts[s[left]-'a'] < k) ++left;
        while(right >= 0 && cnts[s[right]-'a'] < k) --right;
        //cout<<left<<right;
        //再找其中可能符合条件的答案
        int i = left;
        for(i; i <= right; ++i) {
            if(cnts[s[i]-'a'] < k) {  //符合条件的答案里不可能包含小于k次数的字符
                return max(longestSubstring(s.substr(left,i-left+1),k), longestSubstring(s.substr(i+1,right-i),k));  //找左右子字符串中的最大值
            }
        }
        
        if(i == (right+1)) return right-left+1;  //所有字符的次数都大于k，则返回当前整个字符串长度
        else return 0;
        
        /* TLE
        int maxlen = 0;
        unordered_map<int,int> m;
        for(char c : s) ++m[c];
        int allcharktimes = true;
        for(char c :s ) {
            if(m[c] < k){
                allcharktimes = false;
                break;
            }
        }
        if(allcharktimes) return s.size();  //如果所有字符都出现超过k次，则可以直接返回该字符串
        
        //开始遍历字符串找最长长度
        int len = s.size();
        int i = 0;
        while(i <= len-maxlen) {  //如果后面的字符串长度小于当前的maxlen，则没有继续遍历的意义
            if(m[s[i]] < k) { ++i; continue;}  //第一个字符出现次数就小于k,不符合条件
            int j = i;
            int cur_len = 1;
            int cnts[26] = {0};
            while(j++ < len) {
                if(m[s[j]] < k) break;
                else {++cur_len;++cnts[s[j]-'a'];}
            }
            bool isAns = true;
            while(k < 26) {
                if(cnts[k]==0 || cnts[k] >= k) continue;
                else {isAns=false;break;}
            }
            if(isAns) maxlen = max(maxlen,cur_len);
            i = j;
        }
        
        return maxlen;
        */
    }
};
