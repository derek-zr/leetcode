// There are G people in a gang, and a list of various crimes they could commit.
//
// The i-th crime generates a profit[i] and requires group[i] gang members to participate.
//
// If a gang member participates in one crime, that member can't participate in another crime.
//
// Let's call a profitable scheme any subset of these crimes that generates at least P profit, and the total number of gang members participating in that subset of crimes is at most G.
//
// How many schemes can be chosen?  Since the answer may be very large, return it modulo 10^9 + 7.
//
//  
//
// Example 1:
//
//
// Input: G = 5, P = 3, group = [2,2], profit = [2,3]
// Output: 2
// Explanation: 
// To make a profit of at least 3, the gang could either commit crimes 0 and 1, or just crime 1.
// In total, there are 2 schemes.
//
//
//
// Example 2:
//
//
// Input: G = 10, P = 5, group = [2,3,5], profit = [6,7,8]
// Output: 7
// Explanation: 
// To make a profit of at least 5, the gang could commit any crimes, as long as they commit one.
// There are 7 possible schemes: (0), (1), (2), (0,1), (0,2), (1,2), and (0,1,2).
//
//
//  
//
//
// Note:
//
//
// 	1 <= G <= 100
// 	0 <= P <= 100
// 	1 <= group[i] <= 100
// 	0 <= profit[i] <= 100
// 	1 <= group.length = profit.length <= 100
//
//
//
//  
//
//


class Solution {
public:
    //背包问题
    int profitableSchemes(int G, int P, vector<int>& group, vector<int>& profit) {
        vector<vector<int> > dp(G+1,vector<int>(P+1,0)); //dp[i][j]表示i个人参与且总价值大于等于j的数目
        dp[0][0]=1;
        int len = group.size();
        int mod = 1e9+7;
        for(int i=0;i<len;i++){
            for(int j=G;j>=group[i];j--){
                for(int k=P;k>=0;k--){
                    //上一次背包重量小于j-group[i] 并且 上一次背包价值大于k-profit[i]（最小为0）
                    dp[j][k] = (dp[j][k] + dp[j-group[i]][max(0,k-profit[i])]) % mod;
                }
            }
        }
        int ans = 0;
        for(int i=0;i<=G;i++) ans = (ans+dp[i][P]) % mod;
        return ans;
    }
};
