// Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.
//
// Example:
//
//
// Input: n = 4, k = 2
// Output:
// [
//   [2,4],
//   [3,4],
//   [2,3],
//   [1,2],
//   [1,3],
//   [1,4],
// ]
//
//


class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        //第二种方法是利用组合数的性质
        /*C(4, 2) = C(3, 1) + C(3, 2)
        我们不难写出 C(3, 1) 的所有情况：[1], [2], [3]，还有 C(3, 2) 的所有情况：[1, 2],         [1, 3], [2, 3]。我们发现二者加起来为6，正好是 C(4, 2) 的个数之和。但是我们仔细看会         发现，C(3, 2)的所有情况包含在 C(4, 2) 之中，但是 C(3, 1) 的每种情况只有一个数字，         而我们需要的结果k=2，其实很好办，每种情况后面都加上4，于是变成了：[1, 4], [2, 4],           [3, 4]，加上C(3, 2) 的所有情况：[1, 2], [1, 3], [2, 3]，正好就得到了 n=4, k=2         的所有情况了。*/
        if (k > n || k < 0) return {};
        if (k == 0) return {{}};
        vector<vector<int>> ans;
        ans = combine(n-1,k-1);
        for(auto &a : ans) a.push_back(n);  //在C(n-1,k-1)情况后面都压入一个n
        for(auto &a : combine(n-1,k)) ans.push_back(a); //最终结果中插入C(n-1,k)的所有情况
        return ans;
        
        /*
        //典型的回溯法题目
        vector<vector<int>> ans;
        if(n == 0 || k==0) return ans;
        vector<int> nums(n,0);
        for(int i = 0; i < n; ++i) nums[i] = i+1; //1-n
        vector<int> tmp;
        dfs(ans,nums,tmp,k,0,n);
        return ans;
        */
    }
    
    void dfs(vector<vector<int>> &ans,vector<int> &nums,vector<int> tmp,int &k,int start,int &n) {
        if(tmp.size()==k) {
            ans.push_back(tmp);
            return;
        }
        for(int i = start; i < n; ++i) {
            tmp.push_back(nums[i]);
            dfs(ans,nums,tmp,k,i+1,n);
            tmp.pop_back();
        }
        return;
    }
};
