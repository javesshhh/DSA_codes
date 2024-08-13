// https://www.youtube.com/watch?v=8x6dmO6XW8k&list=PL_z_8CaSLPWeYfhtuKHj-9MpYb6XQJ_f2&index=14&ab_channel=AdityaVerma
// https://www.geeksforgeeks.org/find-index-first-1-infinite-sorted-array-0s-1s/

#include <bits/stdc++.h>
using namespace std;

int posOfFirstOne(int a[])
{
    // find the upper and lower bounds between
    // which the first '1' would be present
    int start = 0, end = 1;

    // as the array is being considered infinite
    // therefore 'h' index will always exist in
    // the array
    while (a[end] == 0)
    {

        // lower bound
        start = end;

        // upper bound
        end = 2 * end;
    }

    // required index of first '1'
    int index = -1;
    ;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (a[mid] == 1)
        {
            index = mid;
            end = mid - 1;
        }
        else if (a[mid] < 1)
        {
            start = mid + 1;
        }
    }
    return index;
}

int main()
{
    int arr[] = {0, 0, 1, 1, 1, 1};
    cout << "Index = "
         << posOfFirstOne(arr);
    return 0;
}