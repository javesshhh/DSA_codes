// binary search lower bound method ---------------------> n log n

int lowerBound(vector<int> arr, int n, int x)
{
    int low = 0, high = n - 1;
    int ans = n;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        // maybe an answer
        if (arr[mid] >= x)
        {
            ans = mid;
            // look for smaller index on the left
            high = mid - 1;
        }
        else
        {
            low = mid + 1; // look on the right
        }
    }
    return ans;
}
int rowWithMax1s(vector<vector<int>> &matrix, int n, int m)
{
    int cnt_max = 0;
    int index = -1;

    // traverse the rows:
    for (int i = 0; i < n; i++)
    {
        // get the number of 1's:
        int cnt_ones = m - lowerBound(matrix[i], m, 1);
        if (cnt_ones > cnt_max)
        {
            cnt_max = cnt_ones;
            index = i;
        }
    }
    return index;
}

// advance bs

int rowWithMax1s(vector<vector<int>> arr, int n, int m)
{
    int cnt = 0, idx = -1;
    int j = m - 1, i = 0;
    while (j >= 0 && i < n)
    {
        if (arr[i][j])
        {
            while (arr[i][j])
            {
                j--;
                cnt++;
            }
            idx = i;
        } // else:
        i++;
    }
    return idx;
}