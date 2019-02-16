// In a row of seats, 1 represents a person sitting in that seat, and 0 represents that the seat is empty. 
//
// There is at least one empty seat, and at least one person sitting.
//
// Alex wants to sit in the seat such that the distance between him and the closest person to him is maximized. 
//
// Return that maximum distance to closest person.
//
//
// Example 1:
//
//
// Input: [1,0,0,0,1,0,1]
// Output: 2
// Explanation: 
// If Alex sits in the second open seat (seats[2]), then the closest person has distance 2.
// If Alex sits in any other open seat, the closest person has distance 1.
// Thus, the maximum distance to the closest person is 2.
//
//
// Example 2:
//
//
// Input: [1,0,0,0]
// Output: 3
// Explanation: 
// If Alex sits in the last seat, the closest person is 3 seats away.
// This is the maximum distance possible, so the answer is 3.
//
//
// Note:
//
//
// 	1 <= seats.length <= 20000
// 	seats contains only 0s or 1s, at least one 0, and at least one 1.
//
//
//
//


class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int first_1 = 0;
        int last_1 = 0;
        int max_dis = 0;
        int len = seats.size();
        for(int i=0;i<len;i++){
            if(seats[i]==1) {first_1=i;break;}
        }
        for(int i=len-1;i>=0;i--){
            if(seats[i]==1) {last_1=i;break;}
        }
        max_dis = max(first_1,len-1-last_1);
        if(max_dis==(len-1)) return max_dis;
        int pre_1 = first_1;
        for(int i=pre_1+1;i<len;i++){
            if(seats[i]==1){
                int tmp_dis = i-pre_1;
                tmp_dis = tmp_dis/2;
                pre_1 = i;
                max_dis = max(max_dis,tmp_dis);
            }
        }
        
        return max_dis;
    }
};
