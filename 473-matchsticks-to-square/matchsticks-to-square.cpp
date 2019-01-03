// Remember the story of Little Match Girl? By now, you know exactly what matchsticks the little match girl has, please find out a way you can make one square by using up all those matchsticks. You should not break any stick, but you can link them up, and each matchstick must be used exactly one time.
//
//  Your input will be several matchsticks the girl has, represented with their stick length. Your output will either be true or false, to represent whether you could make one square using all the matchsticks the little match girl has.
//
// Example 1:
//
// Input: [1,1,2,2,2]
// Output: true
//
// Explanation: You can form a square with length 2, one side of the square came two sticks with length 1.
//
//
//
// Example 2:
//
// Input: [3,3,3,3,4]
// Output: false
//
// Explanation: You cannot find a way to form a square with all the matchsticks.
//
//
//
// Note:
//
// The length sum of the given matchsticks is in the range of 0 to 10^9.
// The length of the given matchstick array will not exceed 15.
//
//


class Solution {
public:
    bool makesquare(vector<int>& nums) {
        if(nums.size()<4) return false;
        int sum = 0;
        for(int num:nums) sum+=num;
        if(sum%4!=0) return false;
        int target = sum/4;
        vector<int> sides(4,0);
        bool ans =  false;
        sort(nums.rbegin(),nums.rend());
        ans = dfs(nums,target,sides,0);
        return ans;
     }
    
    bool dfs(vector<int>& nums,int target,vector<int>& sides,int cur){
        if(cur>=nums.size()){
            return sides[0]==target && sides[1]==target && sides[2]==target && sides[3]==target;
        }
        for(int i=0;i<4;i++){
            if(sides[i]+nums[cur]>target) continue;
            sides[i]+=nums[cur];
            if(dfs(nums,target,sides,cur+1)) return true;
            sides[i]-=nums[cur];
        }
        return false;
    }
};
