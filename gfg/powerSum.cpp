// https://practice.geeksforgeeks.org/problems/express-as-sum-of-power-of-natural-numbers5647/1
// https://www.youtube.com/watch?v=S8sSXOs0x1U&ab_channel=CodeFreaks

// User function Template for C++
class Solution
{
public:
    int mod = 1e9 + 7;
    int fn(int n, int x, int i, int limit, vector<vector<int>> &dp)
    {
        if (n == 0)
        {
            return 1;
        }
        if (i > limit)
        {
            return 0;
        }
        if (n < 0)
        {
            return 0;
        }
        if (dp[n][i] != -1)
        {
            return dp[n][i];
        }
        int k = pow(i, x);
        int pick = fn(n - k, x, i + 1, limit, dp) % mod;
        int notpick = fn(n, x, i + 1, limit, dp) % mod;
        return dp[n][i] = (pick + notpick) % mod;
    }

    int numOfWays(int n, int x)
    {
        // code here
        int limit;
        for (int i = 1; i <= 1000; i++)
        {
            if (pow(i, x) > n)
            {
                break;
            }
            limit = i;
        }
        vector<vector<int>> dp(n + 1, vector<int>(limit + 1, -1));
        return fn(n, x, 1, limit, dp);
    }
};