// Given a list of non negative integers, arrange them such that they form the largest number.
//
// Example 1:
//
//
// Input: [10,2]
// Output: "210"
//
// Example 2:
//
//
// Input: [3,30,34,5,9]
// Output: "9534330"
//
//
// Note: The result may be very large, so you need to return a string instead of an integer.
//


class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string ans = "";
        sort(nums.begin(),nums.end(),[](int a, int b) { return to_string(a)+to_string(b) > to_string(b)+to_string(a); });
        
        for(int num : nums) {
            ans += to_string(num);
        }
        
        return ans[0] == '0' ? "0" : ans;  // 0000这种情况
    }
};
