// Given a string S and a character C, return an array of integers representing the shortest distance from the character C in the string.
//
// Example 1:
//
//
// Input: S = "loveleetcode", C = 'e'
// Output: [3, 2, 1, 0, 1, 0, 0, 1, 2, 2, 1, 0]
//
//
//  
//
// Note:
//
//
// 	S string length is in [1, 10000].
// 	C is a single character, and guaranteed to be in string S.
// 	All letters in S and C are lowercase.
//
//


class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        int len=S.size();
        vector<int> ans(len,2*len);
        vector<int> pos;
        
        for(int i=0;i<len;i++){
            if(S[i]==C) pos.push_back(i);
        }
        for(int i=0;i<len;i++){
            if(S[i]==C) ans[i]=0;
            else{
                for(int tmp:pos) ans[i]=min(ans[i],abs(i-tmp)); 
            }
        }
        return ans;
    }
};
