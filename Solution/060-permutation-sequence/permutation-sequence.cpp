// The set [1,2,3,...,n] contains a total of n! unique permutations.
//
// By listing and labeling all of the permutations in order, we get the following sequence for n = 3:
//
//
// 	"123"
// 	"132"
// 	"213"
// 	"231"
// 	"312"
// 	"321"
//
//
// Given n and k, return the kth permutation sequence.
//
// Note:
//
//
// 	Given n will be between 1 and 9 inclusive.
// 	Given k will be between 1 and n! inclusive.
//
//
// Example 1:
//
//
// Input: n = 3, k = 3
// Output: "213"
//
//
// Example 2:
//
//
// Input: n = 4, k = 9
// Output: "2314"
//
//


class Solution {
public:
    string getPermutation(int n, int k) {
        //这道题主要是找数学规律
        //从高位到低位逐步确定值
        //例如：1234 1243 1324 1342 1423 1432 最高位以1开头的有6个，同理以2、3、4开头的也有6个
        //确定最高位后，以此类推，可以逐步推出各位置上的数
        //总结数学规律如下：index = k/(n-1)!,k = k %(n-1)!
        string ans = "";
        string nums = "123456789";
        vector<int> fac(n,1);  //建立阶乘数组
        for(int i = 1; i < n; ++i) fac[i] = fac[i-1]*i;
        --k;  //下标从0开始
        //接下来开始逐步确定位置
        for(int i = n; i > 0; --i) {
            int index = k / fac[i-1];
            //cout<<index;
            k = k % fac[i-1];
            ans.push_back(nums[index]);  
            nums.erase(index,1);  //确定后则从数组中删除
        }
        return ans;
    }
};
