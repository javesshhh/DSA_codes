// https://www.youtube.com/watch?v=k4eK-vEmnKg&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=41&ab_channel=takeUforward
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/description/

// recursion

class Solution
{
public:
    int fn(int i, bool buy, vector<int> &prices, int fee)
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
                return prices[i] - fee;
            }
        }
        if (buy == true)
        {
            return max(-prices[i] + fn(i + 1, false, prices, fee), fn(i + 1, true, prices, fee));
        }
        else
        {
            return max(prices[i] - fee + fn(i + 1, true, prices, fee), fn(i + 1, false, prices, fee));
        }
    }

    int maxProfit(vector<int> &prices, int fee)
    {
        int n = prices.size();
        return fn(0, true, prices, fee);
    }
};

// memoization

class Solution
{
public:
    int fn(int i, bool buy, vector<int> &prices, int fee, vector<vector<int>> &dp)
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
                return prices[i] - fee;
            }
        }
        if (dp[i][buy] != -1)
        {
            return dp[i][buy];
        }
        if (buy == true)
        {
            return dp[i][buy] = max(-prices[i] + fn(i + 1, false, prices, fee, dp), fn(i + 1, true, prices, fee, dp));
        }
        else
        {
            return dp[i][buy] = max(prices[i] - fee + fn(i + 1, true, prices, fee, dp), fn(i + 1, false, prices, fee, dp));
        }
    }

    int maxProfit(vector<int> &prices, int fee)
    {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return fn(0, true, prices, fee, dp);
    }
};

// tabulation

class Solution
{
public:
    int fn(int i, bool buy, vector<int> &prices, int fee, vector<vector<int>> &dp)
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
                return prices[i] - fee;
            }
        }
        if (dp[i][buy] != -1)
        {
            return dp[i][buy];
        }
        if (buy == true)
        {
            return dp[i][buy] = max(-prices[i] + fn(i + 1, false, prices, fee, dp), fn(i + 1, true, prices, fee, dp));
        }
        else
        {
            return dp[i][buy] = max(prices[i] - fee + fn(i + 1, true, prices, fee, dp), fn(i + 1, false, prices, fee, dp));
        }
    }

    int maxProfit(vector<int> &prices, int fee)
    {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, 0));
        // return fn(0,true,prices,dp);
        dp[n - 1][true] = 0;
        dp[n - 1][false] = prices[n - 1] - fee;
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
                    dp[i][buy] = max(prices[i] - fee + dp[i + 1][true], dp[i + 1][false]);
                }
            }
        }
        return dp[0][true];
    }
};