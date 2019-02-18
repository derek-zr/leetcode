// Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.
//
// If the fractional part is repeating, enclose the repeating part in parentheses.
//
// Example 1:
//
//
// Input: numerator = 1, denominator = 2
// Output: "0.5"
//
//
// Example 2:
//
//
// Input: numerator = 2, denominator = 1
// Output: "2"
//
// Example 3:
//
//
// Input: numerator = 2, denominator = 3
// Output: "0.(6)"
//
//


class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        int n_positive = numerator>0 ? 1 : -1;
        int d_positive = denominator>0? 1 : -1;
        long long n = abs((long long)numerator);
        if(n==0) return "0";
        long long d = abs((long long)denominator);  //-INT_MAX取绝对值时候会越界，先转为longlong类型
        long long inter = n/d;
        long long remain = n%d;
        string ans = to_string(inter);
        if(n_positive*d_positive==-1) ans = "-"+ans;
        if(remain==0) return ans;
        //小数
        ans += ".";
        unordered_map<long long,int> m;
        string rem_str = "";
        int pos = 0;
        while(remain!=0){
            if(m.find(remain)!=m.end()){
                rem_str.insert(m[remain],"(");
                rem_str += ")";
                return ans+rem_str;
            }
            m[remain] = pos;
            ++pos;
            rem_str += to_string((remain*10)/d);
            remain = (remain*10)%d;
        }
        
        return ans+rem_str;
    }
};
