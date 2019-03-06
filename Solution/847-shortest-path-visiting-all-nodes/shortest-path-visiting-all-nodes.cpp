// An undirected, connected graph of N nodes (labeled 0, 1, 2, ..., N-1) is given as graph.
//
// graph.length = N, and j != i is in the list graph[i] exactly once, if and only if nodes i and j are connected.
//
// Return the length of the shortest path that visits every node. You may start and stop at any node, you may revisit nodes multiple times, and you may reuse edges.
//
//  
//
//
//
//
// Example 1:
//
//
// Input: [[1,2,3],[0],[0],[0]]
// Output: 4
// Explanation: One possible path is [1,0,2,0,3]
//
// Example 2:
//
//
// Input: [[1],[0,2,4],[1,3,4],[2],[1,2]]
// Output: 4
// Explanation: One possible path is [0,1,4,2,3]
//
//
//  
//
// Note:
//
//
// 	1 <= graph.length <= 12
// 	0 <= graph[i].length < graph.length
//
//


struct State{
    int cur;
    int visit;
    int step;
    
    State(int cur,int visit,int step):cur(cur),visit(visit),step(step){}
};

class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int N = graph.size();
        int ans = 0;
        queue<State> q;
        vector<vector<bool>> visited(1<<N,vector<bool>(N,false)); //visit下，停在某个节点的情况是否被计算过
        for(int i=0;i<N;i++){
            q.push(State(i,1<<i,0));  //用0-1 bit表示是否访问过
            visited[1<<i][i] = true;
        }
        
        while(!q.empty()){
            State tmp = q.front();
            q.pop();
            
            if(tmp.visit == (1<<N)-1){ //说明所有节点已经全部访问过
                ans = tmp.step;  //可以直接返回，因为这是bfs，确保了当前是最短的路径
                break;
            }
            
            for(int node : graph[tmp.cur]){
                int tmp_state = tmp.visit|(1<<node); //加上对应node的状态
                if(!visited[tmp_state][node]){
                    q.push(State(node,tmp_state,tmp.step+1));
                    visited[tmp_state][node] = true;
                }
            }
            
        }
        
        return ans;
    }
};
