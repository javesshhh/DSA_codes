// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
// https://youtu.be/4WmTRFZilj8

class Solution {
public:
    int findMin(vector<int>& arr) {
        int n=arr.size();
        int start=0;
	    int end=n-1;
         //array is sorted -> No Rotation
	    if(arr[start]<=arr[end]){
	        return arr[start];
	    }
        // // There is only single element in array -> No Rotation
	    // if(arr[low]==arr[high]) return 0;

	    while(start<=end){
	        int mid=start+(end-start)/2;
	        int prev=(mid+n-1)%n;                        // to avoid out of bound situation
	        int next=(mid+1)%n;                          //
	        if(arr[mid]<=arr[next] && arr[mid]<=arr[prev]){
	            return arr[mid];
	        }
	        else if(arr[mid]>=arr[0]){
	            start=mid+1;                            // unsorted part
	        }
	        else if(arr[mid]<=arr[n-1]){
	            end=mid-1;                              // unsorted part
	        }
	    }
	    return arr[start];
    }
};