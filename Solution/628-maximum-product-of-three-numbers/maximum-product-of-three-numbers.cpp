// Given an integer array, find three numbers whose product is maximum and output the maximum product.
//
// Example 1:
//
//
// Input: [1,2,3]
// Output: 6
//
//
//  
//
// Example 2:
//
//
// Input: [1,2,3,4]
// Output: 24
//
//
//  
//
// Note:
//
//
// 	The length of the given array will be in range [3,104] and all elements are in the range [-1000, 1000].
// 	Multiplication of any three numbers in the input won't exceed the range of 32-bit signed integer.
//
//
//  
//


class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int large1 = INT_MIN, large2 =INT_MIN, large3 = INT_MIN;   //1>2>3
        int sma1 = INT_MAX, sma2 = INT_MAX;                        //1<2
        
        for(int num : nums){
            if(num>large1){
                large3 = large2;
                large2 = large1;
                large1 = num;
            }
            else if(num>large2){
                large3 = large2;
                large2 = num;
            }
            else if(num>large3){
                large3 = num;
            }
            
            if(num<sma1){
                sma2 = sma1;
                sma1 = num;
            }
            else if(num<sma2) sma2 = num;
        }
        
        return max(large1*large2*large3, sma1*sma2*large1);
    }
};
