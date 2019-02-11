//
// Given scores of N athletes, find their relative ranks and the people with the top three highest scores, who will be awarded medals: "Gold Medal", "Silver Medal" and "Bronze Medal".
//
// Example 1:
//
// Input: [5, 4, 3, 2, 1]
// Output: ["Gold Medal", "Silver Medal", "Bronze Medal", "4", "5"]
// Explanation: The first three athletes got the top three highest scores, so they got "Gold Medal", "Silver Medal" and "Bronze Medal". For the left two athletes, you just need to output their relative ranks according to their scores.
//
//
//
// Note:
//
// N is a positive integer and won't exceed 10,000.
// All the scores of athletes are guaranteed to be unique.
//
//
//


class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        int len = nums.size();
        map<int,int> m;
        vector<string> ans(len,"");
        for(int i=0;i<len;i++) m[nums[i]]=i;
        
        //map默认升序排列，从后向前遍历
        int cnt = 1;
        for(auto it=m.rbegin();it!=m.rend();++it){ //这里用rbegin和rend
            if(cnt==1) ans[it->second] = "Gold Medal";
            else if(cnt==2) ans[it->second] = "Silver Medal";
            else if(cnt==3) ans[it->second] = "Bronze Medal";
            else ans[it->second] = to_string(cnt);++cnt;
        }
        
        return ans;
    }
};
