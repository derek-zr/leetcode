// Given the radius and x-y positions of the center of a circle, write a function randPoint which generates a uniform random point in the circle.
//
// Note:
//
//
// 	input and output values are in floating-point.
// 	radius and x-y position of the center of the circle is passed into the class constructor.
// 	a point on the circumference of the circle is considered to be in the circle.
// 	randPoint returns a size 2 array containing x-position and y-position of the random point, in that order.
//
//
//
// Example 1:
//
//
// Input: 
// ["Solution","randPoint","randPoint","randPoint"]
// [[1,0,0],[],[],[]]
// Output: [null,[-0.72939,-0.65505],[-0.78502,-0.28626],[-0.83119,-0.19803]]
//
//
//
// Example 2:
//
//
// Input: 
// ["Solution","randPoint","randPoint","randPoint"]
// [[10,5,-7.5],[],[],[]]
// Output: [null,[11.52438,-8.33273],[2.46992,-16.21705],[11.13430,-12.42337]]
//
//
// Explanation of Input Syntax:
//
// The input is two lists: the subroutines called and their arguments. Solution's constructor has three arguments, the radius, x-position of the center, and y-position of the center of the circle. randPoint has no arguments. Arguments are always wrapped with a list, even if there aren't any.
//
//


class Solution {
public:
    Solution(double radius, double x_center, double y_center) {
        r = radius;
        x = x_center;
        y = y_center;
    }
    
    //第一种思想是用极坐标的方法，随机rand出一个角度和长度，利用圆的极坐标形式即可得到点，但这种方法在取随机长度时需要考虑表达式里的平方关系。
    //第二种方法是拒绝采样，随机产生坐标，不符合条件则拒绝，符合则返回
    vector<double> randPoint() {
        while (true) {
            double tmp_x = (2 * (double)rand() / RAND_MAX - 1.0) * r;
            double tmp_y = (2 * (double)rand() / RAND_MAX - 1.0) * r;
            if (tmp_x * tmp_x + tmp_y * tmp_y <= r * r) return {x + tmp_x, y + tmp_y};
        }
    }
private:
    double r , x, y;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */
