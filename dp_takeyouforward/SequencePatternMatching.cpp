// https://www.youtube.com/watch?v=QVntmksK2es&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=30&ab_channel=AdityaVerma
// https://leetcode.com/problems/is-subsequence/description/

// recursion

class Solution
{
public:
    bool fn(int n1, int n2, string &s, string &t)
    {
        if (n1 == 0)
        {
            return true;
        }
        if (n2 == 0 && n1 != 0)
        {
            return false;
        }
        if (s[n1 - 1] == t[n2 - 1])
        {
            return fn(n1 - 1, n2 - 1, s, t);
        }
        else
        {
            return fn(n1, n2 - 1, s, t);
        }
    }

    bool isSubsequence(string s, string t)
    {
        int n1 = s.length();
        int n2 = t.length();
        return fn(n1, n2, s, t);
    }
};

// memoization

class Solution
{
public:
    bool fn(int n1, int n2, string &s, string &t, vector<vector<int>> &dp)
    {
        if (n1 == 0)
        {
            return true;
        }
        if (n2 == 0 && n1 != 0)
        {
            return false;
        }
        if (dp[n1][n2] != -1)
        {
            return dp[n1][n2];
        }
        if (s[n1 - 1] == t[n2 - 1])
        {
            return dp[n1][n2] = fn(n1 - 1, n2 - 1, s, t, dp);
        }
        else
        {
            return dp[n1][n2] = fn(n1, n2 - 1, s, t, dp);
        }
    }

    bool isSubsequence(string s, string t)
    {
        int n1 = s.length();
        int n2 = t.length();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, -1));
        return fn(n1, n2, s, t, dp);
    }
};

// tabulation

class Solution
{
public:
    bool fn(int n1, int n2, string &s, string &t, vector<vector<int>> &dp)
    {
        if (n1 == 0)
        {
            return true;
        }
        if (n2 == 0 && n1 != 0)
        {
            return false;
        }
        if (dp[n1][n2] != -1)
        {
            return dp[n1][n2];
        }
        if (s[n1 - 1] == t[n2 - 1])
        {
            return dp[n1][n2] = fn(n1 - 1, n2 - 1, s, t, dp);
        }
        else
        {
            return dp[n1][n2] = fn(n1, n2 - 1, s, t, dp);
        }
    }

    bool isSubsequence(string s, string t)
    {
        int n1 = s.length();
        int n2 = t.length();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
        // return fn(n1,n2,s,t,dp);
        for (int i = 0; i <= n2; i++)
        {
            dp[0][i] = true;
        }
        for (int i = 1; i <= n1; i++)
        {
            dp[i][0] = false;
        }
        for (int i = 1; i <= n1; i++)
        {
            for (int j = 1; j <= n2; j++)
            {
                if (s[i - 1] == t[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = dp[i][j - 1];
                }
            }
        }
        return dp[n1][n2];
    }
};