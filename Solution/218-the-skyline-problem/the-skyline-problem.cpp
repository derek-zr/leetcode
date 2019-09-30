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
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        //这道题有两个关键点：
        //第一个是必须要按照顺序遍历左边界，再遍历右边界。即先找左边界构成的point，再找由于右边界相交产生的point
        //第二个是如何判断产生了point：
        //对于左边界，只要出现了自身比之前的最高高度还高，则说明产生了point
        //对于右边界，如果去除自身，自身高度仍然高于当前的最高高度，也会产生point
        vector<pair<int, int>> heights;
        vector<vector<int>>  ans;
        multiset<int> m;     //可能存在多个相同的高度
        
        //存储所有的高度，便于排序遍历
        for (auto build : buildings) {
            //这里有个技巧，左边界压入的是高度负值，便于区分左右边界，这样就不需要自定义排序函数
            heights.push_back({build[0], -build[2]});
            heights.push_back({build[1], build[2]});
        }
        
        //横坐标排序，同时保证左坐标在前面
        sort(heights.begin(), heights.end());
        
        //插入一个0，便于最后一个点确定
        m.insert(0);
        
        int preHighest = 0, curHighest = 0;
        
        for (auto p : heights) {
            //遇到左边界则插入，遇到右边界则删除
            if (p.second < 0)  m.insert({-p.second});
            else m.erase(m.find(p.second));
            
            //当前最高的，set会自动排序
            curHighest = *m.rbegin();
            
            if (curHighest != preHighest) {
                //遇到高度变化则说明有point
                //cout<<p.first<<curHighest<<endl;
                ans.push_back({p.first, curHighest});
                preHighest = curHighest;
            }
        }
        
        return ans;
    }
};
