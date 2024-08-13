// https://www.youtube.com/watch?v=GqOmJHQZivw&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=20&ab_channel=takeUforward
// https://www.geeksforgeeks.org/0-1-knapsack-problem-dp-10/
// https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=0-1-knapsack-problem0945

// recursion

class Solution
{
public:
    // Function to return max value that can be put in knapsack of capacity W.

    int fn(int i, int w, int wt[], int val[], int n)
    {
        if (i == n)
        {
            return 0;
        }

        if (wt[i] <= w)
        {
            return max(val[i] + fn(i + 1, w - wt[i], wt, val, n), fn(i + 1, w, wt, val, n));
        }
        else
        {
            return fn(i + 1, w, wt, val, n);
        }
    }

    int knapSack(int W, int wt[], int val[], int n)
    {
        return fn(0, W, wt, val, n);
    }
};

// memoization

class Solution
{
public:
    // Function to return max value that can be put in knapsack of capacity W.

    int fn(int i, int w, int wt[], int val[], int n, vector<vector<int>> &dp)
    {
        if (i == n)
        {
            return 0;
        }
        if (dp[i][w] != -1)
        {
            return dp[i][w];
        }
        if (wt[i] <= w)
        {
            return dp[i][w] = max(val[i] + fn(i + 1, w - wt[i], wt, val, n, dp), fn(i + 1, w, wt, val, n, dp));
        }
        else
        {
            return dp[i][w] = fn(i + 1, w, wt, val, n, dp);
        }
    }

    int knapSack(int W, int wt[], int val[], int n)
    {
        vector<vector<int>> dp(n + 1, vector<int>(W + 1, -1));
        return fn(0, W, wt, val, n, dp);
    }
};

// tabulation

class Solution
{
public:
    // Function to return max value that can be put in knapsack of capacity W.

    int fn(int i, int w, int wt[], int val[], int n, vector<vector<int>> &dp)
    {
        if (i == n)
        {
            return 0;
        }
        if (dp[i][w] != -1)
        {
            return dp[i][w];
        }
        if (wt[i] <= w)
        {
            return dp[i][w] = max(val[i] + fn(i + 1, w - wt[i], wt, val, n, dp), fn(i + 1, w, wt, val, n, dp));
        }
        else
        {
            return dp[i][w] = fn(i + 1, w, wt, val, n, dp);
        }
    }

    int knapSack(int W, int wt[], int val[], int n)
    {
        vector<vector<int>> dp(n + 1, vector<int>(W + 1, -1));
        //   return fn(0,W,wt,val,n,dp);
        for (int i = 0; i <= W; i++)
        {
            dp[n][i] = 0;
        }
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = 0; j <= W; j++)
            {
                if (wt[i] <= j)
                {
                    dp[i][j] = max(val[i] + dp[i + 1][j - wt[i]], dp[i + 1][j]);
                }
                else
                {
                    dp[i][j] = dp[i + 1][j];
                }
            }
        }
        return dp[0][W];
    }
};

// space optimization

class Solution
{
public:
    // Function to return max value that can be put in knapsack of capacity W.

    int fn(int i, int w, int wt[], int val[], int n, vector<vector<int>> &dp)
    {
        if (i == n)
        {
            return 0;
        }
        if (dp[i][w] != -1)
        {
            return dp[i][w];
        }
        if (wt[i] <= w)
        {
            return dp[i][w] = max(val[i] + fn(i + 1, w - wt[i], wt, val, n, dp), fn(i + 1, w, wt, val, n, dp));
        }
        else
        {
            return dp[i][w] = fn(i + 1, w, wt, val, n, dp);
        }
    }

    int knapSack(int W, int wt[], int val[], int n)
    {
        // vector<vector<int>>dp(n+1,vector<int>(W+1,-1));
        vector<int> prev(W + 1, 0), curr(W + 1, 0);
        //   return fn(0,W,wt,val,n,dp);
        for (int i = 0; i <= W; i++)
        {
            prev[i] = 0;
        }
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = 0; j <= W; j++)
            {
                if (wt[i] <= j)
                {
                    curr[j] = max(val[i] + prev[j - wt[i]], prev[j]);
                }
                else
                {
                    curr[j] = prev[j];
                }
            }
            prev = curr;
        }
        return prev[W];
    }
};