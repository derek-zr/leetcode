// Given a string which contains only lowercase letters, remove duplicate letters so that every letter appear once and only once. You must make sure your result is the smallest in lexicographical order among all possible results.
//
// Example 1:
//
//
// Input: "bcabc"
// Output: "abc"
//
//
// Example 2:
//
//
// Input: "cbacdcbc"
// Output: "acdb"
//


class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> cnts(26,0);
        vector<int> visited(26,0);
        string ans = "0";   //先放个0，方便与第一个字符进行比较
        for(auto letter:s) ++cnts[letter-'a'];
        for(auto letter:s){
            --cnts[letter-'a']; //先减去一个计数
            if(visited[letter-'a']) continue;
            while(letter<ans.back() && cnts[ans.back()-'a']){  //当前的letter小于ans中的最后一个字母且最后一个字母后面还会出现，则可以先删除这个字母，等后面再加上
                visited[ans.back()-'a']=0;
                ans.pop_back();
            }
            ans += letter;
            visited[letter-'a'] = 1;
        }
        
        return ans.substr(1);
        
    }
};
