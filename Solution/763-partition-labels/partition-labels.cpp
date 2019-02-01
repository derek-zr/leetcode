//
// A string S of lowercase letters is given.  We want to partition this string into as many parts as possible so that each letter appears in at most one part, and return a list of integers representing the size of these parts.
//
//
// Example 1:
//
// Input: S = "ababcbacadefegdehijhklij"
// Output: [9,7,8]
// Explanation:
// The partition is "ababcbaca", "defegde", "hijhklij".
// This is a partition so that each letter appears in at most one part.
// A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits S into less parts.
//
//
//
// Note:
// S will have length in range [1, 500].
// S will consist of lowercase letters ('a' to 'z') only.
//


class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> ans,pos(26); //pos用于记录每个letter最后出现的位置
        int strlen=S.size();
        for(int i=0;i<strlen;i++) pos[S[i]-'a']=i;
        int last_index=0;
        int index=INT_MIN;
        for(int i=0;i<strlen;i++){
            index=max(index,pos[S[i]-'a']);
            if(index==i){
                ans.push_back(i-last_index+1);
                last_index=i+1;
            }
        }
        return ans;
    }
};
