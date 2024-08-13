// https://leetcode.com/problems/kth-missing-positive-number/description/
// https://www.youtube.com/watch?v=uZ0N_hZpyps&ab_channel=takeUforward

class Solution
{
public:
    int findKthPositive(vector<int> &arr, int k)
    {
        int ind = 0, ans = 1, n = arr.size();
        int count = 0;
        while (count != k)
        {
            if ((ind < n && ans < arr[ind]) || ind >= n)
                count++;
            if (ind < n && ans == arr[ind])
                ind++;
            ans++;
        }
        return ans - 1;
    }
};

// 1 2 4 8 9                  1 2 4 1 

class Solution
{
public:
    int findKthPositive(vector<int> &vec, int k)
    {
        int n = vec.size();
        int low = 0, high = n - 1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            int missing = vec[mid] - (mid + 1);
            if (missing < k)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return k + high + 1;
    }
};