// https://www.interviewbit.com/problems/highest-product/

int Solution::maxp3(vector<int> &A)
{
    sort(A.begin(), A.end());
    int n = A.size();
    int val = A[n - 1] * A[n - 2] * A[n - 3];
    int ans = A[0] * A[1] * A[n - 1];
    return max(ans, val);
}

//

int Solution::maxp3(vector<int> &A)
{
    int x = INT_MIN, y = INT_MIN, z = INT_MIN;
    for (int i = 0; i < A.size(); i++)
    {
        if (A[i] > x)
        {
            z = y;
            y = x;
            x = A[i];
        }
        else if (A[i] > y)
        {
            z = y;
            y = A[i];
        }
        else if (A[i] > z)
        {
            z = A[i];
        }
    }
    // cout<<x<<" "<<y<<" "<<z;
    int a = INT_MAX;
    int b = INT_MAX;
    for (int i = 0; i < A.size(); i++)
    {
        if (A[i] < a)
        {
            b = a;
            a = A[i];
        }
        else if (A[i] < b)
        {
            b = A[i];
        }
    }
    return max(x * y * z, a * b * x);
}