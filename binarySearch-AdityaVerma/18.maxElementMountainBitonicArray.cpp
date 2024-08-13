// https://www.youtube.com/watch?v=BrrZL1RDMwc&list=PL_z_8CaSLPWeYfhtuKHj-9MpYb6XQJ_f2&index=18&ab_channel=AdityaVerma

// https://leetcode.com/problems/peak-index-in-a-mountain-array/description/

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int start = 0;
        int end = arr.size() - 1;

        int mid;

        while(start<=end)
        {
            mid = start  + (end - start)/2;

            if(arr[mid] > arr[mid - 1] && arr[mid] > arr[mid+1])
            {
                return mid;
            }
            if(arr[mid] < arr[mid + 1] && arr[mid] > arr[mid - 1])
            start = mid+1 ;
            else
            end = mid ;
        }
        return mid;
    }
};