// Given a list of airline tickets represented by pairs of departure and arrival airports [from, to], reconstruct the itinerary in order. All of the tickets belong to a man who departs from JFK. Thus, the itinerary must begin with JFK.
//
// Note:
//
//
// 	If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when read as a single string. For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].
// 	All airports are represented by three capital letters (IATA code).
// 	You may assume all tickets form at least one valid itinerary.
//
//
// Example 1:
//
//
// Input: [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
// Output: ["JFK", "MUC", "LHR", "SFO", "SJC"]
//
//
// Example 2:
//
//
// Input: [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
// Output: ["JFK","ATL","JFK","SFO","ATL","SFO"]
// Explanation: Another possible reconstruction is ["JFK","SFO","ATL","JFK","ATL","SFO"].
//              But it is larger in lexical order.
//
//


class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        //dfs
        vector<string> ans;
        unordered_map<string,multiset<string>> m; //这里用multiset，允许出现多个相同的键值，且自动排序。可能会出现相同的行程单
        
        for(auto t : tickets) {
            m[t[0]].insert(t[1]);
        }
        
        dfs(m,ans,"JFK");
        reverse(ans.begin(),ans.end());
        return ans;
    }
    
    void dfs(unordered_map<string,multiset<string>> &m, vector<string> &ans, string st) {
        while (m[st].size()) {
            string next = *m[st].begin();
            m[st].erase(m[st].begin());  //遍历完即删除，避免重复使用路径
            dfs(m,ans,next);
        }
        ans.push_back(st);
    }
};
