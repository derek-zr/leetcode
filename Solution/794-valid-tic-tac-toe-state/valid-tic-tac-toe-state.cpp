// A Tic-Tac-Toe board is given as a string array board. Return True if and only if it is possible to reach this board position during the course of a valid tic-tac-toe game.
//
// The board is a 3 x 3 array, and consists of characters " ", "X", and "O".  The " " character represents an empty square.
//
// Here are the rules of Tic-Tac-Toe:
//
//
// 	Players take turns placing characters into empty squares (" ").
// 	The first player always places "X" characters, while the second player always places "O" characters.
// 	"X" and "O" characters are always placed into empty squares, never filled ones.
// 	The game ends when there are 3 of the same (non-empty) character filling any row, column, or diagonal.
// 	The game also ends if all squares are non-empty.
// 	No more moves can be played if the game is over.
//
//
//
// Example 1:
// Input: board = ["O  ", "   ", "   "]
// Output: false
// Explanation: The first player always plays "X".
//
// Example 2:
// Input: board = ["XOX", " X ", "   "]
// Output: false
// Explanation: Players take turns making moves.
//
// Example 3:
// Input: board = ["XXX", "   ", "OOO"]
// Output: false
//
// Example 4:
// Input: board = ["XOX", "O O", "XOX"]
// Output: true
//
//
// Note:
//
//
// 	board is a length-3 array of strings, where each string board[i] has length 3.
// 	Each board[i][j] is a character in the set {" ", "X", "O"}.
//
//


class Solution {
public:
    bool validTicTacToe(vector<string>& board) {
        //判断传进来的board是否可能是下棋过程中出现的状态
        //X:cnts+1 O:cnts-1 cnts最终只能为0或+1
        //记录X win还是O win. 如果其中一个win了，则游戏已经结束
        int cnts = 0;
        int X_Win = false,O_Win=false;
        for(int i=0;i<board.size();i++){
            for(char a:board[i]){
                if(a=='X') cnts++;
                else if(a=='O') cnts--;
            }
        }
        
        if(cnts!=0 && cnts!=1) return false;
        
        //记录胜负情况
        for(string s:board){
            if(s[0]==s[1] && s[1]==s[2] && s[0]=='X')  X_Win=true;
            else if(s[0]==s[1] && s[1]==s[2] && s[0]=='O') O_Win=true;
        }
        //cout<<X_Win<<O_Win<<endl;
        
        string s0 =board[0];
        string s1 =board[1];
        string s2 =board[2];
        for(int i=0;i<s0.size();i++){
            if(s0[i]==s1[i] && s1[i]==s2[i] && s0[i]=='X')  X_Win=true;
            else if(s0[i]==s1[i] && s1[i]==s2[i] && s0[i]=='O') O_Win=true;
        }
        
        if(s0[0]==s1[1] && s1[1]==s2[2] && s0[0]=='X') X_Win=true;
        else if(s0[0]==s1[1] && s1[1]==s2[2] && s0[0]=='O') O_Win=true;
        
        if(s0[2]==s1[1] && s1[1]==s2[0] && s0[2]=='X') X_Win=true;
        else if(s0[2]==s1[1] && s1[1]==s2[0] && s0[2]=='O') O_Win=true;
        
        //cout<<X_Win<<O_Win<<endl;
        if(X_Win && O_Win) return false;
        if(X_Win && cnts==0) return false;  //X赢的时候，X的个数必然大于O一个
        if(O_Win && cnts==1) return false;  //O赢的时候，X的个数必然等于O
        
        return true;
        
    }
};
