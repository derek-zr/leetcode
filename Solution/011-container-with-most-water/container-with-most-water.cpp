// Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of the line i is at (i, ai) and (i, 0). Find two lines, which, together with the x-axis forms a container, such that the container contains the most water.
//
// Notice that you may not slant the container.
//
//  
// Example 1:
//
//
// Input: height = [1,8,6,2,5,4,8,3,7]
// Output: 49
// Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.
//
//
// Example 2:
//
//
// Input: height = [1,1]
// Output: 1
//
//
// Example 3:
//
//
// Input: height = [4,3,2,1,4]
// Output: 16
//
//
// Example 4:
//
//
// Input: height = [1,2,1]
// Output: 2
//
//
//  
// Constraints:
//
//
// 	n = height.length
// 	2 <= n <= 3 * 104
// 	0 <= height[i] <= 3 * 104
//
//


class Solution {
public:
    int maxArea(vector<int>& height) {
        //双指针解决，宽度从大到小遍历
        int ans = 0;
        int left = 0, right = height.size() - 1;
        //遍历过程中求最大值
        while(left < right) {
            int cur_h = min(height[left], height[right]);
            ans =  max(ans, (right-left) * cur_h);
            //移动
            while(left < right && height[left] <= cur_h) ++left;  //高度相等或小于的直接跳过，不可能更大
            while(left < right && height[right] <= cur_h) --right;
        }
        return ans;
        /*
        int water = 0;
        int i = 0, j = height.size() - 1;
        while (i < j) {
            int h = min(height[i], height[j]);
            water = max(water, (j - i) * h);
            while (height[i] <= h && i < j) i++;
            while (height[j] <= h && i < j) j--;
        }
        return water;
        */
        /*slow
        int area = 0;
        int len = height.size();
        for(int i=0;i<len;i++){
            for(int j=i+1;j<len;j++){
                int x_len = j -i;
                int y_len = min(height[i],height[j]);
                area = max(area,x_len*y_len);
            }
        }
        
        return area;*/
    }
};
