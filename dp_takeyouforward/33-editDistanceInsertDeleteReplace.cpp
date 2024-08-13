// https://www.youtube.com/watch?v=fJaKO8FbDdo&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=34&ab_channel=takeUforward
// https://leetcode.com/problems/edit-distance/description/

// recursion

class Solution
{
public:
    int fn(int n1, int n2, string &s1, string &s2)
    {
        if ((n1 == 0 && n2 == 0))
        {
            return 0;
        }
        if (n1 == 0 && n2 != 0)
        {
            return n2;
        }
        if (n2 == 0 && n1 != 0)
        {
            return n1;
        }
        if (s1[n1 - 1] == s2[n2 - 1])
        {
            return fn(n1 - 1, n2 - 1, s1, s2);
        }
        else
        {
            return min(min(1 + fn(n1 - 1, n2 - 1, s1, s2), 1 + fn(n1, n2 - 1, s1, s2)), 1 + fn(n1 - 1, n2, s1, s2));
        }
    }

    int minDistance(string word1, string word2)
    {
        int n1 = word1.size();
        int n2 = word2.size();
        return fn(n1, n2, word1, word2);
    }
};

// memoization

class Solution
{
public:
    int fn(int n1, int n2, string &s1, string &s2, vector<vector<int>> &dp)
    {
        if ((n1 == 0 && n2 == 0))
        {
            return 0;
        }
        if (n1 == 0 && n2 != 0)
        {
            return n2;
        }
        if (n2 == 0 && n1 != 0)
        {
            return n1;
        }
        if (dp[n1][n2] != -1)
        {
            return dp[n1][n2];
        }
        if (s1[n1 - 1] == s2[n2 - 1])
        {
            return dp[n1][n2] = fn(n1 - 1, n2 - 1, s1, s2, dp);
        }
        else
        {
            return dp[n1][n2] = min(min(1 + fn(n1 - 1, n2 - 1, s1, s2, dp), 1 + fn(n1, n2 - 1, s1, s2, dp)), 1 + fn(n1 - 1, n2, s1, s2, dp));
        }
    }

    int minDistance(string word1, string word2)
    {
        int n1 = word1.size();
        int n2 = word2.size();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, -1));
        return fn(n1, n2, word1, word2, dp);
    }
};

// tabulation

class Solution
{
public:
    int fn(int n1, int n2, string &s1, string &s2, vector<vector<int>> &dp)
    {
        if ((n1 == 0 && n2 == 0))
        {
            return 0;
        }
        if (n1 == 0 && n2 != 0)
        {
            return n2;
        }
        if (n2 == 0 && n1 != 0)
        {
            return n1;
        }
        if (dp[n1][n2] != -1)
        {
            return dp[n1][n2];
        }
        if (s1[n1 - 1] == s2[n2 - 1])
        {
            return dp[n1][n2] = fn(n1 - 1, n2 - 1, s1, s2, dp);
        }
        else
        {
            return dp[n1][n2] = min(min(1 + fn(n1 - 1, n2 - 1, s1, s2, dp), 1 + fn(n1, n2 - 1, s1, s2, dp)), 1 + fn(n1 - 1, n2, s1, s2, dp));
        }
    }

    int minDistance(string word1, string word2)
    {
        int n1 = word1.size();
        int n2 = word2.size();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
        // return fn(n1,n2,word1,word2,dp);
        for (int i = 0; i <= n1; i++)
        {
            dp[i][0] = i;
        }
        for (int i = 0; i <= n2; i++)
        {
            dp[0][i] = i;
        }
        dp[0][0] = 0;
        for (int i = 1; i <= n1; i++)
        {
            for (int j = 1; j <= n2; j++)
            {

                if (word1[i - 1] == word2[j - 1] && i - 1 >= 0 && j - 1 >= 0)
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else
                {
                    // if( i-1>=0 && j-1>=0)
                    dp[i][j] = min(min(1 + dp[i - 1][j - 1], 1 + dp[i][j - 1]), 1 + dp[i - 1][j]);
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
    int fn(int n1, int n2, string &s1, string &s2, vector<vector<int>> &dp)
    {
        if ((n1 == 0 && n2 == 0))
        {
            return 0;
        }
        if (n1 == 0 && n2 != 0)
        {
            return n2;
        }
        if (n2 == 0 && n1 != 0)
        {
            return n1;
        }
        if (dp[n1][n2] != -1)
        {
            return dp[n1][n2];
        }
        if (s1[n1 - 1] == s2[n2 - 1])
        {
            return dp[n1][n2] = fn(n1 - 1, n2 - 1, s1, s2, dp);
        }
        else
        {
            return dp[n1][n2] = min(min(1 + fn(n1 - 1, n2 - 1, s1, s2, dp), 1 + fn(n1, n2 - 1, s1, s2, dp)), 1 + fn(n1 - 1, n2, s1, s2, dp));
        }
    }

    int minDistance(string word1, string word2)
    {
        int n1 = word1.size();
        int n2 = word2.size();
        // vector<vector<int>>dp(n1+1,vector<int>(n2+1,0));
        vector<int> prev(n2 + 1, 0), curr(n2 + 1, 0);
        // return fn(n1,n2,word1,word2,dp);
        // for(int i=0;i<=n1;i++){
        //     dp[i][0]=i;
        // }
        // for(int i=0;i<=n2;i++){
        //     dp[0][i]=i;
        // }
        // prev[0]=0;
        if (n1 != 0 && n2 == 0)
        {
            return n1;
        }
        else if (n1 == 0 && n2 != 0)
        {
            return n2;
        }
        else
        {
            for (int i = 0; i <= n2; i++)
            {
                prev[i] = i;
            }
            for (int i = 1; i <= n1; i++)
            {
                for (int j = 1; j <= n2; j++)
                {
                    curr[0] = i;
                    if (word1[i - 1] == word2[j - 1])
                    {
                        curr[j] = prev[j - 1];
                    }
                    else
                    {
                        // if( i-1>=0 && j-1>=0)
                        curr[j] = min(min(1 + prev[j - 1], 1 + curr[j - 1]), 1 + prev[j]);
                    }
                }
                prev = curr;
            }
            return prev[n2];
        }
    }
};