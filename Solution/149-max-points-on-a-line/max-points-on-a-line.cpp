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


/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point>& points) {
        int ans = 0;
        int len = points.size();
        for(int i = 0; i < len; ++i) {
            map<pair<int,int>,int> m ; //考虑到斜率要算除法，如果直接相除可能存在double精度不够的情况，所以这里改存分子和分母
            int dup = 1;  //可能存在相同坐标的点
            for(int j = i+1; j < len; ++j) {
                if(points[i].x == points[j].x && points[i].y == points[j].y) {++dup;continue;}
                int dx = points[j].x - points[i].x;
                int dy = points[j].y - points[i].y;
                int d = gcd(dx,dy);   //求分子分母的最大公约数
                ++m[{dx/d,dy/d}];
            }
            ans = max(ans,dup);
            for(auto it = m.begin(); it != m.end(); ++it) ans = max(ans,it->second+dup);
        }
        
        return ans;
    }
    
    int gcd(int num1,int num2) {
        return (num2==0) ? num1 : gcd(num2,num1%num2);
    }
};
