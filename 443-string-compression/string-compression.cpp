// Given an array of characters, compress it in-place.
//
// The length after compression must always be smaller than or equal to the original array.
//
// Every element of the array should be a character (not int) of length 1.
//
// After you are done modifying the input array in-place, return the new length of the array.
//  
//
// Follow up:
// Could you solve it using only O(1) extra space?
//  
//
// Example 1:
//
//
// Input:
// ["a","a","b","b","c","c","c"]
//
// Output:
// Return 6, and the first 6 characters of the input array should be: ["a","2","b","2","c","3"]
//
// Explanation:
// "aa" is replaced by "a2". "bb" is replaced by "b2". "ccc" is replaced by "c3".
//
//
//  
//
// Example 2:
//
//
// Input:
// ["a"]
//
// Output:
// Return 1, and the first 1 characters of the input array should be: ["a"]
//
// Explanation:
// Nothing is replaced.
//
//
//  
//
// Example 3:
//
//
// Input:
// ["a","b","b","b","b","b","b","b","b","b","b","b","b"]
//
// Output:
// Return 4, and the first 4 characters of the input array should be: ["a","b","1","2"].
//
// Explanation:
// Since the character "a" does not repeat, it is not compressed. "bbbbbbbbbbbb" is replaced by "b12".
// Notice each digit has it's own entry in the array.
//
//
//  
//
// Note:
//
//
// 	All characters have an ASCII value in [35, 126].
// 	1 <= len(chars) <= 1000.
//
//


class Solution {
public:
    int compress(vector<char>& a) {
        
        int i = 0, cnt = 0, t = 0;
        for (int j = 0; j < a.size(); ++j) if (j+1 == a.size() || a[j+1] != a[j]) {
            int m = t;
            a[t++] = a[j];
            if (j >= i + 1) {
                string s = to_string(j-i+1);
                for (char c:s) a[t++] = c;
            }
            i = j + 1;
            cnt += t-m;
        }
        return cnt;
        
        /*这部分不知道为什么run code时答案正确，submit时候就出错。。。
        if(chars.size()==1||chars.size()==0) return chars.size();
        int ans = 0;
        int com_index = 0;
        for(int i=1;i<=chars.size();){
            int tmp_cnt = 1;
            chars[com_index++] = chars[i-1];
            while(chars[i]==chars[i-1]) {tmp_cnt++;i++;}
            if(tmp_cnt==1){i++;}
            else {
                string s = to_string(tmp_cnt);
                int j=0;
                while(j<s.size()) chars[com_index++] = s[j++];
                i++;
            }
        }
        return com_index;
        */
    }
};
