// Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.
//
//
// The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped. Thanks Marcos for contributing this image!
//
// Example:
//
//
// Input: [0,1,0,2,1,0,1,3,2,1,2,1]
// Output: 6
//


class Solution {
public:
    //这道题可以用dp或者stack或者双指针
    int trap(vector<int>& height) {
        
        //stack
        int n = height.size();
        int i = 0,ans = 0;
        stack<int> s;
        
        while(i < n) {
            if(s.empty() || height[i] <= height[s.top()])
                s.push(i++);    //这里压入坐标，方便计算坑的宽度
            else {
                int tmp = s.top();
                s.pop();
                if(s.empty()) continue;  //坑必须有另一边
                ans += (min(height[i],height[s.top()])-height[tmp]) * (i-s.top()-1);
            }
        }
        
        return ans;
        
        
        /*
        //dp
        int n = height.size();
        int ans = 0, max_h = 0;
        vector<int> dp(n,0);
        
        //先从前向后扫描，dp[i]代表这个方向到i位置的最大值
        for(int i=0;i<n;i++){
            dp[i] = max_h;
            max_h = max(max_h,height[i]);
        }
        
        max_h = 0;
        
        //从后向前扫描取两个方向中的较小者
        for(int i=n-1;i>=0;i--){
            dp[i] = min(dp[i],max_h);
            max_h = max(max_h,height[i]);
            if(dp[i]>height[i]) ans += dp[i]-height[i];
        }
        
        return ans;
        */
        
        /*双指针
        int left = 0, right = height.size()-1;
        int ans = 0;
        int max_left = 0;
        int max_right = 0;
        while(left<right){
            //装水的多少取决于最短的那一边
            if(height[left]<height[right]){
                if(height[left]>max_left) max_left = height[left];
                else ans += (max_left-height[left]);
                ++left;
            }
            else{
                if(height[right]>max_right) max_right = height[right];
                else ans += (max_right-height[right]);
                --right;
            }
            
        }
        
        return ans;
        */
    }
};
