// https://www.youtube.com/watch?v=IV1dHbk5CDc&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=39&ab_channel=takeUforward
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/description/

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

    int maxProfit(int k, vector<int> &prices)
    {
        int n = prices.size();
        return fn(0, true, k, prices);
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

    int maxProfit(int k, vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k + 1, -1)));
        return fn(0, true, k, prices, dp);
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

    int maxProfit(int k, vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k + 1, 0)));
        // return fn(0, true,k, prices,dp);

        for (int i = 0; i <= k; i++)
        {
            dp[n - 1][true][i] = 0;
        }
        for (int i = 0; i <= k; i++)
        {
            dp[n - 1][false][i] = prices[n - 1];
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= 1; j++)
            {
                dp[i][j][0] = 0;
            }
        }
        for (int i = n - 2; i >= 0; i--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                for (int j = 1; j <= k; j++)
                {
                    if (buy == true)
                    {
                        dp[i][buy][j] = max(-prices[i] + dp[i + 1][false][j], dp[i + 1][true][j]);
                    }
                    else
                    {
                        dp[i][buy][j] = max(prices[i] + dp[i + 1][true][j - 1], dp[i + 1][false][j]);
                    }
                }
            }
        }
        return dp[0][true][k];
    }
};