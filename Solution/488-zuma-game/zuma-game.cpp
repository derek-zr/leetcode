// Think about Zuma Game. You have a row of balls on the table, colored red(R), yellow(Y), blue(B), green(G), and white(W). You also have several balls in your hand.
//
// Each time, you may choose a ball in your hand, and insert it into the row (including the leftmost place and rightmost place). Then, if there is a group of 3 or more balls in the same color touching, remove these balls. Keep doing this until no more balls can be removed.
//
// Find the minimal balls you have to insert to remove all the balls on the table. If you cannot remove all the balls, output -1.
//
//
// Examples:
// Input: "WRRBBW", "RB"
// Output: -1
// Explanation: WRRBBW -> WRR[R]BBW -> WBBW -> WBB[B]W -> WW
//
// Input: "WWRRBBWW", "WRBRW"
// Output: 2
// Explanation: WWRRBBWW -> WWRR[R]BBWW -> WWBBWW -> WWBB[B]WW -> WWWW -> empty
//
// Input:"G", "GGGGG"
// Output: 2
// Explanation: G -> G[G] -> GG[G] -> empty 
//
// Input: "RBYYBBRRB", "YRBGB"
// Output: 3
// Explanation: RBYYBBRRB -> RBYY[Y]BBRRB -> RBBBRRB -> RRRB -> B -> B[B] -> BB[B] -> empty 
//
//
//
// Note:
//
// You may assume that the initial row of balls on the table won’t have any 3 or more consecutive balls with the same color.
// The number of balls on the table won't exceed 20, and the string represents these balls is called "board" in the input.
// The number of balls in your hand won't exceed 5, and the string represents these balls is called "hand" in the input.
// Both input strings will be non-empty and only contain characters 'R','Y','B','G','W'.
//
//


class Solution {
public:
    int findMinStep(string board, string hand) {
        //dfs题目，遍历各种添加的情况
        int ans = INT_MAX;
        unordered_map<char, int> m;
        for (char c : hand) ++m[c];
        ans = helper(board, m);
        return ans == INT_MAX ? -1 : ans;
    }
    
    int helper(string board, unordered_map<char, int>& m) {
        //每次开始前去除三个连续重复的气球
        board = remove3groups(board);
        if (board.empty())  return 0;
        int balls = INT_MAX, start = 0;
        for (int end = 0; end <= board.size(); ++end) {
            if (end < board.size() && board[start] == board[end])  continue;
            //判断需要几个气球来凑成3个
            int needBalls = 3 - (end - start);
            if (m[board[start]] >= needBalls) {
                //手上的气球足够添加
                m[board[start]] -= needBalls;
                int nextBalls = helper(board.substr(0, start) + board.substr(end), m);
                if (nextBalls != INT_MAX)  balls = min(balls, nextBalls+needBalls);
                //恢复状态
                m[board[start]] += needBalls;
            }
            start = end;
        }
        return balls;
    }
    
    string remove3groups(string board) {
        int start = 0;
        for (int end = 0; end <= board.size(); ++end) {
            if (end < board.size() && board[end] == board[start]) continue;
            //递归处理其余子串的情况
            if (end - start >= 3) return remove3groups(board.substr(0, start) + board.substr(end));
            else start = end;
        }
        return board;
    }
    
};
