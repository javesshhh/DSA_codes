// https://www.youtube.com/watch?v=-uQGzhYj8BQ&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=38&ab_channel=takeUforward
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/description/

// recursion

class Solution
{
public:
    int fn(int i, bool buy, int k, vector<int> &prices)
    {
        if (k == 0)
        {
            return 0;
        }
        int n = prices.size();
        if (i == n - 1)
        {
            if (buy == true)
            {
                return 0;
            }
            else
            {
                return prices[i];
            }
        }
        if (buy == true)
        {
            return max(-prices[i] + fn(i + 1, false, k, prices), fn(i + 1, true, k, prices));
        }
        else
        {
            return max(prices[i] + fn(i + 1, true, k - 1, prices), fn(i + 1, false, k, prices));
        }
    }

    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        return fn(0, true, 2, prices);
    }
};

// memoization

class Solution
{
public:
    int fn(int i, bool buy, int k, vector<int> &prices, vector<vector<vector<int>>> &dp)
    {
        if (k == 0)
        {
            return 0;
        }
        int n = prices.size();
        if (i == n - 1)
        {
            if (buy == true)
            {
                return 0;
            }
            else
            {
                return prices[i];
            }
        }
        if (dp[i][buy][k] != -1)
        {
            return dp[i][buy][k];
        }
        if (buy == true)
        {
            return dp[i][buy][k] = max(-prices[i] + fn(i + 1, false, k, prices, dp), fn(i + 1, true, k, prices, dp));
        }
        else
        {
            return dp[i][buy][k] = max(prices[i] + fn(i + 1, true, k - 1, prices, dp), fn(i + 1, false, k, prices, dp));
        }
    }

    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        return fn(0, true, 2, prices, dp);
    }
};

// tabulation

class Solution
{
public:
    int fn(int i, bool buy, int k, vector<int> &prices, vector<vector<vector<int>>> &dp)
    {
        if (k == 0)
        {
            return 0;
        }
        int n = prices.size();
        if (i == n - 1)
        {
            if (buy == true)
            {
                return 0;
            }
            else
            {
                return prices[i];
            }
        }
        if (dp[i][buy][k] != -1)
        {
            return dp[i][buy][k];
        }
        if (buy == true)
        {
            return dp[i][buy][k] = max(-prices[i] + fn(i + 1, false, k, prices, dp), fn(i + 1, true, k, prices, dp));
        }
        else
        {
            return dp[i][buy][k] = max(prices[i] + fn(i + 1, true, k - 1, prices, dp), fn(i + 1, false, k, prices, dp));
        }
    }

    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, 0)));
        // return fn(0, true,2, prices,dp);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= 1; j++)
            {
                dp[i][j][0] = 0;
            }
        }
        dp[n - 1][true][2] = 0;
        dp[n - 1][true][1] = 0;
        dp[n - 1][false][2] = prices[n - 1];
        dp[n - 1][false][1] = prices[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                for (int k = 1; k <= 2; k++)
                {
                    if (buy == true)
                    {
                        dp[i][buy][k] = max(-prices[i] + dp[i + 1][false][k], dp[i + 1][true][k]);
                    }
                    else
                    {
                        dp[i][buy][k] = max(prices[i] + dp[i + 1][true][k - 1], dp[i + 1][false][k]);
                    }
                }
            }
        }
        return dp[0][true][2];
    }
};