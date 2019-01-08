// Given a directed, acyclic graph of N nodes.  Find all possible paths from node 0 to node N-1, and return them in any order.
//
// The graph is given as follows:  the nodes are 0, 1, ..., graph.length - 1.  graph[i] is a list of all nodes j for which the edge (i, j) exists.
//
//
// Example:
// Input: [[1,2], [3], [3], []] 
// Output: [[0,1,3],[0,2,3]] 
// Explanation: The graph looks like this:
// 0--->1
// |    |
// v    v
// 2--->3
// There are two paths: 0 -> 1 -> 3 and 0 -> 2 -> 3.
//
//
// Note:
//
//
// 	The number of nodes in the graph will be in the range [2, 15].
// 	You can print different paths in any order, but you should keep the order of nodes inside one path.
//
//


class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int nodes=graph.size();
        vector<vector<int>> ans;
        vector<int> way;
        vector<vector<bool>> roads(nodes,vector<bool>(nodes,false));
        for(int i=0;i<nodes;i++){
            for(int num : graph[i]){
                roads[i][num]=true;
            }
        }
        dfs(0,nodes,ans,roads,way);
        return ans;
    }
    void dfs(int node,int nodes,vector<vector<int>>& ans,vector<vector<bool>>& roads,vector<int>& way){
        way.push_back(node);
        if(node==(nodes-1)) {ans.push_back(way);}
        for(int i=1;i<nodes;i++){
            if(roads[node][i]) {
                dfs(i,nodes,ans,roads,way);
                
            }
        }
        way.pop_back();
        return;
    }
};
