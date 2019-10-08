// Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.
//
// Example 1:
//
//
// Input: [[1,1],[2,2],[3,3]]
// Output: 3
// Explanation:
// ^
// |
// |        o
// |     o
// |  o  
// +------------->
// 0  1  2  3  4
//
//
// Example 2:
//
//
// Input: [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
// Output: 4
// Explanation:
// ^
// |
// |  o
// |     o        o
// |        o
// |  o        o
// +------------------->
// 0  1  2  3  4  5  6
//
//
// NOTE: input types have been changed on April 15, 2019. Please reset to default code definition to get new method signature.
//


class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        //同一个斜率的点在同一条直线上，但问题在于斜率需要做除法，因此进度很难保证
        //所以这里同时保存分子和分母，即x的差值和y的差值
        int len = points.size();   
        int ans = 0;
        
        for (int i = 0 ; i < len; ++i) {
            map<pair<int, int>, int> m; 
            int dup = 1;
            for (int j = i+1; j < len; ++j) {
                //可能存在重复的点
                if (points[i][0] == points[j][0] && points[i][1] == points[j][1]) { ++dup; continue; }
                int dx = points[j][0] - points[i][0];    
                int dy = points[j][1] - points[i][1];
                //cout<<dx<<dy;
                int gcd_num = gcd(dx, dy);   //两者的最大公约数
                ++m[{dx / gcd_num, dy / gcd_num}];
            }
            ans = max(ans, dup);    //解决只有一个点的情况，以及全部为重复点的情况
            for (auto &p : m) ans = max(ans, p.second + dup);
        }
        
        return ans;
    }
    
    int gcd(int a, int b) {
        //对于负数情况也能够正确计算
        return (b == 0) ? a : gcd(b, a % b);    
    }
    
};
