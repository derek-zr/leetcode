// A frog is crossing a river. The river is divided into x units and at each unit there may or may not exist a stone. The frog can jump on a stone, but it must not jump into the water.
//
// Given a list of stones' positions (in units) in sorted ascending order, determine if the frog is able to cross the river by landing on the last stone. Initially, the frog is on the first stone and assume the first jump must be 1 unit.
//
//
// If the frog's last jump was k units, then its next jump must be either k - 1, k, or k + 1 units. Note that the frog can only jump in the forward direction.
//
// Note:
//
// The number of stones is ≥ 2 and is < 1,100.
// Each stone's position will be a non-negative integer < 231.
// The first stone's position is always 0.
//
//
//
// Example 1:
//
// [0,1,3,5,6,8,12,17]
//
// There are a total of 8 stones.
// The first stone at the 0th unit, second stone at the 1st unit,
// third stone at the 3rd unit, and so on...
// The last stone at the 17th unit.
//
// Return true. The frog can jump to the last stone by jumping 
// 1 unit to the 2nd stone, then 2 units to the 3rd stone, then 
// 2 units to the 4th stone, then 3 units to the 6th stone, 
// 4 units to the 7th stone, and 5 units to the 8th stone.
//
//
//
// Example 2:
//
// [0,1,2,3,4,8,9,11]
//
// Return false. There is no way to jump to the last stone as 
// the gap between the 5th and 6th stone is too large.
//
//


class Solution {
public:
    bool canCross(vector<int>& stones) {
        //建立一个i位置的石头与其能跳距离的hashmap，方便后续的dp
        //dp[i]表示i位置上青蛙能弹跳的最大距离
        int len = stones.size();
        unordered_map<int,unordered_set<int>> m;
        vector<int> dp(len,0);
        m[0].insert(0);
        int last = 0;
        
        for(int i = 1; i < len; ++i) {
            while(dp[last]+1 < stones[i] - stones[last]) ++last;  //找到第一个可以到达的点
            for(int j = last; j < i; ++j) {
                int tmp = stones[i] - stones[j];  //本次需要跳的距离
                if(m[j].count(tmp-1) || m[j].count(tmp) || m[j].count(tmp+1)) {
                    m[i].insert(tmp);
                    dp[i] = max(dp[i],tmp);
                }
            }
        }
        return dp.back() > 0;  //最后的位置不为0则表示能够达到
    }
};
