// https://www.youtube.com/watch?v=HgyouUi11zk&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=23&ab_channel=takeUforward
// https://leetcode.com/problems/coin-change-ii/description/

// recursion

class Solution
{
public:
    int fn(int i, vector<int> &coins, int amt)
    {
        int n = coins.size();
        if (i == n)
        {
            if (amt == 0)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        int notpick = fn(i + 1, coins, amt);
        int pick = 0;
        if (coins[i] <= amt)
        {
            pick = fn(i, coins, amt - coins[i]);
        }
        return pick + notpick;
    }

    int change(int amt, vector<int> &coins)
    {
        return fn(0, coins, amt);
    }
};

// memoization

class Solution
{
public:
    int fn(int i, vector<int> &coins, int amt, vector<vector<int>> &dp)
    {
        int n = coins.size();
        if (i == n)
        {
            if (amt == 0)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        if (dp[i][amt] != -1)
        {
            return dp[i][amt];
        }
        int notpick = fn(i + 1, coins, amt, dp);
        int pick = 0;
        if (coins[i] <= amt)
        {
            pick = fn(i, coins, amt - coins[i], dp);
        }
        return dp[i][amt] = pick + notpick;
    }

    int change(int amt, vector<int> &coins)
    {
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(amt + 1, -1));
        return fn(0, coins, amt, dp);
    }
};

// tabulation

class Solution
{
public:
    int fn(int i, vector<int> &coins, int amt, vector<vector<int>> &dp)
    {
        int n = coins.size();
        if (i == n)
        {
            if (amt == 0)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        if (dp[i][amt] != -1)
        {
            return dp[i][amt];
        }
        int notpick = fn(i + 1, coins, amt, dp);
        int pick = 0;
        if (coins[i] <= amt)
        {
            pick = fn(i, coins, amt - coins[i], dp);
        }
        return dp[i][amt] = pick + notpick;
    }

    int change(int amt, vector<int> &coins)
    {
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(amt + 1, 0));
        // return fn(0,coins,amt,dp);
        dp[n][0] = 1;
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = 0; j <= amt; j++)
            {
                int notpick = dp[i + 1][j];
                int pick = 0;
                if (coins[i] <= j)
                {
                    pick = dp[i][j - coins[i]];
                }
                dp[i][j] = pick + notpick;
            }
        }
        return dp[0][amt];
    }
};

// space optimization

class Solution
{
public:
    int fn(int i, vector<int> &coins, int amt, vector<vector<int>> &dp)
    {
        int n = coins.size();
        if (i == n)
        {
            if (amt == 0)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        if (dp[i][amt] != -1)
        {
            return dp[i][amt];
        }
        int notpick = fn(i + 1, coins, amt, dp);
        int pick = 0;
        if (coins[i] <= amt)
        {
            pick = fn(i, coins, amt - coins[i], dp);
        }
        return dp[i][amt] = pick + notpick;
    }

    int change(int amt, vector<int> &coins)
    {
        int n = coins.size();
        // vector<vector<int>>dp(n+1,vector<int>(amt+1,0));
        vector<int> prev(amt + 1, 0), curr(amt + 1, 0);
        // return fn(0,coins,amt,dp);
        prev[0] = 1;
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = 0; j <= amt; j++)
            {
                int notpick = prev[j];
                int pick = 0;
                if (coins[i] <= j)
                {
                    pick = curr[j - coins[i]];
                }
                curr[j] = pick + notpick;
            }
            prev = curr;
        }
        return prev[amt];
    }
};
