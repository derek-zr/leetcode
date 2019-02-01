// Given a set of points in the xy-plane, determine the minimum area of a rectangle formed from these points, with sides parallel to the x and y axes.
//
// If there isn't any rectangle, return 0.
//
//  
//
//
// Example 1:
//
//
// Input: [[1,1],[1,3],[3,1],[3,3],[2,2]]
// Output: 4
//
//
//
// Example 2:
//
//
// Input: [[1,1],[1,3],[3,1],[3,3],[4,1],[4,3]]
// Output: 2
//
//
//  
//
// Note:
//
//
// 	1 <= points.length <= 500
// 	0 <= points[i][0] <= 40000
// 	0 <= points[i][1] <= 40000
// 	All points are distinct.
//
//
//


class Solution {
public:
    //用一个hashmap和set
    int minAreaRect(vector<vector<int>>& points) {
        if(points.size()==0) return 0;
        map<int,set<int>> m;
        for(auto p : points){
            m[p[0]].insert(p[1]);
        }
        
        int min_area = INT_MAX;
        for(auto p1 : points){
            for(auto p2 : points){    
                //p1 p2 为对角线上的两个点
                if(p1[0]==p2[0] || p1[1]==p2[1]) continue;
                if(m[p1[0]].count(p2[1]) && m[p2[0]].count(p1[1])) {
                    //这四个点均存在
                    int tmp_area = abs(p1[0]-p2[0])*abs(p1[1]-p2[1]);
                    min_area = min(min_area,tmp_area);
                }
            }
        }
        
        return min_area==INT_MAX? 0 : min_area;
    }
};
