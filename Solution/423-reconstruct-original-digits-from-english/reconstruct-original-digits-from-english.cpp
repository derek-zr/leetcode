// Given a non-empty string containing an out-of-order English representation of digits 0-9, output the digits in ascending order.
//
// Note:
//
// Input contains only lowercase English letters.
// Input is guaranteed to be valid and can be transformed to its original digits. That means invalid inputs such as "abc" or "zerone" are not permitted.
// Input length is less than 50,000.
//
//
//
// Example 1:
//
// Input: "owoztneoer"
//
// Output: "012"
//
//
//
// Example 2:
//
// Input: "fviefuro"
//
// Output: "45"
//
//


class Solution {
public:
    //"zero", "two", "four", "six", "eight", "one", "three", "five", "seven", "nine"
    string originalDigits(string s) {
        string res = "";
        vector<string> words{"zero", "two", "four", "six", "eight", "one", "three", "five", "seven", "nine"};
        vector<int> nums{0, 2, 4, 6, 8, 1, 3, 5, 7, 9}, cnts(26, 0);
        vector<char> chars{'z', 'w', 'u', 'x', 'g', 'o', 'h', 'f', 's', 'i'};
        for(char c : s) ++cnts[c- 'a'];
        
        for(int i=0;i<10;i++){
            int cnt = cnts[chars[i]-'a'];
            for(char tmp : words[i]) cnts[tmp-'a'] -= cnt;
            while(cnt--) res += (nums[i]+'0');
        }
        
        sort(res.begin(),res.end());
        return res;
    }
};
