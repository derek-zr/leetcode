// The count-and-say sequence is a sequence of digit strings defined by the recursive formula:
//
//
// 	countAndSay(1) = "1"
// 	countAndSay(n) is the way you would "say" the digit string from countAndSay(n-1), which is then converted into a different digit string.
//
//
// To determine how you "say" a digit string, split it into the minimal number of groups so that each group is a contiguous section all of the same character. Then for each group, say the number of characters, then say the character. To convert the saying into a digit string, replace the counts with a number and concatenate every saying.
//
// For example, the saying and conversion for digit string "3322251":
//
// Given a positive integer n, return the nth term of the count-and-say sequence.
//
//  
// Example 1:
//
//
// Input: n = 1
// Output: "1"
// Explanation: This is the base case.
//
//
// Example 2:
//
//
// Input: n = 4
// Output: "1211"
// Explanation:
// countAndSay(1) = "1"
// countAndSay(2) = say "1" = one 1 = "11"
// countAndSay(3) = say "11" = two 1's = "21"
// countAndSay(4) = say "21" = one 2 + one 1 = "12" + "11" = "1211"
//
//
//  
// Constraints:
//
//
// 	1 <= n <= 30
//
//


/*
 * [38] Count and Say
 *
 * https://leetcode.com/problems/count-and-say/description/
 *
 * algorithms
 * Easy (37.74%)
 * Total Accepted:    216.4K
 * Total Submissions: 573.4K
 * Testcase Example:  '1'
 *
 * The count-and-say sequence is the sequence of integers with the first five
 * terms as following:
 * 
 * 1.     1
 * 2.     11
 * 3.     21
 * 4.     1211
 * 5.     111221
 * 
 * 
 * 
 * 1 is read off as "one 1" or 11.
 * 11 is read off as "two 1s" or 21.
 * 21 is read off as "one 2, then one 1" or 1211.
 * 
 * 
 * 
 * Given an integer n, generate the nth term of the count-and-say sequence.
 * 
 * 
 * 
 * Note: Each term of the sequence of integers will be represented as a
 * string.
 * 
 * 
 * Example 1:
 * 
 * Input: 1
 * Output: "1"
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: 4
 * Output: "1211"
 * 
 * 
 */
class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) {
            return "1";
        } else {
            string output = countAndSay(n - 1), result = "";
            int index = 0;
            while (index < output.size()) {
                char current = output[index];
                int cursor = index, count = 0;
                while (output[cursor] == current && cursor < output.size()) {
                    cursor++; count++;
                }
                char number = count + '0';
                result += number;
                result += current;
                index += count;
            }
            return result;
        }
    }
};

