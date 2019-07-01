// Given a string s, you are allowed to convert it to a palindrome by adding characters in front of it. Find and return the shortest palindrome you can find by performing this transformation.
//
// Example 1:
//
//
// Input: "aacecaaa"
// Output: "aaacecaaa"
//
//
// Example 2:
//
//
// Input: "abcd"
// Output: "dcbabcd"


class Solution {
public:
    string shortestPalindrome(string s) {
        /**/
        //第一种解法，比较tricky。
        //核心思想如下：对于一个字符串，其回文串一定可以通过reverse(s)+s得到，但这个显然不一定是最短的。对于aabcc来说，aa是一个回文的suffix，没必要重复添加在新串中（ccbaabcc即可，把aa放在中间）。所以我们要做的就是找到这个回文suffix。
        int len = s.size();
        int i = 0, j = len-1;
        //下面的循环比较难想。我们通过这个循环找到了一个切分点i，现在该字符串可以被分为两部分：s(i)一定是需要反转并添加在前面的，而s(0,i)不确定其是不是回文，所以需要递归中处理。
        for(j; j >= 0; --j) {
            if(s[i] == s[j]) ++i;
        }
        if(i == len) return s; //说明当前即为回文串
        string suffix = s.substr(i);
        reverse(suffix.begin(),suffix.end());
        //递归处理0-i的字符串，因为不确定其是否一定为回文串
        return suffix + shortestPalindrome(s.substr(0,i)) + s.substr(i);
    }
};
