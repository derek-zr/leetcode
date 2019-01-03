// Your task is to calculate ab mod 1337 where a is a positive integer and b is an extremely large positive integer given in the form of an array.
//
// Example 1:
//
//
//
// Input: a = 2, b = [3]
// Output: 8
//
//
//
// Example 2:
//
//
// Input: a = 2, b = [1,0]
// Output: 1024
//
//
//


class Solution {
    
    const int base = 1337;
    int powMod(int a,int k){
        int result = 1;
        a %= base;
        for(int i=0;i<k;i++){
            result = (result*a) % base;
        }
        return result;
    }
    
public:
    int superPow(int a, vector<int>& b) {
        if(b.size()==0) return 1;
        int last = b.back();
        b.pop_back();
        return powMod(superPow(a,b),10) * powMod(a,last) % base;
    }
};
