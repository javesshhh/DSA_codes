// https://www.youtube.com/watch?v=ogjf7ORKfd8&list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9&index=8&ab_channel=takeUforward
// https://takeuforward.org/data-structure/merge-sort-algorithm/
// https://leetcode.com/problems/sort-an-array/description/

class Solution
{
public:
    void merge(vector<int> &arr, int low, int mid, int high)
    {
        vector<int> temp;    // temporary array
        int left = low;      // starting index of left half of arr
        int right = mid + 1; // starting index of right half of arr

        // storing elements in the temporary array in a sorted manner//

        while (left <= mid && right <= high)
        {
            if (arr[left] <= arr[right])
            {
                temp.push_back(arr[left]);
                left++;
            }
            else
            {
                temp.push_back(arr[right]);
                right++;
            }
        }

        // if elements on the left half are still left //

        while (left <= mid)
        {
            temp.push_back(arr[left]);
            left++;
        }

        //  if elements on the right half are still left //
        while (right <= high)
        {
            temp.push_back(arr[right]);
            right++;
        }

        // transfering all elements from temporary to arr //
        for (int i = low; i <= high; i++)
        {
            arr[i] = temp[i - low];
        }
    }

    void mergeSort(vector<int> &arr, int low, int high)
    {
        if (low >= high)
            return;
        int mid = (low + high) / 2;
        mergeSort(arr, low, mid);      // left half
        mergeSort(arr, mid + 1, high); // right half
        merge(arr, low, mid, high);    // merging sorted halves
    }

    vector<int> sortArray(vector<int> &arr)
    {
        // vector<int>arr;
        int n = arr.size();
        mergeSort(arr, 0, n - 1);
        return arr;
    }
};