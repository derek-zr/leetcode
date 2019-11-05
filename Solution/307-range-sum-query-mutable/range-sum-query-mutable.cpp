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
    //相当于加了额外信息的满二叉树，可以添加子树的节点和或最大值、最小值。
    //当某个结点的值发生变化时，只需要更新一下所有祖先结点的信息
    //这里用一个数组来模拟线段树
    
    NumArray(vector<int> nums) {
        n = nums.size();
        tree.resize(2*n);
        //后n个相当于是叶子节点，保存数组内的值
        for(int i = n; i < 2*n; i++)
            tree[i] = nums[i - n];
        //前n个是各个区间段的和，其中tree[0]是一个无用的值
        for(int i = n-1; i >= 0; i--)
            tree[i] = tree[2*i] + tree[2*i+1];
    }
    
    void update(int i, int val) {
        //找到对应的叶子节点
        i += n;
        tree[i] = val;
        //只需要更新对应的父节点，即i/2
        while(i){
            //i 和 i^1 始终为一对奇偶数
            tree[i / 2] = tree[i] + tree[i ^ 1]; //i对应的另一个对称节点的索引为i^1
            i /= 2;
        }
    }
    
    int sumRange(int i, int j) {
        int sum = 0;
        i += n;
        j += n;
        //当i为右节点时，加上自身节点的值。 当j为左节点时，加上自身节点的值。否则，等到后续轮次直接累加父节点的值
        //对于i是左节点，j是右节点的情况，由于都需要累加父节点的值，所以可以留到后续累加，暂时不需要处理
        //这里只需要处理 只累加当前叶子节点的情况
        for(i,j; i <= j; i /= 2, j /= 2){
            if(i % 2 == 1) sum += tree[i++];     //为奇数说明是右节点
            if(j % 2 == 0) sum += tree[j--];     //为偶数说明是左节点
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
