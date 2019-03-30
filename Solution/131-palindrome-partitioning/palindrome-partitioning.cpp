// Given a string s, partition s such that every substring of the partition is a palindrome.
//
// Return all possible palindrome partitioning of s.
//
// Example:
//
//
// Input: "aab"
// Output:
// [
//   ["aa","b"],
//   ["a","a","b"]
// ]
//
//


class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> tmp;
        dfs(s,0,ans,tmp);
        return ans;
    }
    
    void dfs(string& s,int start,vector<vector<string>>& ans,vector<string>& tmp){
        if(start==s.size()) {ans.push_back(tmp);return;}
        for(int i=start;i<s.size();i++){
            if(!isPali(s,start,i)) continue;
            tmp.push_back(s.substr(start,i-start+1));
            dfs(s,i+1,ans,tmp);
            tmp.pop_back();
        }
    }
    
    bool isPali(string& s , int start, int end){
        while(start<end){
            if(s[start]!=s[end]) return false;
            ++start;
            --end;
        }
        
        return true;
    }
};
