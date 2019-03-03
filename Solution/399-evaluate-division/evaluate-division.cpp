//
// Equations are given in the format A / B = k, where  A and B are variables represented as strings, and k is a real number (floating point number). Given some queries, return the answers. If the answer does not exist, return -1.0.
//
// Example:
// Given  a / b = 2.0, b / c = 3.0. queries are:  a / c = ?,  b / a = ?, a / e = ?,  a / a = ?, x / x = ? . return  [6.0, 0.5, -1.0, 1.0, -1.0 ].
//
//
// The input is:  vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries , where equations.size() == values.size(), and the values are positive. This represents the equations. Return  vector<double>.
//
//
// According to the example above:
// equations = [ ["a", "b"], ["b", "c"] ],
// values = [2.0, 3.0],
// queries = [ ["a", "c"], ["b", "a"], ["a", "e"], ["a", "a"], ["x", "x"] ]. 
//
//
//
// The input is always valid. You may assume that evaluating the queries will result in no division by zero and there is no contradiction.
//


class Solution {
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        vector<double> ans;
        unordered_map<string,unordered_map<string,double>> m;
        
        //建图
        for(int i=0;i<equations.size();i++){
            m[equations[i].first][equations[i].second] = values[i];
            m[equations[i].second][equations[i].first] = 1.0 / values[i];
        }
        
        for(auto q : queries){
            unordered_set<string> visited;
            double tmp = dfs(q.first,q.second,visited,m);
            ans.push_back(tmp>0.0 ? tmp : -1.0);
        }
        
        return ans;
    }
    
    double dfs(string s1,string s2,unordered_set<string>& visited,unordered_map<string,unordered_map<string,double>>& m) {
        //if(s1 == s2) return 1.0;  //这里不能加这个返回，否则x/x也会返回1.0
        if(m[s1].count(s2)) return m[s1][s2];
        
        for(auto q : m[s1]){
            if(visited.count(q.first)) continue;
            visited.insert(q.first);
            double tmp =  dfs(q.first,s2,visited,m);
            if(tmp>0.0) return tmp*q.second;
        }
        
        return -1.0;
    }
    
};
