//
// Given a sorted array, two integers k and x, find the k closest elements to x in the array.  The result should also be sorted in ascending order.
// If there is a tie,  the smaller elements are always preferred.
//
//
// Example 1:
//
// Input: [1,2,3,4,5], k=4, x=3
// Output: [1,2,3,4]
//
//
//
//
// Example 2:
//
// Input: [1,2,3,4,5], k=4, x=-1
// Output: [1,2,3,4]
//
//
//
// Note:
//
// The value k is positive and will always be smaller than the length of the sorted array.
//  Length of the given array is positive and will not exceed 104
//  Absolute value of elements in the array and x will not exceed 104
//
//
//
//
//
//
// UPDATE (2017/9/19):
// The arr parameter had been changed to an array of integers (instead of a list of integers). Please reload the code definition to get the latest changes.
//


class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> ans;
        int len=arr.size();
        if(x<=arr[0]) {
            for(int i=0;i<k;i++) ans.push_back(arr[i]);
            return ans;
        }
        else if(x>=arr[len-1]){
            for(int i=len-k;i<len;i++) ans.push_back(arr[i]);
            return ans;
        }
        else{
            int index=-1;
            for(int i=1;i<len;i++){
                if(arr[i]>=x&&arr[i-1]<=x) {index=i;break;}
            }
            int p=index,q=index-1;
            for(int i=k;i>0;i--){
                if(q<0||p<len&&abs(arr[p]-x)<abs(arr[q]-x)) {ans.push_back(arr[p]);p++;}
                else {ans.push_back(arr[q]);q--;}
            }
            sort(ans.begin(),ans.end());
            return ans;
        }
    }
};
