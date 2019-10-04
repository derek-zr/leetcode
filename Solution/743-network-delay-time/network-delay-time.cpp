// There are N network nodes, labelled 1 to N.
//
// Given times, a list of travel times as directed edges times[i] = (u, v, w), where u is the source node, v is the target node, and w is the time it takes for a signal to travel from source to target.
//
// Now, we send a signal from a certain node K. How long will it take for all nodes to receive the signal? If it is impossible, return -1.
//
//  
//
// Example 1:
//
//
//
//
// Input: times = [[2,1,1],[2,3,1],[3,4,1]], N = 4, K = 2
// Output: 2
//
//
//  
//
// Note:
//
//
// 	N will be in the range [1, 100].
// 	K will be in the range [1, N].
// 	The length of times will be in the range [1, 6000].
// 	All edges times[i] = (u, v, w) will have 1 <= u, v <= N and 0 <= w <= 100.
//
//


class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        int res = 0;
        vector<vector<int>> edges(N+1, vector<int>(N+1, -1));
        queue<int> q{{K}};
        vector<int> dist(N + 1, INT_MAX);
        dist[K] = 0;
        for (auto e : times) edges[e[0]][e[1]] = e[2];
        while (!q.empty()) {
            unordered_set<int> visited;
            for (int i = q.size(); i > 0; --i) {
                int u = q.front(); q.pop();
                for (int v = 1; v <= N; ++v) {
                    if (edges[u][v] != -1 && dist[u] + edges[u][v] < dist[v]) {
                        if (!visited.count(v)) {
                            visited.insert(v);
                            q.push(v);
                        }
                        dist[v] = dist[u] + edges[u][v];
                    }
                }
            }
        }
        for (int i = 1; i <= N; ++i) {
            res = max(res, dist[i]);
        }
        return res == INT_MAX ? -1 : res;
    }
};
