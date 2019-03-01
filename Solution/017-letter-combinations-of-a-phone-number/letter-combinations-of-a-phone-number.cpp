// Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.
//
// A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.
//
//
//
// Example:
//
//
// Input: "23"
// Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
//
//
// Note:
//
// Although the above answer is in lexicographical order, your answer could be in any order you want.
//


class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        vector<string> res;
        string maps[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        letterCombinationsDFS(digits, maps, 0, "", res);
        return res;
    }
    
    void letterCombinationsDFS(string digits, string maps[], int len, string tmp, vector<string> &res){
        if(len == digits.size()) {res.push_back(tmp);return;}
        string s = maps[digits[len] - '0'];
        for(int i = 0;i < s.size(); i++)
            letterCombinationsDFS(digits,maps,len+1,tmp+s[i],res);
    }
};
