// https://www.youtube.com/watch?v=myPeWb3Y68A&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=21&ab_channel=takeUforward
// https://leetcode.com/problems/coin-change/description/

// recursion

class Solution
{
public:
    int fn(int i, vector<int> &coins, int amt)
    {
        int n = coins.size();
        if (i == n - 1)
        {
            if (amt == 0)
            {
                return 0;
            }
            else
            {
                if (amt < coins[i])
                {
                    return 1e8;
                }
                else if (amt == coins[i])
                {
                    return 1;
                }
                else
                {
                    if (amt % coins[i] == 0)
                    {
                        return amt / coins[i];
                    }
                    else
                    {
                        return 1e8;
                    }
                }
            }
        }
        int notpick = 0 + fn(i + 1, coins, amt);
        int pick = 1e8;
        if (coins[i] <= amt)
        {
            pick = 1 + fn(i, coins, amt - coins[i]);
        }
        return min(pick, notpick);
    }

    int coinChange(vector<int> &coins, int amt)
    {
        int ans = fn(0, coins, amt);
        if (ans >= 1e8)
        {
            return -1;
        }
        else
        {
            return ans;
        }
    }
};

// memoization

class Solution
{
public:
    int fn(int i, vector<int> &coins, int amt, vector<vector<int>> &dp)
    {
        int n = coins.size();
        if (i == n - 1)
        {
            if (amt == 0)
            {
                return 0;
            }
            else
            {
                if (amt < coins[i])
                {
                    return 1e8;
                }
                else if (amt == coins[i])
                {
                    return 1;
                }
                else
                {
                    if (amt % coins[i] == 0)
                    {
                        return amt / coins[i];
                    }
                    else
                    {
                        return 1e8;
                    }
                }
            }
        }
        if (dp[i][amt] != -1)
        {
            return dp[i][amt];
        }
        int notpick = 0 + fn(i + 1, coins, amt, dp);
        int pick = 1e8;
        if (coins[i] <= amt)
        {
            pick = 1 + fn(i, coins, amt - coins[i], dp);
        }
        return dp[i][amt] = min(pick, notpick);
    }

    int coinChange(vector<int> &coins, int amt)
    {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amt + 1, -1));
        int ans = fn(0, coins, amt, dp);
        if (ans >= 1e8)
        {
            return -1;
        }
        else
        {
            return ans;
        }
    }
};

// tabulation

class Solution
{
public:
    int fn(int i, vector<int> &coins, int amt, vector<vector<int>> &dp)
    {
        int n = coins.size();
        if (i == n - 1)
        {
            if (amt == 0)
            {
                return 0;
            }
            else
            {
                if (amt % coins[i] == 0)
                {
                    return amt / coins[i];
                }
                else
                {
                    return 1e8;
                }
            }
        }
        if (dp[i][amt] != -1)
        {
            return dp[i][amt];
        }
        int notpick = 0 + fn(i + 1, coins, amt, dp);
        int pick = 1e8;
        if (coins[i] <= amt)
        {
            pick = 1 + fn(i, coins, amt - coins[i], dp);
        }
        return dp[i][amt] = min(pick, notpick);
    }

    int coinChange(vector<int> &coins, int amt)
    {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amt + 1, 0));
        // int ans= fn(0,coins,amt,dp);
        if (amt == 0)
        {
            dp[n - 1][0] = 0;
        }
        else
        {
            for (int i = 1; i <= amt; i++)
            {
                if (i % coins[n - 1] == 0)
                {
                    dp[n - 1][i] = i / coins[n - 1];
                }
                else
                {
                    dp[n - 1][i] = 1e9;
                }
            }
        }
        for (int i = n - 2; i >= 0; i--)
        {
            for (int j = 0; j <= amt; j++)
            {
                int notpick = 0 + dp[i + 1][j];
                int pick = 1e9;
                if (coins[i] <= j)
                {
                    pick = 1 + dp[i][j - coins[i]];
                }
                dp[i][j] = min(pick, notpick);
            }
        }
        int ans = dp[0][amt];
        if (ans >= 1e9)
        {
            return -1;
        }
        else
        {
            return ans;
        }
    }
};

// space optimization

class Solution
{
public:
    int fn(int i, vector<int> &coins, int amt, vector<vector<int>> &dp)
    {
        int n = coins.size();
        if (i == n - 1)
        {
            if (amt == 0)
            {
                return 0;
            }
            else
            {
                if (amt % coins[i] == 0)
                {
                    return amt / coins[i];
                }
                else
                {
                    return 1e8;
                }
            }
        }
        if (dp[i][amt] != -1)
        {
            return dp[i][amt];
        }
        int notpick = 0 + fn(i + 1, coins, amt, dp);
        int pick = 1e8;
        if (coins[i] <= amt)
        {
            pick = 1 + fn(i, coins, amt - coins[i], dp);
        }
        return dp[i][amt] = min(pick, notpick);
    }

    int coinChange(vector<int> &coins, int amt)
    {
        int n = coins.size();
        // vector<vector<int>>dp(n,vector<int>(amt+1,0));
        vector<int> prev(amt + 1, 0), curr(amt + 1, 0);
        // int ans= fn(0,coins,amt,dp);
        if (amt == 0)
        {
            prev[0] = 0;
        }
        else
        {
            for (int i = 1; i <= amt; i++)
            {
                if (i % coins[n - 1] == 0)
                {
                    prev[i] = i / coins[n - 1];
                }
                else
                {
                    prev[i] = 1e9;
                }
            }
        }
        for (int i = n - 2; i >= 0; i--)
        {
            for (int j = 0; j <= amt; j++)
            {
                int notpick = 0 + prev[j];
                int pick = 1e9;
                if (coins[i] <= j)
                {
                    pick = 1 + curr[j - coins[i]];
                }
                curr[j] = min(pick, notpick);
            }
            prev = curr;
        }
        int ans = prev[amt];
        if (ans >= 1e9)
        {
            return -1;
        }
        else
        {
            return ans;
        }
    }
};