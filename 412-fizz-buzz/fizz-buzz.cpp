// Write a program that outputs the string representation of numbers from 1 to n.
//
// But for multiples of three it should output “Fizz” instead of the number and for the multiples of five output “Buzz”. For numbers which are multiples of both three and five output “FizzBuzz”.
//
// Example:
//
// n = 15,
//
// Return:
// [
//     "1",
//     "2",
//     "Fizz",
//     "4",
//     "Buzz",
//     "Fizz",
//     "7",
//     "8",
//     "Fizz",
//     "Buzz",
//     "11",
//     "Fizz",
//     "13",
//     "14",
//     "FizzBuzz"
// ]
//
//


class Solution {
public:
    vector<string> fizzBuzz(int n) {
     int i;
     vector<string> ans(n);
     string str1="Fizz";
     string str2="Buzz";
     for(int i=1;i<=n;i++){
     	if(i%3==0)
     		ans[i-1]+=str1;
     	if(i%5==0)
     		ans[i-1]+=str2;
        if(i%3!=0&&i%5!=0)  //此处判断条件也可替换为 ans[i-1]==""
        	ans[i-1]+=to_string(i);
     }
     return ans;
    }
};
