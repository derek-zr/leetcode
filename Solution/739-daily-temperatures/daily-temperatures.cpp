//
// Given a list of daily temperatures T, return a list such that, for each day in the input, tells you how many days you would have to wait until a warmer temperature.  If there is no future day for which this is possible, put 0 instead.
//
// For example, given the list of temperatures T = [73, 74, 75, 71, 69, 72, 76, 73], your output should be [1, 1, 4, 2, 1, 1, 0, 0].
//
//
// Note:
// The length of temperatures will be in the range [1, 30000].
// Each temperature will be an integer in the range [30, 100].
//


class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        //第二种方法，单调栈。这道题使用递减栈
        int len = T.size();
        vector<int> ans(len,0);
        stack<int> s;
        for(int i = 0; i < len; ++i) {
            while(!s.empty() && T[i] > T[s.top()]) {
                //遇到温度更高的，则不断出栈。计算栈内元素warmer的下标差
                int tmp = s.top();
                s.pop();
                ans[tmp] = i-tmp;
            }
            s.push(i); //压入当前下标，此时仍符合递减栈性质
        }
        return ans;
        /*
        //第一种方法，用hashmap保存当前遍历到的温度和下标间的映射
        //每次都遍历当前温度到最高温度的下标差，计算最小值
        vector<int> ans;
        unordered_map<int,int> m; //记录气温和下标的对应关系
        int len = T.size();
        ans.push_back(0);  //最后一天一定为0
        m[T[len-1]] = len-1;
        for(int i = len-2; i >= 0; --i) {
            int cur = T[i];
            m[cur] = i;
            int tmp_min = INT_MAX;
            while(++cur <= 100) {
                if(m[cur] > i) tmp_min = min(tmp_min,m[cur]);
            }
            if(tmp_min==INT_MAX) ans.push_back(0);  //找不到更warmer的
            else ans.push_back(tmp_min-i);
        }
        reverse(ans.begin(),ans.end());
        return ans;*/
    }
};
