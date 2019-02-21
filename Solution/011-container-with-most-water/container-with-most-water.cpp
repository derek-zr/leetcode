// Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.
//
// Note: You may not slant the container and n is at least 2.
//
//  
//
//
//
// The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49. 
//
//  
//
// Example:
//
//
// Input: [1,8,6,2,5,4,8,3,7]
// Output: 49
//


class Solution {
public:
    int maxArea(vector<int>& height) {
        int water = 0;
        int i = 0, j = height.size() - 1;
        while (i < j) {
            int h = min(height[i], height[j]);
            water = max(water, (j - i) * h);
            while (height[i] <= h && i < j) i++;
            while (height[j] <= h && i < j) j--;
        }
        return water;
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
