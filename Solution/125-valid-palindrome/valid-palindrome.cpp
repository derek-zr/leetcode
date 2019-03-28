// Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
//
// Note: For the purpose of this problem, we define empty string as valid palindrome.
//
// Example 1:
//
//
// Input: "A man, a plan, a canal: Panama"
// Output: true
//
//
// Example 2:
//
//
// Input: "race a car"
// Output: false
//
//


class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.size()-1;
        while(left<=right){
            if(!isalnum(s[left])) left++;
            else if(!isalnum(s[right])) right--;
            else if((s[left] + 32 - 'a') %32 != (s[right] + 32 - 'a') % 32) return false;
            else {
                ++left;
                --right;
            }
        }
        
        return true;
    }
};
