// Given n points in the plane that are all pairwise distinct, a "boomerang" is a tuple of points (i, j, k) such that the distance between i and j equals the distance between i and k (the order of the tuple matters).
//
// Find the number of boomerangs. You may assume that n will be at most 500 and coordinates of points are all in the range [-10000, 10000] (inclusive).
//
// Example:
//
//
// Input:
// [[0,0],[1,0],[2,0]]
//
// Output:
// 2
//
// Explanation:
// The two boomerangs are [[1,0],[0,0],[2,0]] and [[1,0],[2,0],[0,0]]
//
//
//  
//


class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        //hashmap存储各点之间的距离
        int ans = 0;
        for(auto &p : points) {
            unordered_map<double,int> cnts;
            for(auto &q : points) {
                double tmp = pow(p[0]-q[0],2) + pow(p[1]-q[1],2);
                ans += 2*cnts[tmp]; //可以组成两对顺序不同
                ++cnts[tmp];
            }
        }
        return ans;
    }
};
