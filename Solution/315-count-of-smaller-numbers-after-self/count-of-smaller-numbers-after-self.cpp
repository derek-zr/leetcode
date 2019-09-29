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


class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        //插入排序，将nums数组从末尾逐个插入到一个新数组中
        //通过二分法找到的插入位置的坐标即smaller的数目
        //eg. [1] -> [0]; [1,6] -> [1,0]; ....
        int len = nums.size();
        vector<int> newnums, ans(len);
        
        //开始从尾部向前遍历
        for (int i = len-1; i >= 0; --i) {
            int left = 0, right = newnums.size();
            while (left < right) {
                int mid = left + (right - left) / 2;
                if (newnums[mid] < nums[i]) left = mid + 1;
                else right = mid;
            }
            ans[i] = right;
            //插入新数组中
            newnums.insert(newnums.begin()+right, nums[i]);
        }
        
        return ans;
    }
};
