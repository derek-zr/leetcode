// Given a string, sort it in decreasing order based on the frequency of characters.
//
// Example 1:
//
// Input:
// "tree"
//
// Output:
// "eert"
//
// Explanation:
// 'e' appears twice while 'r' and 't' both appear once.
// So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
//
//
//
// Example 2:
//
// Input:
// "cccaaa"
//
// Output:
// "cccaaa"
//
// Explanation:
// Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
// Note that "cacaca" is incorrect, as the same characters must be together.
//
//
//
// Example 3:
//
// Input:
// "Aabb"
//
// Output:
// "bbAa"
//
// Explanation:
// "bbaA" is also a valid answer, but "Aabb" is incorrect.
// Note that 'A' and 'a' are treated as two different characters.
//
//


class Solution {
public:
    string frequencySort(string s) {
        //用两个map，先统计char，int的对应关系，再得到int，string的对应关系，得到结果
        unordered_map<char,int> m1;
        for(char c : s) ++m1[c];
        //再得到次数和string的对应关系
        map<int,string> m2;
        for(auto &it : m1) {
            int cnt = it.second;
            char tmp = it.first;
            m2[cnt] += string(cnt,tmp);
        }
        string ans;
        //map默认key从小到大排序
        for(auto it = m2.rbegin(); it != m2.rend(); ++it) {
            ans += it->second;
        }
        return ans;
    }
};
