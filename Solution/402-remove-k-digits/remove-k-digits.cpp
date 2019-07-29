// Given a non-negative integer num represented as a string, remove k digits from the number so that the new number is the smallest possible.
//
//
// Note:
//
// The length of num is less than 10002 and will be ≥ k.
// The given num does not contain any leading zero.
//
//
//
//
// Example 1:
//
// Input: num = "1432219", k = 3
// Output: "1219"
// Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
//
//
//
// Example 2:
//
// Input: num = "10200", k = 1
// Output: "200"
// Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
//
//
//
// Example 3:
//
// Input: num = "10", k = 2
// Output: "0"
// Explanation: Remove all the digits from the number and it is left with nothing which is 0.
//
//


class Solution {
public:
    string removeKdigits(string num, int k) {
        //单调栈的思想。
        //eg. 1432219，当3入栈时，为了保证栈的单调，需要删除4
        string ans = "";
        int len = num.size() , remain = len-k;
        
        //进栈，这里用string代替栈
        for(char c : num) {
            while(k && !ans.empty() && ans.back() > c) {
                ans.pop_back();
                --k;
            }
            ans.push_back(c);
        }
        //resize到应返回的大小
        ans.resize(remain);
        //cout<<ans.size();
        while(!ans.empty() && ans[0] == '0') ans.erase(ans.begin());
        return ans.empty() ? "0" : ans;
    }
};
