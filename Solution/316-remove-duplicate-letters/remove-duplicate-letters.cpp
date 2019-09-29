// Given a string which contains only lowercase letters, remove duplicate letters so that every letter appears once and only once. You must make sure your result is the smallest in lexicographical order among all possible results.
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
//


class Solution {
public:
    string removeDuplicateLetters(string s) {
        //类似于维持一个单调序列，保证符合条件的情况时，使得答案中的字母尽量按照顺序单调排列
        //使用cnts和visited数组来表示某个字符的出现次数和访问情况
        vector<int> cnts(26, 0);
        vector<int> visited(26, 0);
        string ans; 
        for (char c : s)  ++cnts[c - 'a'];
        
        //开始遍历
        for (char c : s) {
            --cnts[c - 'a']; 
            if (visited[c - 'a'])  continue;    //说明之前已经访问过，并且排好了位置
            //维持答案的单调性（符合条件的情况下）
            //小于当前ans的最后一个字符，并且ans中的字符后续还会出现，可以先删除，后面再加上
            while (!ans.empty() && c < ans.back() && cnts[ans.back() - 'a']) {
                visited[ans.back() - 'a'] = 0;    //需要重新访问，安排位置
                ans.pop_back();
            }
            ans += c;
            visited[ans.back() - 'a'] = 1;
        }
        
        return ans;
    }
};
