//
// Given a string and a string dictionary, find the longest string in the dictionary that can be formed by deleting some characters of the given string. If there are more than one possible results, return the longest word with the smallest lexicographical order. If there is no possible result, return the empty string.
//
// Example 1:
//
// Input:
// s = "abpcplea", d = ["ale","apple","monkey","plea"]
//
// Output: 
// "apple"
//
//
//
//
// Example 2:
//
// Input:
// s = "abpcplea", d = ["a","b","c"]
//
// Output: 
// "a"
//
//
//
// Note:
//
// All the strings in the input will only contain lower-case letters.
// The size of the dictionary won't exceed 1,000.
// The length of all the strings in the input won't exceed 1,000.
//
//


class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        //自定义排序函数，并且逐个比较
        sort(d.begin(), d.end(), [](string a, string b){
            //长度优先，相同长度比较字符顺序
            if (a.size() == b.size()) return a < b;
            return a.size() > b.size();
        });
        for (string str : d) {
            int i = 0;
            for (char c : s) {
                if (i < str.size() && c == str[i]) ++i;
            }
            if (i == str.size()) return str;
        }
        return "";
    }
};
