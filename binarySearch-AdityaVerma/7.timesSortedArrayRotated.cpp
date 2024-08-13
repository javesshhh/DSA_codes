// https://practice.geeksforgeeks.org/problems/rotation4723/1
// https://www.youtube.com/watch?v=4WmTRFZilj8&list=PL_z_8CaSLPWeYfhtuKHj-9MpYb6XQJ_f2&index=7&ab_channel=AdityaVerma

// To find the number of rotations in a rotated sorted array, we need to find the index of the minimum element,
// so this question gets converted to finding the index of the minimum element.

class Solution{
public:
	int findKRotation(int arr[], int n) {
	    // code here
	    int start=0;
	    int end=n-1;
         //array is sorted -> No Rotation
	    if(arr[start]<=arr[end]){
	        return 0;
	    }

	    while(start<=end){
	        int mid=start+(end-start)/2;
	        int prev=(mid-1);                        // to avoid out of bound situation
	        if(arr[mid]<arr[prev]){
	            return mid;
	        }
	        else if(arr[mid]>=arr[0]){
	            start=mid+1;                            // unsorted part
	        }
	        else if(arr[mid]<=arr[n-1]){
	            end=mid-1;                              // unsorted part
	        }
	    }
	    return 0;
	}
};