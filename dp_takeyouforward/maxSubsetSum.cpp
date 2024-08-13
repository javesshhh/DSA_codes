// https://practice.geeksforgeeks.org/problems/e047b92794316450814b29de56cc9c6ec18371b7/1

// memoization

class Solution
{

public:
    long long solve(int i, int n, vector<int> &a, vector<int> &dp)
    {
        if (i >= n)
            return 0;
        if (dp[i] != -1)
            return dp[i];

        long long fp = a[i] + solve(i + 1, n, a, dp); // pick

        long long sp = 0;
        if (i + 1 < n)                              // not pick i
            sp = a[i + 1] + solve(i + 2, n, a, dp); // instead pick i+1

        return dp[i] = max(fp, sp);
    }

    long long findMaxSubsetSum(int N, vector<int> &A)
    {
        vector<int> DP(N + 1, -1);
        return solve(0, N, A, DP);
    }
};

// tabulation

class Solution
{

public:
    long long findMaxSubsetSum(int N, vector<int> &A)
    {
        vector<long long> dp(N + 2, 0);

        for (int i = N - 1; i >= 0; i--)
        {
            long long fp = A[i] + dp[i + 1];

            long long sp = 0;
            if (i + 1 < N)
                sp = A[i + 1] + dp[i + 2];

            dp[i] = max(fp, sp);
        }

        return dp[0];
    }
};

// space optimization

class Solution
{

public:
    long long findMaxSubsetSum(int N, vector<int> &A)
    {
        long long first = 0, second = 0, curr = 0;

        for (int i = N - 1; i >= 0; i--)
        {
            long long fp = A[i] + first;

            long long sp = 0;
            if (i + 1 < N)
                sp = A[i + 1] + second;

            curr = max(fp, sp);

            second = first;
            first = curr;
        }

        return curr;
    }
};