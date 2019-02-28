// Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.
//
// The update(i, val) function modifies nums by updating the element at index i to val.
//
// Example:
//
//
// Given nums = [1, 3, 5]
//
// sumRange(0, 2) -> 9
// update(1, 2)
// sumRange(0, 2) -> 8
//
//
// Note:
//
//
// 	The array is only modifiable by the update function.
// 	You may assume the number of calls to update and sumRange function is distributed evenly.
//
//


class NumArray {
public:
    //用线段树做
    NumArray(vector<int> nums) {
        n = nums.size();
        tree.resize(2*n);
        for(int i = n; i < 2*n; i++)
            tree[i] = nums[i - n];
        for(int i = n-1; i >= 0; i--)
            tree[i] = tree[2*i] + tree[2*i+1];
    }
    
    void update(int i, int val) {
        i += n;
        tree[i] = val;
        while(i){
            tree[i / 2] = tree[i] + tree[i ^ 1]; //i对应的另一个对称节点的索引为i^1
            i /= 2;
        }
    }
    
    int sumRange(int i, int j) {
        int sum = 0;
        i += n;
        j += n;
        //当i为右节点时，加上自身节点的值。 当j为左节点时，加上自身节点的值。否则，等到后续轮次直接累加父节点的值
        for(i,j; i <= j; i /= 2, j /= 2){
            if(i%2 == 1) sum += tree[i++]; 
            if(j%2 == 0) sum += tree[j--]; 
        }
        
        return sum;
    }
private:
    int n;
    vector<int> tree;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */
