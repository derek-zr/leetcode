// You are given the number of rows n_rows and number of columns n_cols of a 2D binary matrix where all values are initially 0. Write a function flip which chooses a 0 value uniformly at random, changes it to 1, and then returns the position [row.id, col.id] of that value. Also, write a function reset which sets all values back to 0. Try to minimize the number of calls to system's Math.random() and optimize the time and space complexity.
//
// Note:
//
//
// 	1 <= n_rows, n_cols <= 10000
// 	0 <= row.id < n_rows and 0 <= col.id < n_cols
// 	flip will not be called when the matrix has no 0 values left.
// 	the total number of calls to flip and reset will not exceed 1000.
//
//
// Example 1:
//
//
// Input: 
// ["Solution","flip","flip","flip","flip"]
// [[2,3],[],[],[],[]]
// Output: [null,[0,1],[1,2],[1,0],[1,1]]
//
//
//
// Example 2:
//
//
// Input: 
// ["Solution","flip","flip","reset","flip"]
// [[1,2],[],[],[],[]]
// Output: [null,[0,0],[0,1],null,[0,0]]
//
//
// Explanation of Input Syntax:
//
// The input is two lists: the subroutines called and their arguments. Solution's constructor has two arguments, n_rows and n_cols. flip and reset have no arguments. Arguments are always wrapped with a list, even if there aren't any.
//


class Solution {
public:
/*
   还有一种存储映射关系的方法，但是比较难想。
   我们需要使用一个变量size，初始化为矩形的长乘以宽，然后还是只生成一个随机数id，并使用另一个变量val来记录它。接下来我们给size自减1，我们知道 rand() % size 得到的随机数的范围是 [0, size-1]，那么假如第一次随机出了size-1后，此时size自减1之后，下一次不必担心还会随机出size-1，因为此时的size比之前减少了1。如果第一次随机出了0，假设最开始size=4，那么此时自减1之后，size=3，此时我们将0映射到3。那么下次我们如果再次随机出了0，此时size自减1之后，size=2，现在0有映射值，所以我们将id改为其映射值3，然后再将0映射到2，这样下次就算再摇出了0，我们还可以改变id值。大家有没有发现，我们的映射值都是没有没使用过的数字，这也是为啥开始先检测id是否被使用了，若已经被使用了，则换成其映射值，然后再更新之前的id的映射值，找到下一个未被使用的值即可。
   核心代码如下：
    vector<int> flip() {
        int id = rand() % size, val = id;
        --size;
        if (m.count(id)) id = m[id];
        m[val] = m.count(size) ? m[size] : size;
        return {id / col, id % col};
    }
*/
    Solution(int n_rows, int n_cols) {
        row = n_rows;
        col = n_cols;
    }
    
    vector<int> flip() {
        while(true) {
            int val = rand() % (row*col);
            if(!flipped.count(val)) {
                flipped.insert(val);
                return {val / col , val % col};
            }
        }
    }
    
    void reset() {
        flipped.clear();
    }
    
private:
    int row, col;
    unordered_set<int> flipped;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n_rows, n_cols);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */
