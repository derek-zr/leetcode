// Given a list accounts, each element accounts[i] is a list of strings, where the first element accounts[i][0] is a name, and the rest of the elements are emails representing emails of the account.
//
// Now, we would like to merge these accounts.  Two accounts definitely belong to the same person if there is some email that is common to both accounts.  Note that even if two accounts have the same name, they may belong to different people as people could have the same name.  A person can have any number of accounts initially, but all of their accounts definitely have the same name.
//
// After merging the accounts, return the accounts in the following format: the first element of each account is the name, and the rest of the elements are emails in sorted order.  The accounts themselves can be returned in any order.
//
// Example 1:
//
// Input: 
// accounts = [["John", "johnsmith@mail.com", "john00@mail.com"], ["John", "johnnybravo@mail.com"], ["John", "johnsmith@mail.com", "john_newyork@mail.com"], ["Mary", "mary@mail.com"]]
// Output: [["John", 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com'],  ["John", "johnnybravo@mail.com"], ["Mary", "mary@mail.com"]]
// Explanation: 
// The first and third John's are the same person as they have the common email "johnsmith@mail.com".
// The second John and Mary are different people as none of their email addresses are used by other accounts.
// We could return these lists in any order, for example the answer [['Mary', 'mary@mail.com'], ['John', 'johnnybravo@mail.com'], 
// ['John', 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com']] would still be accepted.
//
//
//
// Note:
// The length of accounts will be in the range [1, 1000].
// The length of accounts[i] will be in the range [1, 10].
// The length of accounts[i][j] will be in the range [1, 30].
//


class Solution {
public:
    //union find
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string,string> parents;
        unordered_map<string,string> owners;
        unordered_map<string,set<string>> unions;
        
        //parents初始化为自身
        for(int i=0;i<accounts.size();i++){
            for(int j=1;j<accounts[i].size();j++){
                parents[accounts[i][j]] = accounts[i][j];
                owners[accounts[i][j]] = accounts[i][0];
            }
        }
        //将accounts[i]中的每个邮箱链接到第一个邮箱
        for(int i=0;i<accounts.size();i++){
            string parent = find(accounts[i][1],parents);
            for(int j=2;j<accounts[i].size();j++){
                parents[find(accounts[i][j],parents)] = parent;
            }
        }
        //for (auto parent : parents){
        //    cout<<parent.first<<parent.second<<endl;
        //}
        
        //同一个parents的加入union
        for(int i=0;i<accounts.size();i++){
            for(int j=1;j<accounts[i].size();j++){
                unions[find(accounts[i][j],parents)].insert(accounts[i][j]);
            }
        }
        vector<vector<string>> ans;
        for(auto u : unions){
            vector<string> tmp(u.second.begin(),u.second.end());
            tmp.insert(tmp.begin(),owners[u.first]);
            ans.push_back(tmp);
        }
        return ans;
    }
    
    string find(string s,unordered_map<string,string> &parents){
        return parents[s] == s ? s : find(parents[s],parents);
    }
};
