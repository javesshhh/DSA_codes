// https://www.youtube.com/watch?v=OgvOZ6OrJoY&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=24&ab_channel=takeUforward
// https://practice.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=knapsack-with-duplicate-items

// recursion

// User function Template for C++

class Solution
{
public:
    int fn(int i, int w, int val[], int wt[], int n)
    {
        if (i == n)
        {
            return 0;
        }
        if (wt[i] > w)
        {
            return fn(i + 1, w, val, wt, n);
        }
        else
        {
            return max(val[i] + fn(i, w - wt[i], val, wt, n), fn(i + 1, w, val, wt, n));
        }
    }

    int knapSack(int n, int w, int val[], int wt[])
    {
        // code here
        return fn(0, w, val, wt, n);
    }
};

// memoization

// User function Template for C++

class Solution
{
public:
    int fn(int i, int w, int val[], int wt[], int n, vector<vector<int>> &dp)
    {
        if (i == n)
        {
            return 0;
        }
        if (dp[i][w] != -1)
        {
            return dp[i][w];
        }
        if (wt[i] > w)
        {
            return dp[i][w] = fn(i + 1, w, val, wt, n, dp);
        }
        else
        {
            return dp[i][w] = max(val[i] + fn(i, w - wt[i], val, wt, n, dp), fn(i + 1, w, val, wt, n, dp));
        }
    }

    int knapSack(int n, int w, int val[], int wt[])
    {
        // code here
        vector<vector<int>> dp(n + 1, vector<int>(w + 1, -1));
        return fn(0, w, val, wt, n, dp);
    }
};

// tabulation

// User function Template for C++

class Solution
{
public:
    int fn(int i, int w, int val[], int wt[], int n, vector<vector<int>> &dp)
    {
        if (i == n)
        {
            return 0;
        }
        if (dp[i][w] != -1)
        {
            return dp[i][w];
        }
        if (wt[i] > w)
        {
            return dp[i][w] = fn(i + 1, w, val, wt, n, dp);
        }
        else
        {
            return dp[i][w] = max(val[i] + fn(i, w - wt[i], val, wt, n, dp), fn(i + 1, w, val, wt, n, dp));
        }
    }

    int knapSack(int n, int w, int val[], int wt[])
    {
        // code here
        vector<vector<int>> dp(n + 1, vector<int>(w + 1, 0));
        // return fn(0,w,val,wt,n,dp);
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = 0; j <= w; j++)
            {
                if (wt[i] > j)
                {
                    dp[i][j] = dp[i + 1][j];
                }
                else
                {
                    dp[i][j] = max(val[i] + dp[i][j - wt[i]], dp[i + 1][j]);
                }
            }
        }
        return dp[0][w];
    }
};

// space optimization

// User function Template for C++

class Solution
{
public:
    int fn(int i, int w, int val[], int wt[], int n, vector<vector<int>> &dp)
    {
        if (i == n)
        {
            return 0;
        }
        if (dp[i][w] != -1)
        {
            return dp[i][w];
        }
        if (wt[i] > w)
        {
            return dp[i][w] = fn(i + 1, w, val, wt, n, dp);
        }
        else
        {
            return dp[i][w] = max(val[i] + fn(i, w - wt[i], val, wt, n, dp), fn(i + 1, w, val, wt, n, dp));
        }
    }

    int knapSack(int n, int w, int val[], int wt[])
    {
        // code here
        // vector<vector<int>>dp(n+1,vector<int>(w+1,0));
        vector<int> prev(w + 1, 0), curr(w + 1, 0);
        // return fn(0,w,val,wt,n,dp);
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = 0; j <= w; j++)
            {
                if (wt[i] > j)
                {
                    curr[j] = prev[j];
                }
                else
                {
                    curr[j] = max(val[i] + curr[j - wt[i]], prev[j]);
                }
            }
            prev = curr;
        }
        return prev[w];
    }
};