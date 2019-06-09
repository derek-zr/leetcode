// There are N children standing in a line. Each child is assigned a rating value.
//
// You are giving candies to these children subjected to the following requirements:
//
//
// 	Each child must have at least one candy.
// 	Children with a higher rating get more candies than their neighbors.
//
//
// What is the minimum candies you must give?
//
// Example 1:
//
//
// Input: [1,0,2]
// Output: 5
// Explanation: You can allocate to the first, second and third child with 2, 1, 2 candies respectively.
//
//
// Example 2:
//
//
// Input: [1,2,2]
// Output: 4
// Explanation: You can allocate to the first, second and third child with 1, 2, 1 candies respectively.
//              The third child gets 1 candy because it satisfies the above two conditions.
//
//


class Solution {
public:
    int candy(vector<int>& ratings) {
        //贪心法。前后两次遍历
        int ans = 0;
        int len = ratings.size();
        vector<int> candies(len,1);
        
        //从前向后遍历
        for(int i = 0; i < len-1; ++i) {
            if(ratings[i+1] > ratings[i]) candies[i+1] = candies[i]+1;
        }
        
        //从后向前遍历
        for(int i = len-1; i > 0; --i) {
            if(ratings[i-1] > ratings[i]) candies[i-1] = max(candies[i-1],candies[i]+1);
        }
        
        //求总的糖果数
        for(int i = 0; i < len; ++i) {
            ans += candies[i];
        }
        
        return ans;
    }
};
