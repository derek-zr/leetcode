// Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.
//
// Example 1:
//
//
// Input: [3,2,1,5,6,4] and k = 2
// Output: 5
//
//
// Example 2:
//
//
// Input: [3,2,3,1,2,4,5,5,6] and k = 4
// Output: 4
//
// Note: 
// You may assume k is always valid, 1 ≤ k ≤ array's length.
//


class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int left = 0, right = nums.size();
        while(left < right) {
            int cur = partition(nums, left, right);
            if (cur == k-1) return nums[cur];
            else if (cur > k-1)  right = cur;
            else left = cur + 1;
        }
        return -1;
    }
    
    int partition(vector<int> &nums, int left, int right) {
        //分割为两部分 elements>pivot  pivot   elements<pivot
        int pivot = nums[left];
        int l = left + 1;
        int r = right - 1;
        
        //这里一定要有等号，考虑只有两个元素的情况(left+1==right)
        while(l <= r) {
            if (nums[l] < pivot && nums[r] > pivot) {
                swap(nums[l++], nums[r--]);
            }
            
            if (nums[l] >= pivot)  ++l;
            if (nums[r] <= pivot)  --r;
        }
        //交换pivot和r
        swap(nums[left], nums[r]);
        //cout << r;
        return r;
    }
    
    /*
    //快排，当partition的位置为k时，则当前值即为klarge
    //In average, this algorithm reduces the size of the problem by approximately one half after each partition, giving the recurrence T(n) = T(n/2) + O(n) 
    //with O(n) being the time for partition. The solution is T(n) = O(n), which means we have found an average linear-time solution. However, 
    //in the worst case, the recurrence will become T(n) = T(n - 1) + O(n) and T(n) = O(n^2).
    int findKthLargest(vector<int>& nums, int k) {
        int left = 0, right = nums.size()-1;
        while(1) {
            int pos = partition(nums,left,right);
            if(pos == k-1) return nums[pos];
            else if(pos > k-1) right = pos-1;  //左边大的多了，分割左边
            else left = pos +1;
        }
    }
    
    int partition(vector<int>& nums,int left,int right) {
        int pivot = nums[left];  //第一个作为pivot，找到pos后在swap位置
        int l = left+1;
        int r = right;
        
        while(l <= r) {
            if(nums[l] < pivot && nums[r] > pivot) {
                swap(nums[l++],nums[r--]);
            }
            
            if(nums[l] >= pivot) ++l;
            if(nums[r] <= pivot) --r;
        }
        
        swap(nums[left],nums[r]);
        return r;
    }
    */
};
