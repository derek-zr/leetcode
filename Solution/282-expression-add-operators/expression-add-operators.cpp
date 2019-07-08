// Given a string that contains only digits 0-9 and a target value, return all possibilities to add binary operators (not unary) +, -, or * between the digits so they evaluate to the target value.
//
// Example 1:
//
//
// Input: num = "123", target = 6
// Output: ["1+2+3", "1*2*3"] 
//
//
// Example 2:
//
//
// Input: num = "232", target = 8
// Output: ["2*3+2", "2+3*2"]
//
// Example 3:
//
//
// Input: num = "105", target = 5
// Output: ["1*0+5","10-5"]
//
// Example 4:
//
//
// Input: num = "00", target = 0
// Output: ["0+0", "0-0", "0*0"]
//
//
// Example 5:
//
//
// Input: num = "3456237490", target = 9191
// Output: []
//
//


class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        //因为乘法的存在，所以需要传递上一个运算的值
        helper(ans,num,target,"",0,0);
        return ans;
    }
    
    //用long防止overflow
    void helper(vector<string> &ans,string num,long target,string tmp,long previous,long curNum) {
        if(num.empty() && curNum == target) {
            ans.push_back(tmp);
            return;
        }
        //开始遍历
        int len = num.size();
        for(int i = 1; i <= len; ++i) {
            string cur = num.substr(0,i);
            //去除掉第一位为0的不合理的数字
            if(cur.size() > 1 && cur[0] == '0') continue;
            string remained = num.substr(i);
            if(tmp.size() > 0) {
                helper(ans,remained,target,tmp+"+"+cur,stoll(cur),curNum+stoll(cur));
                helper(ans,remained,target,tmp+"-"+cur,-stoll(cur),curNum-stoll(cur));
                //乘法需要单独处理，将上一个的运算结果复原，同时本次的previous设为乘积结果
                helper(ans,remained,target,tmp+"*"+cur,previous*stoll(cur),(curNum-previous)+previous*stoll(cur));
                
            }
            else {
                helper(ans,remained,target,cur,stoll(cur),stoll(cur));
            }
        }
    }
};
