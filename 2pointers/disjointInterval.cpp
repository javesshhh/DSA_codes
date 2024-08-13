// https://www.interviewbit.com/problems/disjoint-intervals/
// https://www.youtube.com/watch?v=va9hxY9zvlM

bool cmp(vector<int> &a, vector<int> &b)
{
    return a[1] < b[1];
}
// 2,3 1,4 4,6 8,9
int Solution::solve(vector<vector<int>> &A)
{
    sort(A.begin(), A.end(), cmp);
    int prev = A[0][1];
    int ans = 1;
    for (int i = 1; i < A.size(); i++)
    {
        if (A[i][0] > prev)
        {
            ans++;
            prev = A[i][1];
        }
    }

    return ans;
}
