// We are playing the Guess Game. The game is as follows:
//
// I pick a number from 1 to n. You have to guess which number I picked.
//
// Every time you guess wrong, I'll tell you whether the number I picked is higher or lower.
//
// However, when you guess a particular number x, and you guess wrong, you pay $x. You win the game when you guess the number I picked.
//
// Example:
//
//
// n = 10, I pick 8.
//
// First round:  You guess 5, I tell you that it's higher. You pay $5.
// Second round: You guess 7, I tell you that it's higher. You pay $7.
// Third round:  You guess 9, I tell you that it's lower. You pay $9.
//
// Game over. 8 is the number I picked.
//
// You end up paying $5 + $7 + $9 = $21.
//
//
// Given a particular n ≥ 1, find out how much money you need to have to guarantee a win.


//在最佳猜测策略的情况下的最小花费
//如两个元素时：3,4 显然最小花费是3（不管第一次是否猜对，第二次一定保证选出正确的）

class Solution {
public:
    int getMoneyAmount(int n) {
        int dp[n+1][n+1];
        memset(dp,0,sizeof(dp));
        
        for(int i=1;i<=n;i++){
            for(int j=i-1;j>0;j--){
                int minAns=INT_MAX;
                for(int k=j;k<i;k++){
                    int temp=k+max(dp[j][k-1],dp[k+1][i]);
                    minAns=min(minAns,temp);
                }
                dp[j][i]=minAns;
            }
        }
        return dp[1][n];
    }
};
