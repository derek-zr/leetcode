// table.dungeon, .dungeon th, .dungeon td {
//   border:3px solid black;
// }
//
//  .dungeon th, .dungeon td {
//     text-align: center;
//     height: 70px;
//     width: 70px;
// }
//
// The demons had captured the princess (P) and imprisoned her in the bottom-right corner of a dungeon. The dungeon consists of M x N rooms laid out in a 2D grid. Our valiant knight (K) was initially positioned in the top-left room and must fight his way through the dungeon to rescue the princess.
//
// The knight has an initial health point represented by a positive integer. If at any point his health point drops to 0 or below, he dies immediately.
//
// Some of the rooms are guarded by demons, so the knight loses health (negative integers) upon entering these rooms; other rooms are either empty (0's) or contain magic orbs that increase the knight's health (positive integers).
//
// In order to reach the princess as quickly as possible, the knight decides to move only rightward or downward in each step.
//
//  
//
// Write a function to determine the knight's minimum initial health so that he is able to rescue the princess.
//
// For example, given the dungeon below, the initial health of the knight must be at least 7 if he follows the optimal path RIGHT-> RIGHT -> DOWN -> DOWN.
//
//
//
//
// 			-2 (K)
// 			-3
// 			3
//
//
// 			-5
// 			-10
// 			1
//
//
// 			10
// 			30
// 			-5 (P)
//
//
//
//
//  
//
// Note:
//
//
// 	The knight's health has no upper bound.
// 	Any room can contain threats or power-ups, even the first room the knight enters and the bottom-right room where the princess is imprisoned.
//
//


class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        //用动态规划做，因为最终到达时血量最小为1
        //所以我们用dp[i][j]表示在i j 位置的血量，从右下角向左上角dp
        //为了避免边界情况，我们添加一行一列
        if(dungeon.empty()) return 0;
        int rows = dungeon.size(), cols = dungeon[0].size();
        vector<vector<int> > dp(rows+1,vector<int>(cols+1,INT_MAX)); //求最低血量，所以初始化为最大值
        
        //公主所在的位置，坐标变化了！！因为我们多加了一行一列，而骑士只能下或者右
        dp[rows][cols-1] = 1, dp[rows-1][cols] = 1;
        
        //开始dp
        for(int i = rows-1; i >= 0; --i) {
            for(int j = cols-1; j >= 0; --j) {
                //若后面相减的值为负数，则说明当前格子为血瓶。进入血瓶的房间时，初始血量最低为1即可。
                dp[i][j] = max(1,min(dp[i+1][j],dp[i][j+1])-dungeon[i][j]);
            }
        }
        
        return dp[0][0];
    }
};
