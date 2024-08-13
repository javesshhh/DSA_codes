// https://www.interviewbit.com/problems/array-3-pointers/

int Solution::minimize(const vector<int> &A, const vector<int> &B, const vector<int> &C)
{
    // O(N) solution
    // The main logic is VISUALIZATION IN A NUMBER LINE
    // Imagine the three numbers are x, y, z lying in the number line
    // The maximum af all the differences will be max(x,y,z) - min(x,y,z)
    // that is max(abs(A[i] - B[j]), abs(B[j] - C[k]), abs(C[k] - A[i])) = max(A[i],B[j],C[k]) - min(A[i],B[j],C[k])
    // like 0 -----x-----y-----z---- infinity  , the maximum difference is z(max value) - x(min value)
    // Now to minimise ( max(x,y,z) - min(x,y,z) ) there are two ways:
    // reduce max(x,y,z) or increase min(x,y,z)
    // But since we start at the starting indices, max cannot be further reduced
    // So in each step we increase the min(x,y,z)
    // Since the arrays are sorted , increasing the index causes the elements to increase in value.

    int ans = INT_MAX; // because we have to minimise the answer

    int i = 0, j = 0, k = 0;

    while (i < A.size() && j < B.size() && k < C.size())
    {
        int mini = min({A[i], B[j], C[k]});
        int diff = max({A[i], B[j], C[k]}) - mini;

        ans = min(ans, diff);

        if (mini == A[i])
            i++;
        else if (mini == B[j])
            j++;
        else
            k++;
    }

    return ans;
}
