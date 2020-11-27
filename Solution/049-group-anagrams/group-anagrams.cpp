// Given an array of strings strs, group the anagrams together. You can return the answer in any order.
//
// An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.
//
//  
// Example 1:
// Input: strs = ["eat","tea","tan","ate","nat","bat"]
// Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
// Example 2:
// Input: strs = [""]
// Output: [[""]]
// Example 3:
// Input: strs = ["a"]
// Output: [["a"]]
//
//  
// Constraints:
//
//
// 	1 <= strs.length <= 104
// 	0 <= strs[i].length <= 100
// 	strs[i] consists of lower-case English letters.
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
