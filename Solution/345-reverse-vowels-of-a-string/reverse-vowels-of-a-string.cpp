// Write a function that takes a string as input and reverse only the vowels of a string.
//
// Example 1:
//
//
// Input: "hello"
// Output: "holle"
//
//
//
// Example 2:
//
//
// Input: "leetcode"
// Output: "leotcede"
//
//
// Note:
// The vowels does not include the letter "y".
//
//  
//


class Solution {
public:
    string reverseVowels(string s) {
        int left = 0, right= s.size() - 1;
        while (left < right) {
            if (isVowel(s[left]) && isVowel(s[right])) {
                swap(s[left++], s[right--]);
            } else if (isVowel(s[left])) {
                --right;
            } else {
                ++left;
            }
        }
        return s;
    }
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }
};
