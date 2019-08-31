// Given an array of strings, group anagrams together.
//
// Example:
//
//
// Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
// Output:
// [
//   ["ate","eat","tea"],
//   ["nat","tan"],
//   ["bat"]
// ]
//
// Note:
//
//
// 	All inputs will be in lowercase.
// 	The order of your output does not matter.
//
//


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> m;
        vector<vector<string>> ans;
        
        for(string s : strs){
            string t = s;
            sort(t.begin(),t.end());    //用sort作为key的效率反而更高emmm
            m[t].push_back(s);
            //m[cnt2string(s)].push_back(s);
        }
        
        for(auto p : m){
            ans.push_back(p.second);
        }
        
        return ans;
    }
    
    string cnt2string(string s){
        vector<int> cnts(26,0);
        string res;
        for(char c : s) cnts[c-'a']++;
        
        for(int i=0;i<26;i++){
            if(cnts[i] != 0) {
                res += to_string(cnts[i])+string(1,'a'+i);
            }
        }
        
        //cout<<res<<endl;
        return res;
    }
    
};
