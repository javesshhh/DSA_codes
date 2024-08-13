// https://www.interviewbit.com/problems/subarray-with-given-xor/
// https://www.youtube.com/watch?v=eZr-6p0B7ME&ab_channel=takeUforward

int Solution::solve(vector<int> &arr, int k)
{
    int n = arr.size();
    int xr = 0;
    int cnt = 0;
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        xr = xr ^ arr[i];
        if (xr == k)
            cnt++;
        if (m.find(xr ^ k) != m.end())
        {
            cnt += m[xr ^ k];
        }
        m[xr]++;
    }
    return cnt;
}
