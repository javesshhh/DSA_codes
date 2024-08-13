// https://leetcode.com/problems/search-in-rotated-sorted-array/description/
// https://www.youtube.com/watch?v=Id-DdcWb5AU&list=PL_z_8CaSLPWeYfhtuKHj-9MpYb6XQJ_f2&index=8&ab_channel=AdityaVerma

class Solution {
public:

    // finding index of minimum element and calling simple binary search function on both sorted sides for min element

    int binarySearch(vector<int>& arr, int target,int ans,int start,int end){
        
    while(start<=end){
        // int mid=(start+end)/2;                      // might cause overflow due to addition of two large values
        int mid=start + (end-start)/2;                 // prevent overflow
        if(arr[mid]==target){
            return mid;
        }
        else if(target<arr[mid]){
            end=mid-1;
        }
        else{
            start=mid+1;
        }
    }
    return -1;
    }

    int min(vector<int>& arr, int target){
        int n=arr.size();
        int start=0;
	    int end=n-1;
        int index=0;
         //array is sorted -> No Rotation
	    if(arr[start]<=arr[end]){
	        return index=start;
	    }
        // // There is only single element in array -> No Rotation
	    // if(arr[low]==arr[high]) return 0;

	    while(start<=end){
	        int mid=start+(end-start)/2;
	        int prev=(mid+n-1)%n;                        // to avoid out of bound situation
	        int next=(mid+1)%n;                          //
	        if(arr[mid]<=arr[next] && arr[mid]<=arr[prev]){
	            return index=mid;
	        }
	        else if(arr[mid]>=arr[0]){
	            start=mid+1;                            // unsorted part
	        }
	        else if(arr[mid]<=arr[n-1]){
	            end=mid-1;                              // unsorted part
	        }
	    }
        return index;
    }

    int search(vector<int>& arr, int target) {
        
	    int n=arr.size();
        int ans=-1;
        if(binarySearch(arr,target,ans,0,min(arr,target)-1)==-1 && binarySearch(arr,target,ans,min(arr,target),n-1)!=-1){
            return binarySearch(arr,target,ans,min(arr,target),n-1);
        }
        else if(binarySearch(arr,target,ans,0,min(arr,target)-1)!=-1 && binarySearch(arr,target,ans,min(arr,target),n-1)==-1){
            return binarySearch(arr,target,ans,0,min(arr,target)-1);
        }
        return -1;
    }
};