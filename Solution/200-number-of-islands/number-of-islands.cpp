// Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.
//
// Example 1:
//
//
// Input:
// 11110
// 11010
// 11000
// 00000
//
// Output: 1
//
//
// Example 2:
//
//
// Input:
// 11000
// 11000
// 00100
// 00011
//
// Output: 3
//


class UnionFind {
public:
    UnionFind(int n){
        father.resize(n);
        for(int i = 0; i < n; i++)
            father[i] = i;
    }
    
    void connect(int a, int b){
        int root_a = find(a);
        int root_b = find(b);
        if(root_a != root_b){
            father[root_a] = root_b;
            --cnt;
        }
    }
    
    int query(){
        return cnt;
    }
    
    void set_cnt(int num){
        cnt = num;
    }

private:
    vector<int> father;
    int cnt;
    
    int find(int x){
        while(father[x] != x){
            father[x] = father[father[x]];
            x= father[x];
        }
        return x;
    }
};

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty() || grid[0].empty()) return 0;
        
        //union find
        int res = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        
        UnionFind uf(rows*cols);
        
        int total_1 = 0;
        for(int i = 0 ;i < rows; i++){
            for(int j = 0 ;j < cols; j++){
                if(grid[i][j] == '1') ++total_1;
            }
        }
        
        uf.set_cnt(total_1);
        
        for(int i = 0 ;i < rows; i++){
            for(int j = 0 ;j < cols; j++){
                if(grid[i][j] == '1') {
                    
                    if (i > 0 && grid[i - 1][j] == '1') {
                        uf.connect(i * cols + j, (i - 1) * cols + j);
                    }
                    if (i <  rows - 1 && grid[i + 1][j] == '1') {
                        uf.connect(i * cols + j, (i + 1) * cols + j);
                    }
                    if (j > 0 && grid[i][j - 1] == '1') {
                        uf.connect(i * cols + j, i * cols + j - 1);
                    }
                    if (j < cols - 1 && grid[i][j + 1] == '1') {
                        uf.connect(i * cols + j, i * cols + j + 1);
                    }
                }
             
            }
        }
        
        return uf.query();
        
        /*
        //bfs
        int res = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<bool>> visited(rows,vector<bool>(cols,false));
        
        queue<pair<int,int>> q;
         for(int i = 0 ;i < rows; i++){
            for(int j = 0 ;j < cols; j++){
                if(visited[i][j] || grid[i][j] == '0') continue;
                q.push(make_pair(i,j));
                ++res;
                grid[i][j] = '0';
                
                while(!q.empty()){
                    auto p = q.front();
                    q.pop();
                    int k = p.first,n = p.second;
                    if(k > 0 && grid[k-1][n] == '1'){
                        q.push(make_pair(k-1,n));
                        grid[k-1][n] = '0';
                    }
                    if(k+1 < grid.size() && grid[k+1][n] == '1'){
                        q.push(make_pair(k+1,n));
                        grid[k+1][n] = '0';
                    }
                    if(n > 0 && grid[k][n-1] == '1'){
                        q.push(make_pair(k,n-1));
                        grid[k][n-1] = '0';
                    }
                    if(n+1 < grid[0].size() && grid[k][n+1] == '1'){
                        q.push(make_pair(k,n+1));
                        grid[k][n+1] = '0';
                    }
                    
                }
            }
        }
        
        
        return res;*/
        
        /*
        //dfs
        int res = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<bool>> visited(rows,vector<bool>(cols,false));
        
        for(int i = 0 ;i < rows; i++){
            for(int j = 0 ;j < cols; j++){
                if(visited[i][j] || grid[i][j] == '0') continue;
                dfs(grid,visited,i,j);
                ++res;
            }
        }
            
        return res;*/
    }
    
    void dfs(vector<vector<char>>& grid,vector<vector<bool>>& visited,int x,int y){
        if (x < 0 || x >= grid.size()) return;
        if (y < 0 || y >= grid[0].size()) return;
        if (grid[x][y] != '1' || visited[x][y]) return;
        visited[x][y] = true;
        dfs(grid, visited, x - 1, y);
        dfs(grid, visited, x + 1, y);
        dfs(grid, visited, x, y - 1);
        dfs(grid, visited, x, y + 1);
        
        return;
    }
};
