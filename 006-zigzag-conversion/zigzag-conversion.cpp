// The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
//
//
// P   A   H   N
// A P L S I I G
// Y   I   R
//
//
// And then read line by line: "PAHNAPLSIIGYIR"
//
// Write the code that will take a string and make this conversion given a number of rows:
//
//
// string convert(string s, int numRows);
//
// Example 1:
//
//
// Input: s = "PAYPALISHIRING", numRows = 3
// Output: "PAHNAPLSIIGYIR"
//
//
// Example 2:
//
//
// Input: s = "PAYPALISHIRING", numRows = 4
// Output: "PINALSIGYAHRPI"
// Explanation:
//
// P     I    N
// A   L S  I G
// Y A   H R
// P     I
//


class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1) return s;
        int len = s.size();
        string ans;
        for(int i=0;i<numRows;i++){
            int first = 2*(numRows-i-1);
            int second = 2 *(i);
            int pos = i;
            if(pos < len) ans += s[pos];
            while(1){
                pos += first;
                if(pos >= len) break;
                if(first) ans += s[pos];
                pos+=second;
                if(pos >= len) break;
                if(second) ans += s[pos];
            }
        }
        return ans;
    }
};
