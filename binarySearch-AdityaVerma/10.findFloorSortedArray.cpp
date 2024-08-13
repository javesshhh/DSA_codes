// https://practice.geeksforgeeks.org/problems/floor-in-a-sorted-array-1587115620/1?utm_source=geeksforgeeks&utm_medium=article_practice_tab&utm_campaign=article_practice_tab
// https://www.youtube.com/watch?v=5cx0xerA8XY&list=PL_z_8CaSLPWeYfhtuKHj-9MpYb6XQJ_f2&index=10&ab_channel=AdityaVerma
// https://www.geeksforgeeks.org/floor-in-a-sorted-array/

// Function to find floor of x
// n: size of vector
// x: element whose floor is to find
int findFloor(vector<long long> arr, long long n, long long target)
{

    int start = 0;
    int end = n - 1;
    int floor = -1;
    while (start <= end)
    {
        // int mid=(start+end)/2;                      // might cause overflow due to addition of two large values
        int mid = start + (end - start) / 2; // prevent overflow
        if (arr[mid] == target)
        {
            return mid;
        }
        else if (target > arr[mid])
        {
            floor = mid;
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return floor;
}

// Think about approach given below it may help:
// floor : end pointer after the whole execution of loop,if mid is not exist.
// ceil : start pointer after the whole execution of loop,if mid is not exist.