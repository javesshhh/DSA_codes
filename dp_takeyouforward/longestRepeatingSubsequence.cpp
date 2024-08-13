// https://www.youtube.com/watch?v=hbTaCmQGqLg&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=29&ab_channel=AdityaVerma
// https://www.geeksforgeeks.org/longest-repeating-subsequence/
// https://practice.geeksforgeeks.org/problems/longest-repeating-subsequence2004/1?utm_source=geeksforgeeks&utm_medium=article_practice_tab&utm_campaign=article_practice_tab
// just lcs with condition that i!=j

// recursion

class Solution
{
public:
    int fn(int i, int j, string &a, string &b)
    {
        if (i == 0 || j == 0)
        {
            return 0;
        }
        if (a[i - 1] == b[j - 1] && i != j)
        {
            return 1 + fn(i - 1, j - 1, a, b);
        }
        else
        {
            return max(fn(i - 1, j, a, b), fn(i, j - 1, a, b));
        }
    }

    int LongestRepeatingSubsequence(string str)
    {
        // Code here
        string a = str;
        string b = str;
        int n = str.length();
        return fn(n, n, a, b);
    }
};

// memoization

class Solution
{
public:
    int fn(int i, int j, string &a, string &b, vector<vector<int>> &dp)
    {
        if (i == 0 || j == 0)
        {
            return 0;
        }
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        if (a[i - 1] == b[j - 1] && i != j)
        {
            return dp[i][j] = 1 + fn(i - 1, j - 1, a, b, dp);
        }
        else
        {
            return dp[i][j] = max(fn(i - 1, j, a, b, dp), fn(i, j - 1, a, b, dp));
        }
    }

    int LongestRepeatingSubsequence(string str)
    {
        // Code here
        string a = str;
        string b = str;
        int n = str.length();

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return fn(n, n, a, b, dp);
    }
};

// tabulation

class Solution
{
public:
    int fn(int i, int j, string &a, string &b, vector<vector<int>> &dp)
    {
        if (i == 0 || j == 0)
        {
            return 0;
        }
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        if (a[i - 1] == b[j - 1] && i != j)
        {
            return dp[i][j] = 1 + fn(i - 1, j - 1, a, b, dp);
        }
        else
        {
            return dp[i][j] = max(fn(i - 1, j, a, b, dp), fn(i, j - 1, a, b, dp));
        }
    }

    int LongestRepeatingSubsequence(string str)
    {
        // Code here
        string a = str;
        string b = str;
        int n = str.length();

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        //  return fn(n,n,a,b,dp);
        for (int i = 0; i <= n; i++)
        {
            dp[0][i] = 0;
        }
        for (int i = 0; i <= n; i++)
        {
            dp[i][0] = 0;
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (a[i - 1] == b[j - 1] && i != j)
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[n][n];
    }
};