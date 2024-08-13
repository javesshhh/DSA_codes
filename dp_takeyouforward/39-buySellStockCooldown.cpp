// https://www.youtube.com/watch?v=IGIe46xw3YY&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=40&ab_channel=takeUforward
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/

// recursion

class Solution
{
public:
    int fn(int i, bool buy, vector<int> &prices)
    {
        int n = prices.size();
        if (i >= n)
        {
            return 0;
        }
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
            return max(-prices[i] + fn(i + 1, false, prices), fn(i + 1, true, prices));
        }
        else
        {
            return max(prices[i] + fn(i + 2, true, prices), fn(i + 1, false, prices));
        }
    }

    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        return fn(0, true, prices);
    }
};

// memoization

class Solution
{
public:
    int fn(int i, bool buy, vector<int> &prices, vector<vector<int>> &dp)
    {
        int n = prices.size();
        if (i >= n)
        {
            return 0;
        }
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
        if (dp[i][buy] != -1)
        {
            return dp[i][buy];
        }
        if (buy == true)
        {
            return dp[i][buy] = max(-prices[i] + fn(i + 1, false, prices, dp), fn(i + 1, true, prices, dp));
        }
        else
        {
            return dp[i][buy] = max(prices[i] + fn(i + 2, true, prices, dp), fn(i + 1, false, prices, dp));
        }
    }

    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, -1));
        return fn(0, true, prices, dp);
    }
};

// tabulation

class Solution
{
public:
    int fn(int i, bool buy, vector<int> &prices, vector<vector<int>> &dp)
    {
        int n = prices.size();
        if (i >= n)
        {
            return 0;
        }
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
        if (dp[i][buy] != -1)
        {
            return dp[i][buy];
        }
        if (buy == true)
        {
            return dp[i][buy] = max(-prices[i] + fn(i + 1, false, prices, dp), fn(i + 1, true, prices, dp));
        }
        else
        {
            return dp[i][buy] = max(prices[i] + fn(i + 2, true, prices, dp), fn(i + 1, false, prices, dp));
        }
    }

    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        // return fn(0, true, prices,dp);
        for (int i = 0; i <= 1; i++)
        {
            dp[n][i] = 0;
        }
        dp[n - 1][true] = 0;
        dp[n - 1][false] = prices[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                if (buy == true)
                {
                    dp[i][buy] = max(-prices[i] + dp[i + 1][false], dp[i + 1][true]);
                }
                else
                {
                    dp[i][buy] = max(prices[i] + dp[i + 2][true], dp[i + 1][false]);
                }
            }
        }
        return dp[0][true];
    }
};