// Given an m x n matrix of positive integers representing the height of each unit cell in a 2D elevation map, compute the volume of water it is able to trap after raining.
//
//  
//
// Note:
//
// Both m and n are less than 110. The height of each unit cell is greater than 0 and is less than 20,000.
//
//  
//
// Example:
//
//
// Given the following 3x6 height map:
// [
//   [1,4,3,1,3,2],
//   [3,2,1,3,2,4],
//   [2,3,3,2,3,1]
// ]
//
// Return 4.
//
//
//
//
// The above image represents the elevation map [[1,4,3,1,3,2],[3,2,1,3,2,4],[2,3,3,2,3,1]] before the rain.
//
//  
//
//
//
// After the rain, water is trapped between the blocks. The total volume of water trapped is 4.
//


class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        /*
        考虑如下一种方法：
        开始时，海平面h被初始化为最低的那个高度，每次我们往里面灌h+0.01高度的水，如果我们发现一个点刚刚被淋湿，即第一次被访问（说明其是洼地，且旁边至少有一个边界的高度为h）
        则此时能够装入h-cur_height的水。如此逐步遍历，即可得到最终的蓄水量。
        实现细节：
        初始化时候，我们将所有边缘上的点加入队列(边缘上的点一定不可能存储水)，并逐步遍历，重复上述过程，得到结果。
        */
        if(heightMap.empty()) return 0;
        int rows = heightMap.size(), cols = heightMap[0].size();
        int ans = 0, level = INT_MIN;
        //用优先级队列，头部就是最小的高度
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        vector<vector<bool>> visited(rows,vector<bool>(cols,false));
        vector<vector<int>> dirs{{0,1},{0,-1},{1,0},{-1,0}};
        //初始化
        for(int i = 0; i < rows; ++i) {
            for(int j = 0; j < cols; ++j) {
                if(i == 0 || i == rows-1 || j == 0 || j == cols-1) {
                    q.push({heightMap[i][j],i*cols+j});
                    visited[i][j] = true;
                }
            }
        }
        //开始遍历
        while(!q.empty()) {
            auto tmp = q.top();
            q.pop();
            int h = tmp.first, r = tmp.second / cols, c = tmp.second % cols;
            //cout<<h<<r<<c<<endl;
            level = max(level,h);  //更新海平面
            for(int i = 0; i < dirs.size(); ++i) {
                int x = dirs[i][0]+r , y = dirs[i][1]+c;
                if(x < 0 || x >= rows || y < 0 || y >= cols || visited[x][y]) continue;  //跳过已经访问过的
                visited[x][y] = true;
                //cout<<x<<y<<heightMap[x][y]<<level<<endl;
                //如果低于海平面，则说明可以蓄水
                if(heightMap[x][y] < level) ans += level-heightMap[x][y];
                q.push({heightMap[x][y] , x*cols+y});
            }
        }
        return ans;
    }
};
