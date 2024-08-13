// https://www.youtube.com/watch?v=NPZn9jBrX8U&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=27&ab_channel=takeUforward
// https://leetcode.com/problems/longest-common-subsequence/description/

// recursion

class Solution
{
public:
    int fn(int i1, int i2, string &s1, string &s2)
    {
        if (i1 < 0 || i2 < 0)
        {
            return 0;
        }
        if (s1[i1] == s2[i2])
        {
            return 1 + fn(i1 - 1, i2 - 1, s1, s2);
        }
        else
        {
            return max(fn(i1 - 1, i2, s1, s2), fn(i1, i2 - 1, s1, s2));
        }
    }

    int longestCommonSubsequence(string text1, string text2)
    {
        int n1 = text1.size();
        int n2 = text2.size();
        return fn(n1 - 1, n2 - 1, text1, text2);
    }
};

// recursion (by giving input as length of string to iterate instead of index to iterate)
// https://www.youtube.com/watch?v=4Urd0a0BNng&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=19&ab_channel=AdityaVerma

class Solution
{
public:
    int fn(int n1, int n2, string &s1, string &s2)
    {
        if (n1 == 0 || n2 == 0)
        {
            return 0;
        }
        if (s1[n1 - 1] == s2[n2 - 1])
        {
            return 1 + fn(n1 - 1, n2 - 1, s1, s2);
        }
        else
        {
            return max(fn(n1 - 1, n2, s1, s2), fn(n1, n2 - 1, s1, s2));
        }
    }

    int longestCommonSubsequence(string text1, string text2)
    {
        int n1 = text1.size();
        int n2 = text2.size();
        return fn(n1, n2, text1, text2);
    }
};

// memoization

class Solution
{
public:
    int fn(int i1, int i2, string &s1, string &s2, vector<vector<int>> &dp)
    {
        if (i1 < 0 || i2 < 0)
        {
            return 0;
        }
        if (dp[i1][i2] != -1)
        {
            return dp[i1][i2];
        }
        if (s1[i1] == s2[i2])
        {
            return dp[i1][i2] = 1 + fn(i1 - 1, i2 - 1, s1, s2, dp);
        }
        else
        {
            return dp[i1][i2] = max(fn(i1 - 1, i2, s1, s2, dp), fn(i1, i2 - 1, s1, s2, dp));
        }
    }

    int longestCommonSubsequence(string text1, string text2)
    {
        int n1 = text1.size();
        int n2 = text2.size();
        vector<vector<int>> dp(n1, vector<int>(n2, -1));
        return fn(n1 - 1, n2 - 1, text1, text2, dp);
    }
};

// memoization by shifting of index forward ny 1 so as to initialise base case in iterative solution

class Solution
{
public:
    int fn(int i1, int i2, string &s1, string &s2, vector<vector<int>> &dp)
    {
        if (i1 == 0 || i2 == 0)
        {
            return 0;
        }
        if (dp[i1][i2] != -1)
        {
            return dp[i1][i2];
        }
        if (s1[i1 - 1] == s2[i2 - 1])
        {
            return dp[i1][i2] = 1 + fn(i1 - 1, i2 - 1, s1, s2, dp);
        }
        else
        {
            return dp[i1][i2] = max(fn(i1 - 1, i2, s1, s2, dp), fn(i1, i2 - 1, s1, s2, dp));
        }
    }

    int longestCommonSubsequence(string text1, string text2)
    {
        int n1 = text1.size();
        int n2 = text2.size();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, -1));
        return fn(n1, n2, text1, text2, dp);
    }
};

// memoization by passing length instead of index
// https://youtu.be/g_hIx4yn9zg

class Solution
{
public:
    int fn(int n1, int n2, string &s1, string &s2, vector<vector<int>> &dp)
    {
        if (n1 == 0 || n2 == 0)
        {
            return 0;
        }
        if (dp[n1][n2] != -1)
        {
            return dp[n1][n2];
        }
        if (s1[n1 - 1] == s2[n2 - 1])
        {
            return dp[n1][n2] = 1 + fn(n1 - 1, n2 - 1, s1, s2, dp);
        }
        else
        {
            return dp[n1][n2] = max(fn(n1 - 1, n2, s1, s2, dp), fn(n1, n2 - 1, s1, s2, dp));
        }
    }

    int longestCommonSubsequence(string text1, string text2)
    {
        int n1 = text1.size();
        int n2 = text2.size();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, -1));
        return fn(n1, n2, text1, text2, dp);
    }
};

// tabulation (with reference to above index shifted code)

class Solution
{
public:
    int fn(int i1, int i2, string &s1, string &s2, vector<vector<int>> &dp)
    {
        if (i1 == 0 || i2 == 0)
        {
            return 0;
        }
        if (dp[i1][i2] != -1)
        {
            return dp[i1][i2];
        }
        if (s1[i1 - 1] == s2[i2 - 1])
        {
            return dp[i1][i2] = 1 + fn(i1 - 1, i2 - 1, s1, s2, dp);
        }
        else
        {
            return dp[i1][i2] = max(fn(i1 - 1, i2, s1, s2, dp), fn(i1, i2 - 1, s1, s2, dp));
        }
    }

    int longestCommonSubsequence(string s1, string s2)
    {
        int n1 = s1.size();
        int n2 = s2.size();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
        // return fn(n1,n2,text1,text2,dp);
        for (int i1 = 0; i1 <= n1; i1++)
        {
            dp[i1][0] = 0;
        }
        for (int i2 = 0; i2 <= n2; i2++)
        {
            dp[0][i2] = 0;
        }
        for (int i1 = 1; i1 <= n1; i1++)
        {
            for (int i2 = 1; i2 <= n2; i2++)
            {
                if (s1[i1 - 1] == s2[i2 - 1])
                {
                    dp[i1][i2] = 1 + dp[i1 - 1][i2 - 1];
                }
                else
                {
                    dp[i1][i2] = max(dp[i1 - 1][i2], dp[i1][i2 - 1]);
                }
            }
        }
        return dp[n1][n2];
    }
};

// tabulation when length is passed as input instead of index
// https://www.youtube.com/watch?v=hR3s9rGlMTU&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=21&ab_channel=AdityaVerma

class Solution
{
public:
    int fn(int n1, int n2, string &s1, string &s2, vector<vector<int>> &dp)
    {
        if (n1 == 0 || n2 == 0)
        {
            return 0;
        }
        if (dp[n1][n2] != -1)
        {
            return dp[n1][n2];
        }
        if (s1[n1 - 1] == s2[n2 - 1])
        {
            return dp[n1][n2] = 1 + fn(n1 - 1, n2 - 1, s1, s2, dp);
        }
        else
        {
            return dp[n1][n2] = max(fn(n1 - 1, n2, s1, s2, dp), fn(n1, n2 - 1, s1, s2, dp));
        }
    }

    int longestCommonSubsequence(string text1, string text2)
    {
        int n1 = text1.size();
        int n2 = text2.size();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
        // return fn(n1,n2,text1,text2,dp);
        for (int i = 0; i <= n1; i++)
        {
            dp[i][0] = 0;
        }
        for (int i = 0; i <= n2; i++)
        {
            dp[0][i] = 0;
        }
        for (int i = 1; i <= n1; i++)
        {
            for (int j = 1; j <= n2; j++)
            {
                if (text1[i - 1] == text2[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
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
    int fn(int i1, int i2, string &s1, string &s2, vector<vector<int>> &dp)
    {
        if (i1 == 0 || i2 == 0)
        {
            return 0;
        }
        if (dp[i1][i2] != -1)
        {
            return dp[i1][i2];
        }
        if (s1[i1 - 1] == s2[i2 - 1])
        {
            return dp[i1][i2] = 1 + fn(i1 - 1, i2 - 1, s1, s2, dp);
        }
        else
        {
            return dp[i1][i2] = max(fn(i1 - 1, i2, s1, s2, dp), fn(i1, i2 - 1, s1, s2, dp));
        }
    }

    int longestCommonSubsequence(string s1, string s2)
    {
        int n1 = s1.size();
        int n2 = s2.size();
        // vector<vector<int>>dp(n1+1,vector<int>(n2+1,0));
        vector<int> prev(n2 + 1, 0), curr(n2 + 1, 0);
        // return fn(n1,n2,text1,text2,dp);
        for (int i1 = 0; i1 <= n1; i1++)
        {
            prev[0] = 0;
        }
        for (int i2 = 0; i2 <= n2; i2++)
        {
            prev[i2] = 0;
        }
        for (int i1 = 1; i1 <= n1; i1++)
        {
            for (int i2 = 1; i2 <= n2; i2++)
            {
                if (s1[i1 - 1] == s2[i2 - 1])
                {
                    curr[i2] = 1 + prev[i2 - 1];
                }
                else
                {
                    curr[i2] = max(prev[i2], curr[i2 - 1]);
                }
            }
            prev = curr;
        }
        return prev[n2];
    }
};