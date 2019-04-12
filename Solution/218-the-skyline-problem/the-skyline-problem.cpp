// A city's skyline is the outer contour of the silhouette formed by all the buildings in that city when viewed from a distance. Now suppose you are given the locations and height of all the buildings as shown on a cityscape photo (Figure A), write a program to output the skyline formed by these buildings collectively (Figure B).
//
//
// The geometric information of each building is represented by a triplet of integers [Li, Ri, Hi], where Li and Ri are the x coordinates of the left and right edge of the ith building, respectively, and Hi is its height. It is guaranteed that 0 ≤ Li, Ri ≤ INT_MAX, 0 < Hi ≤ INT_MAX, and Ri - Li > 0. You may assume all buildings are perfect rectangles grounded on an absolutely flat surface at height 0.
//
// For instance, the dimensions of all buildings in Figure A are recorded as: [ [2 9 10], [3 7 15], [5 12 12], [15 20 10], [19 24 8] ] .
//
// The output is a list of "key points" (red dots in Figure B) in the format of [ [x1,y1], [x2, y2], [x3, y3], ... ] that uniquely defines a skyline. A key point is the left endpoint of a horizontal line segment. Note that the last key point, where the rightmost building ends, is merely used to mark the termination of the skyline, and always has zero height. Also, the ground in between any two adjacent buildings should be considered part of the skyline contour.
//
// For instance, the skyline in Figure B should be represented as:[ [2 10], [3 15], [7 12], [12 0], [15 10], [20 8], [24, 0] ].
//
// Notes:
//
//
// 	The number of buildings in any input list is guaranteed to be in the range [0, 10000].
// 	The input list is already sorted in ascending order by the left x position Li.
// 	The output list must be sorted by the x position.
// 	There must be no consecutive horizontal lines of equal height in the output skyline. For instance, [...[2 3], [4 5], [7 5], [11 5], [12 7]...] is not acceptable; the three lines of height 5 should be merged into one in the final output as such: [...[2 3], [4 5], [12 7], ...]
//
//


class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int,int>> height,ans;
        multiset<int> m;     //用multiset（可能存在多个相同的高度）储存当前遍历到的高度
        
        //存储所有的高度
        for(auto p : buildings) {
            height.push_back({p[0],-p[2]});  //左边界高度存成负数，和右边界区分
            height.push_back({p[1],p[2]});
        }
        //根据左边界排序
        sort(height.begin(),height.end());
        
        //先插入一个0，最后遍历时得到最右的keypoint
        m.insert(0);
        
        int pre = 0, cur = 0; //pre为0，则左边界一定能插入
        
        for(auto p : height) {
            if(p.second < 0) m.insert(-p.second);   //遇到左边界则插入
            else m.erase(m.find(p.second));         //遇到右边界则删除（说明此时该大楼已经达到右边界，不会影响后面的skyline了）
            
            cur = *m.rbegin();    //取出此时遍历到的最高的大楼高度
            if(cur != pre) {      //如果当前的最高高度与之前的最高高度不相等，则说明出现了keypoint
                ans.push_back({p.first,cur});   //横坐标为当前遍历的坐标，高度为最高高度
                pre = cur;
            }
        }
        
        return ans;
    }
};
