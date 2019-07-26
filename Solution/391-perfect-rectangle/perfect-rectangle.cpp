// Given N axis-aligned rectangles where N > 0, determine if they all together form an exact cover of a rectangular region.
//
// Each rectangle is represented as a bottom-left point and a top-right point. For example, a unit square is represented as [1,1,2,2]. (coordinate of bottom-left point is (1, 1) and top-right point is (2, 2)).
//
//
//
// Example 1:
//
//
// rectangles = [
//   [1,1,3,3],
//   [3,1,4,2],
//   [3,2,4,4],
//   [1,3,2,4],
//   [2,3,3,4]
// ]
//
// Return true. All 5 rectangles together form an exact cover of a rectangular region.
//
//
//  
//
//  
//
//
//
// Example 2:
//
//
// rectangles = [
//   [1,1,2,3],
//   [1,3,2,4],
//   [3,1,4,2],
//   [3,2,4,4]
// ]
//
// Return false. Because there is a gap between the two rectangular regions.
//
//
//  
//
//  
//
//
//
// Example 3:
//
//
// rectangles = [
//   [1,1,3,3],
//   [3,1,4,2],
//   [1,3,2,4],
//   [3,2,4,4]
// ]
//
// Return false. Because there is a gap in the top center.
//
//
//  
//
//  
//
//
//
// Example 4:
//
//
// rectangles = [
//   [1,1,3,3],
//   [3,1,4,2],
//   [1,3,2,4],
//   [2,2,4,4]
// ]
//
// Return false. Because two of the rectangles overlap with each other.
//
//
//  


class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        //从顶点的角度出发，除了最大的矩形框，其余矩形框的顶点，应该都是一一匹配的。
        //即某一个矩形框的左下或者右上的点都应当有与之匹配的其他右下或左上的点
        int min_x = INT_MAX, min_y = INT_MAX, max_x = INT_MIN, max_y = INT_MIN;
        unordered_map<int,unordered_map<int,int>> m;
        for(auto &r : rectangles) {
            int x1 = r[0] , y1 = r[1] , x2 = r[2] ,  y2 = r[3];
            //cout<<"in";
            min_x = min(min_x,x1);
            min_y = min(min_y,y1);
            max_x = max(max_x,x2);
            max_y = max(max_y,y2);
            ++m[x1][y1];  //遇到左上或右下加
            ++m[x2][y2];
            --m[x1][y2];  //遇到左下或者右上减
            --m[x2][y1];
        }
        //先判断最大矩形框的情况
        if(m[min_x][min_y] != 1 || m[max_x][max_y] != 1 || m[min_x][max_y] != -1 || m[max_x][min_y] != -1) return false;
        m[min_x].erase(min_y);
        m[min_x].erase(max_y);
        m[max_x].erase(min_y);
        m[max_x].erase(max_y);
        
        //其余的顶点坐标值，对应的都应该为0
        for(auto &it: m) {
            for(auto &c : it.second) {
                if(c.second != 0) return false;
            }
        }
        return true;
    }
};

