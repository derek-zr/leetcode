// There are a total of n courses you have to take, labeled from 0 to n-1.
//
// Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]
//
// Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?
//
// Example 1:
//
//
// Input: 2, [[1,0]] 
// Output: true
// Explanation: There are a total of 2 courses to take. 
//              To take course 1 you should have finished course 0. So it is possible.
//
// Example 2:
//
//
// Input: 2, [[1,0],[0,1]]
// Output: false
// Explanation: There are a total of 2 courses to take. 
//              To take course 1 you should have finished course 0, and to take course 0 you should
//              also have finished course 1. So it is impossible.
//
//
// Note:
//
//
// 	The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
// 	You may assume that there are no duplicate edges in the input prerequisites.
//
//


class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        
        //dfs
        vector<vector<int>> graph(numCourses,vector<int>(0));
        vector<int> visited(numCourses,0);  //0表示未访问，1表示符合要求，-1表示冲突（有环）
        
        for(auto s : prerequisites){
            graph[s.second].push_back(s.first);
        }
        
        for(int i=0;i<numCourses;i++){
            if(!dfs(graph,visited,i)) return false;
        }
        
        return true;
        
        /*
        //bfs 入度。如果遍历后，入度不为0，则说明存在环
        vector<vector<int>> graph(numCourses,vector<int>(0));
        vector<int> input(numCourses,0);
        queue<int> q;
        
        for(auto s : prerequisites){
            graph[s.second].push_back(s.first);
            ++input[s.first];
        }
        
        for(int i=0;i<numCourses;i++){
            if(input[i]==0) q.push(i);  //初始值为所有入度为0的点
        }
        
        while(!q.empty()){
            int tmp = q.front();
            q.pop();
            for(auto a : graph[tmp]){
                --input[a];
                if(input[a]==0) q.push(a);
            }
        }
        
        for(int a : input){
            if(a!=0) return false;
        }
        
        return true;*/
    }
    
    bool dfs(vector<vector<int>>& graph,vector<int>& visited,int i) {
        if(visited[i]==-1) return false;
        if(visited[i]==1)  return true;
        visited[i] = -1;
        
        for(auto a : graph[i]){
            if(!dfs(graph,visited,a)) return false;
        }
        
        visited[i] = 1;
        return true;
    }
};
