// https://leetcode.com/problems/search-in-rotated-sorted-array/description/
// https://www.youtube.com/watch?v=Id-DdcWb5AU&list=PL_z_8CaSLPWeYfhtuKHj-9MpYb6XQJ_f2&index=8&ab_channel=AdityaVerma

// https://leetcode.com/problems/search-in-rotated-sorted-array-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int rotateIndex = -1;
        int n = nums.size();
        for (int i = 0; i < n - 1; i++)
        {
            if (nums[i] > nums[i + 1])
            {
                rotateIndex = i;
                break;
            }
        }
        if (binarySearch(nums, target, 0, rotateIndex) == -1 && binarySearch(nums, target, rotateIndex + 1, n - 1) != -1)
        {
            return binarySearch(nums, target, rotateIndex + 1, n - 1);
        }
        else if (binarySearch(nums, target, 0, rotateIndex) != -1 && binarySearch(nums, target, rotateIndex + 1, n - 1) == -1)
        {
            return binarySearch(nums, target, 0, rotateIndex);
        }
        return -1;
    }

    int binarySearch(vector<int> &arr, int target, int start, int end)
    {

        while (start <= end)
        {
            // int mid=(start+end)/2;                      // might cause overflow due to addition of two large values
            int mid = start + (end - start) / 2; // prevent overflow
            if (arr[mid] == target)
            {
                return mid;
            }
            else if (target < arr[mid])
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        return -1;
    }
};