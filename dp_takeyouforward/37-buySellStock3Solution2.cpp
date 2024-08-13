// https://www.youtube.com/watch?v=-uQGzhYj8BQ&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=38&ab_channel=takeUforward
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/description/
// based on logic given at the end of the video

// recursion

class Solution
{
public:
    int fn(int i, int k, vector<int> &prices)
    {
        if (k == 0)
        {
            return 0;
        }
        int n = prices.size();
        if (i == n - 1)
        {
            if (k % 2 == 0)
            {
                return 0;
            }
            else
            {
                return prices[i];
            }
        }
        if (k % 2 == 0)
        {
            return max(-prices[i] + fn(i + 1, k - 1, prices), fn(i + 1, k, prices));
        }
        else
        {
            return max(prices[i] + fn(i + 1, k - 1, prices), fn(i + 1, k, prices));
        }
    }

    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        return fn(0, 4, prices);
    }
};

// memoization

class Solution
{
public:
    int fn(int i, int k, vector<int> &prices, vector<vector<int>> &dp)
    {
        if (k == 0)
        {
            return 0;
        }
        int n = prices.size();
        if (i == n - 1)
        {
            if (k % 2 == 0)
            {
                return 0;
            }
            else
            {
                return prices[i];
            }
        }
        if (dp[i][k] != -1)
        {
            return dp[i][k];
        }
        if (k % 2 == 0)
        {
            return dp[i][k] = max(-prices[i] + fn(i + 1, k - 1, prices, dp), fn(i + 1, k, prices, dp));
        }
        else
        {
            return dp[i][k] = max(prices[i] + fn(i + 1, k - 1, prices, dp), fn(i + 1, k, prices, dp));
        }
    }

    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(5, -1));
        return fn(0, 4, prices, dp);
    }
};

// tabulation

class Solution
{
public:
    int fn(int i, int k, vector<int> &prices, vector<vector<int>> &dp)
    {
        if (k == 0)
        {
            return 0;
        }
        int n = prices.size();
        if (i == n - 1)
        {
            if (k % 2 == 0)
            {
                return 0;
            }
            else
            {
                return prices[i];
            }
        }
        if (dp[i][k] != -1)
        {
            return dp[i][k];
        }
        if (k % 2 == 0)
        {
            return dp[i][k] = max(-prices[i] + fn(i + 1, k - 1, prices, dp), fn(i + 1, k, prices, dp));
        }
        else
        {
            return dp[i][k] = max(prices[i] + fn(i + 1, k - 1, prices, dp), fn(i + 1, k, prices, dp));
        }
    }

    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(5, 0));
        // return fn(0, 4, prices,dp);
        for (int i = 0; i < n; i++)
        {
            dp[i][0] = 0;
        }
        dp[n - 1][4] = 0;
        dp[n - 1][2] = 0;
        dp[n - 1][3] = prices[n - 1];
        dp[n - 1][1] = prices[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            for (int k = 1; k <= 4; k++)
            {
                if (k % 2 == 0)
                {
                    dp[i][k] = max(-prices[i] + dp[i + 1][k - 1], dp[i + 1][k]);
                }
                else
                {
                    dp[i][k] = max(prices[i] + dp[i + 1][k - 1], dp[i + 1][k]);
                }
            }
        }
        return dp[0][4];
    }
};