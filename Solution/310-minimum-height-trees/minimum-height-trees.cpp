// For an undirected graph with tree characteristics, we can choose any node as the root. The result graph is then a rooted tree. Among all possible rooted trees, those with minimum height are called minimum height trees (MHTs). Given such a graph, write a function to find all the MHTs and return a list of their root labels.
//
// Format
// The graph contains n nodes which are labeled from 0 to n - 1. You will be given the number n and a list of undirected edges (each edge is a pair of labels).
//
// You can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges.
//
// Example 1 :
//
//
// Input: n = 4, edges = [[1, 0], [1, 2], [1, 3]]
//
//         0
//         |
//         1
//        / \
//       2   3 
//
// Output: [1]
//
//
// Example 2 :
//
//
// Input: n = 6, edges = [[0, 3], [1, 3], [2, 3], [4, 3], [5, 4]]
//
//      0  1  2
//       \ | /
//         3
//         |
//         4
//         |
//         5 
//
// Output: [3, 4]
//
// Note:
//
//
// 	According to the definition of tree on Wikipedia: “a tree is an undirected graph in which any two vertices are connected by exactly one path. In other words, any connected graph without simple cycles is a tree.”
// 	The height of a rooted tree is the number of edges on the longest downward path between the root and a leaf.
//
//


class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        //最后树的根数目只有两种可能，1或者2。如果为3以上，则去除掉相邻的点，取中间点为根，得到的树高度一定更矮。
        //思路如下：先找出叶节点，再找出叶节点连接的节点，从该节点的相邻节点数组中删除叶节点，如果这时候数组size为1，则说明该节点也成为了叶节点。
        //继续遍历直到剩余节点数目小于等于2
        vector<int> ans;
        if(n == 1) return {0};
        vector<unordered_set<int>> adjacents(n);
        queue<int> q;
        
        for(auto e : edges) {
            //双向的
            adjacents[e[0]].insert(e[1]);
            adjacents[e[1]].insert(e[0]);
        }
        
        //压入叶节点
        for(int i = 0; i < n; ++i) {
            if(adjacents[i].size() == 1) q.push(i);
        }
        
        //循环直到剩余数目小于等于2
        while (n > 2) {
            int len = q.size();
            n -= len;
            //找叶节点的相邻节点并删除
            for(int i = 0; i < len; ++i) {
                int tmp = q.front(); 
                q.pop();
                for(auto a : adjacents[tmp]) {
                    adjacents[a].erase(tmp);
                    if (adjacents[a].size() == 1) q.push(a);
                }
            }
        }
        
        while (!q.empty()) {
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};
