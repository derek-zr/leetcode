// You have a number of envelopes with widths and heights given as a pair of integers (w, h). One envelope can fit into another if and only if both the width and height of one envelope is greater than the width and height of the other envelope.
//
// What is the maximum number of envelopes can you Russian doll? (put one inside other)
//
// Note:
// Rotation is not allowed.
//
// Example:
//
//
//
// Input: [[5,4],[6,4],[6,7],[2,3]]
// Output: 3 
// Explanation: The maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).
//
//
//


class Solution {    
public:
    
    static bool cmp(pair<int,int> a,pair<int,int> b){
        if(a.first==b.first) return a.second>b.second;
        return a.first<b.first;
    }
    
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        if(envelopes.size()==0||envelopes.size()==1) return envelopes.size();
        sort(envelopes.begin(),envelopes.end(),cmp);
        vector<int> dp;
        dp.push_back(envelopes[0].second);
        for(int i=1;i<envelopes.size();i++){
            if(envelopes[i].second > dp.back()) {dp.push_back(envelopes[i].second);continue;}
            
            //二分查找插入位置
            int left=0,mid=0,right=dp.size();
            while(left<right){
                mid = left+(right-left)/2;
                if(dp[mid]<envelopes[i].second) left=mid+1;
                else right=mid;
            }
            dp[right] = envelopes[i].second;
            
        }
        
        return dp.size();
    }
};
