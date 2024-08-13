// https://www.youtube.com/watch?v=nVG7eTiD2bY&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&ab_channel=takeUforward
// https://leetcode.com/problems/distinct-subsequences/description/

// recursion

class Solution
{
public:
    int fn(string &s1, int n1, string &s2, int n2)
    {
        if (n2 == 0)
        {
            return 1;
        }
        if (n1 == 0)
        {
            return 0;
        }
        if (s1[n1 - 1] == s2[n2 - 1])
        {
            return fn(s1, n1 - 1, s2, n2 - 1) + fn(s1, n1 - 1, s2, n2);
        }
        else
        {
            return fn(s1, n1 - 1, s2, n2);
        }
    }

    int numDistinct(string s1, string s2)
    {
        int n1 = s1.length();
        int n2 = s2.length();
        // string s="";
        return fn(s1, n1, s2, n2);
    }
};

// memoization

class Solution
{
public:
    int fn(string &s1, int n1, string &s2, int n2, vector<vector<int>> &dp)
    {
        if (n2 == 0)
        {
            return 1;
        }
        if (n1 == 0)
        {
            return 0;
        }
        if (dp[n1][n2] != -1)
        {
            return dp[n1][n2];
        }
        if (s1[n1 - 1] == s2[n2 - 1])
        {
            return dp[n1][n2] = fn(s1, n1 - 1, s2, n2 - 1, dp) + fn(s1, n1 - 1, s2, n2, dp);
        }
        else
        {
            return dp[n1][n2] = fn(s1, n1 - 1, s2, n2, dp);
        }
    }

    int numDistinct(string s1, string s2)
    {
        int n1 = s1.length();
        int n2 = s2.length();
        // string s="";
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, -1));
        return fn(s1, n1, s2, n2, dp);
    }
};

// tabulation

class Solution
{
public:
    int fn(string &s1, int n1, string &s2, int n2, vector<vector<int>> &dp)
    {
        if (n2 == 0 || (n1 == 0 && n2 == 0))
        {
            return 1;
        }
        if (n1 == 0 && n2 != 0)
        {
            return 0;
        }
        if (dp[n1][n2] != -1)
        {
            return dp[n1][n2];
        }
        if (s1[n1 - 1] == s2[n2 - 1])
        {
            return dp[n1][n2] = fn(s1, n1 - 1, s2, n2 - 1, dp) + fn(s1, n1 - 1, s2, n2, dp);
        }
        else
        {
            return dp[n1][n2] = fn(s1, n1 - 1, s2, n2, dp);
        }
    }

    int numDistinct(string s1, string s2)
    {
        int n1 = s1.length();
        int n2 = s2.length();
        // string s="";
        vector<vector<double>> dp(n1 + 1, vector<double>(n2 + 1, 0));
        // return fn(s1,n1,s2,n2,dp);
        for (int i = 0; i <= n1; i++)
        {
            dp[i][0] = 1;
        }
        for (int i = 0; i <= n2; i++)
        {
            dp[0][i] = 0;
        }
        dp[0][0] = 1;
        for (int i = 1; i <= n1; i++)
        {
            for (int j = 1; j <= n2; j++)
            {
                if (s1[i - 1] == s2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[n1][n2];
    }
};

// space optimization

class Solution
{
public:
    int fn(string &s1, int n1, string &s2, int n2, vector<vector<int>> &dp)
    {
        if (n2 == 0 || (n1 == 0 && n2 == 0))
        {
            return 1;
        }
        if (n1 == 0 && n2 != 0)
        {
            return 0;
        }
        if (dp[n1][n2] != -1)
        {
            return dp[n1][n2];
        }
        if (s1[n1 - 1] == s2[n2 - 1])
        {
            return dp[n1][n2] = fn(s1, n1 - 1, s2, n2 - 1, dp) + fn(s1, n1 - 1, s2, n2, dp);
        }
        else
        {
            return dp[n1][n2] = fn(s1, n1 - 1, s2, n2, dp);
        }
    }

    int numDistinct(string s1, string s2)
    {
        int n1 = s1.length();
        int n2 = s2.length();
        // string s="";
        // vector<vector<double>>dp(n1+1,vector<double>(n2+1,0));
        vector<double> prev(n2 + 1, 0), curr(n2 + 1, 0);
        // return fn(s1,n1,s2,n2,dp);
        // for(int i=0;i<=n1;i++){
        //     dp[i][0]=1;
        // }
        // for(int i=0;i<=n2;i++){
        //     dp[0][i]=0;
        // }
        prev[0] = curr[0] = 1;
        for (int i = 1; i <= n1; i++)
        {
            for (int j = 1; j <= n2; j++)
            {
                if (s1[i - 1] == s2[j - 1])
                {
                    curr[j] = prev[j - 1] + prev[j];
                }
                else
                {
                    curr[j] = prev[j];
                }
            }
            prev = curr;
        }
        return prev[n2];
    }
};