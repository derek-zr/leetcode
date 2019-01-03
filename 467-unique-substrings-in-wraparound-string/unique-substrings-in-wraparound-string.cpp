// Consider the string s to be the infinite wraparound string of "abcdefghijklmnopqrstuvwxyz", so s will look like this: "...zabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcd....".
//
// Now we have another string p. Your job is to find out how many unique non-empty substrings of p are present in s. In particular, your input is the string p and you need to output the number of different non-empty substrings of p in the string s.
//
// Note: p consists of only lowercase English letters and the size of p might be over 10000.
//
// Example 1:
//
// Input: "a"
// Output: 1
//
// Explanation: Only the substring "a" of string "a" is in the string s.
//
//
//
// Example 2:
//
// Input: "cac"
// Output: 2
// Explanation: There are two substrings "a", "c" of string "cac" in the string s.
//
//
//
// Example 3:
//
// Input: "zab"
// Output: 6
// Explanation: There are six substrings "z", "a", "b", "za", "ab", "zab" of string "zab" in the string s.
//
//


class Solution {
public:
    //找到以每个字符结尾的最长连续字符串长度(zab……z)
    //eg. for zab
    // cnt(z)=1, cnt(a)=2(za长度潜在的包含了字串a), cnt(b)=3(zab长度潜在包含了b,zb)
    int findSubstringInWraproundString(string p) {
        vector<int> cnts(26,0);
        int len = p.size();
        if(len==0) return 0;
        int contLen =0;
        for(int i=0;i<len;i++){
            if(i>0 && p[i]==p[i-1]+1 || p[i-1]-p[i]==25) contLen++;
            else contLen = 1;
            cnts[p[i]-'a'] = max(cnts[p[i]-'a'],contLen);
        }
        return accumulate(cnts.begin(),cnts.end(),0);
    }
};
