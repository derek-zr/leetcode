// Additive number is a string whose digits can form additive sequence.
//
// A valid additive sequence should contain at least three numbers. Except for the first two numbers, each subsequent number in the sequence must be the sum of the preceding two.
//
// Given a string containing only digits '0'-'9', write a function to determine if it's an additive number.
//
// Note: Numbers in the additive sequence cannot have leading zeros, so sequence 1, 2, 03 or 1, 02, 3 is invalid.
//
// Example 1:
//
//
// Input: "112358"
// Output: true 
// Explanation: The digits can form an additive sequence: 1, 1, 2, 3, 5, 8. 
//              1 + 1 = 2, 1 + 2 = 3, 2 + 3 = 5, 3 + 5 = 8
//
//
// Example 2:
//
//
// Input: "199100199"
// Output: true 
// Explanation: The additive sequence is: 1, 99, 100, 199. 
//              1 + 99 = 100, 99 + 100 = 199
//
// Follow up:
// How would you handle overflow for very large input integers?


class Solution {
public:
    bool isAdditiveNumber(string num) {
        int len = num.size();
        for(int i=1;i<=len/2;i++){
            for(int j=1;j<=(len-i)/2;j++){
                if(check(num.substr(0,i),num.substr(i,j),num.substr(i+j))) return true;   //num1,num2,及剩余的字符串
            }
        }
        return false;
    }
    
    bool check(string num1,string num2,string result){
        if(num1.size()>1 && num1[0]=='0' || num2.size()>1 && num2[0]=='0') return false;  //leading zeros
        string sum = add(num1,num2);
        if(sum==result) return true;
        if(sum.size()>result.size() || sum!=result.substr(0,sum.size())) return false;  //num1+num2 != num(sum.size)
        else return check(num2,sum,result.substr(sum.size()));
    }
    
    string add(string num1,string num2){
        string ans;
        int i=num1.size()-1,j=num2.size()-1;
        int carry=0;
        while(i>=0 || j>=0){
            int sum=carry+(i>=0 ? (num1[i--]-'0') : 0) + (j>=0?  (num2[j--]-'0') : 0);
            ans.push_back(sum%10+'0');
            carry=sum/10;
        }
        if(carry) ans.push_back(carry+'0');
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
