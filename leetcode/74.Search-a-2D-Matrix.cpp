// https://leetcode.com/problems/search-a-2d-matrix/description/
// https://www.youtube.com/watch?v=1CdolnvxLs0&t=4650s&ab_channel=CodeHelp-byBabbar
// the solution is at time stamp 1:02:45

// converting whole 2d matrix as linear sorted array

class Solution {
public:

    bool searchMatrix(vector<vector<int>>& arr, int x) {
        int n=arr.size();
        int m=arr[0].size();
        int start=0;
        int end=n*m-1;

        while(start<=end){
            int mid=start+(end-start)/2;
            if(arr[mid/m][mid%m]==x){
                return true;
            }
            else if(arr[mid/m][mid%m]<x){
                start=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        return false;
    }
};