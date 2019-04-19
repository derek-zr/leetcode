// You are given an integer array nums and you have to return a new counts array. The counts array has the property where counts[i] is the number of smaller elements to the right of nums[i].
//
// Example:
//
//
// Input: [5,2,6,1]
// Output: [2,1,1,0] 
// Explanation:
// To the right of 5 there are 2 smaller elements (2 and 1).
// To the right of 2 there is only 1 smaller element (1).
// To the right of 6 there is 1 smaller element (1).
// To the right of 1 there is 0 smaller element.
//
//


class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        //用二分查找
        //从数组末尾向前遍历，将其插入到一个新数组中
        //二分查找到的插入位置坐标即为右边小于该数字的数目
        //eg. [1] -> [0]; [1,6] -> [1,0]; ....
        int len = nums.size();
        vector<int> new_vec, ans(len);
        
        for(int i = len-1; i >= 0; --i) {
            int left = 0, right = new_vec.size();
            while(left < right) {  //在新数组中查找插入位置
                int mid = left + (right-left)/2;
                if(new_vec[mid] >= nums[i]) right = mid;
                else left = mid+1;
            }
            
            ans[i] = right;
            new_vec.insert(new_vec.begin()+right,nums[i]);
        }
        
        return ans;
    }
};
