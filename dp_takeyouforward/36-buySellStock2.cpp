// https://www.youtube.com/watch?v=nGJmxkUJQGs&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=37&ab_channel=takeUforward
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/

// recursion

class Solution
{
public:
    int fn(int i, bool buy, vector<int> &prices)
    {
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
            return max(-prices[i] + fn(i + 1, false, prices), fn(i + 1, true, prices));
        }
        else
        {
            return max(prices[i] + fn(i + 1, true, prices), fn(i + 1, false, prices));
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
            return dp[i][buy] = max(prices[i] + fn(i + 1, true, prices, dp), fn(i + 1, false, prices, dp));
        }
    }

    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
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
            return dp[i][buy] = max(prices[i] + fn(i + 1, true, prices, dp), fn(i + 1, false, prices, dp));
        }
    }

    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, 0));
        // return fn(0,true,prices,dp);
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
                    dp[i][buy] = max(prices[i] + dp[i + 1][true], dp[i + 1][false]);
                }
            }
        }
        return dp[0][true];
    }
};

// space optimization

class Solution
{
public:
    int fn(int i, bool buy, vector<int> &prices, vector<vector<int>> &dp)
    {
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
            return dp[i][buy] = max(prices[i] + fn(i + 1, true, prices, dp), fn(i + 1, false, prices, dp));
        }
    }

    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        // vector<vector<int>>dp(n,vector<int>(2,0));
        vector<int> curr(2, 0), prev(2, 0);
        // return fn(0,true,prices,dp);
        prev[true] = 0;
        prev[false] = prices[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                if (buy == true)
                {
                    curr[buy] = max(-prices[i] + prev[false], prev[true]);
                }
                else
                {
                    curr[buy] = max(prices[i] + prev[true], prev[false]);
                }
            }
            prev = curr;
        }
        return prev[true];
    }
};