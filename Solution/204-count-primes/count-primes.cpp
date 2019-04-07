// Count the number of prime numbers less than a non-negative number, n.
//
// Example:
//
//
// Input: 10
// Output: 4
// Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
//
//


class Solution {
public:
    int countPrimes(int n) {
        
        int cnts = 0;
        vector<bool> primes(n,true);  //到一个质数时，标识其所有的倍数
        
        for(int i = 2; i < n; ++i) {
            if(primes[i]) {
                ++cnts;
                for(int j = 2; i*j < n; ++j) {
                    primes[i*j] = false;
                }
            }
        }
        
        /*
        for(int i = 1; i < n; ++i) {
            if(isPrime(i)) ++cnts;
        }
        */
        return cnts;
    }
    
    bool isPrime(int num) {
        if(num <= 1) return false;
        for(int i = 2; i*i <= num; ++i) {
            if(num % i == 0) return false;
        }
        
        return true;
    }
};
