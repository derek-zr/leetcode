// You are given two integer arrays nums1 and nums2 sorted in ascending order and an integer k.
//
// Define a pair (u,v) which consists of one element from the first array and one element from the second array.
//
// Find the k pairs (u1,v1),(u2,v2) ...(uk,vk) with the smallest sums.
//
// Example 1:
//
//
// Input: nums1 = [1,7,11], nums2 = [2,4,6], k = 3
// Output: [[1,2],[1,4],[1,6]] 
// Explanation: The first 3 pairs are returned from the sequence: 
//              [1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]
//
// Example 2:
//
//
// Input: nums1 = [1,1,2], nums2 = [1,2,3], k = 2
// Output: [1,1],[1,1]
// Explanation: The first 2 pairs are returned from the sequence: 
//              [1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]
//
// Example 3:
//
//
// Input: nums1 = [1,2], nums2 = [3], k = 3
// Output: [1,3],[2,3]
// Explanation: All possible pairs are returned from the sequence: [1,3],[2,3]
//
//


class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> ans;
        priority_queue<vector<int> , vector<vector<int>> , compare> q;
        
        //开始遍历
        for(int i = 0; i < min((int)nums1.size(),k); ++i) {
            for(int j = 0; j < min((int)nums2.size(),k); ++j) {
                if(q.size() < k) {
                    q.push({nums1[i] , nums2[j]});
                }
                else if(nums1[i] + nums2[j] < q.top()[0] + q.top()[1]) {
                    q.push({nums1[i] , nums2[j]});
                    q.pop();
                }
            }
        }
        while(!q.empty()) {
            ans.push_back(q.top());
            q.pop();
        }
        return ans;
    }
    
    struct compare {
      bool operator() (vector<int> &a , vector<int> &b) {
          return (a[0]+a[1]) < (b[0]+b[1]);
      }  
    };
};
