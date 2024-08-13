// https://www.youtube.com/watch?v=xElxAuBcvsU&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=32&ab_channel=takeUforward
// https://www.youtube.com/watch?v=823Grn4_dCQ&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=24&t=60s&ab_channel=AdityaVerma
// https://leetcode.com/problems/shortest-common-supersequence/description/

// to calculate length of shortest common supersequence
// https://practice.geeksforgeeks.org/problems/shortest-common-supersequence0322/1?utm_source=geeksforgeeks&utm_medium=article_practice_tab&utm_campaign=article_practice_tab

class Solution
{
public:
    // Function to find length of shortest common supersequence of two strings.

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

    int shortestCommonSupersequence(string X, string Y, int m, int n)
    {
        // code here
        int len = longestCommonSubsequence(X, Y);
        // int n=str1.length();
        // int m=str2.length();
        return n + m - len;
    }
};

// recursion + memoization to print shortest common supersequence

string solve(string ans, int i, int j, int n, int m, string s1, string s2, vector<vector<string>> &dp)
{
    if (dp[i][j] != "-1")
        return dp[i][j];

    if (i == n)
    {
        if (j != m)
        {
            for (int k = j; k < m; k++)
            {
                ans += s2[k];
            }
        }
        return ans;
    }

    if (j == m)
    {
        if (i != n)
        {
            for (int k = i; k < n; k++)
            {
                ans += s1[k];
            }
        }
        return ans;
    }

    // dp ka function //

    if (s1[i] == s2[j])
    {
        ans = s1[i] + solve(ans, i + 1, j + 1, n, m, s1, s2, dp);
        return dp[i][j] = ans;
    }
    else
    {
        string ans1 = s1[i] + solve(ans, i + 1, j, n, m, s1, s2, dp);
        string ans2 = s2[j] + solve(ans, i, j + 1, n, m, s1, s2, dp);
        if (ans1.size() < ans2.size())
        {
            return dp[i][j] = ans1;
        }
        else
            return dp[i][j] = ans2;
    }
}
string shortestCommonSupersequence(string str1, string str2)
{

    int n = str1.size();
    int m = str2.size();
    int i = 0;
    int j = 0;
    string ans = "";
    vector<vector<string>> dp(n + 1, vector<string>(m + 1, "-1"));
    return solve(ans, i, j, n, m, str1, str2, dp);
}

// tabulation (according to video of  striver)

class Solution
{
public:

    string shortestCommonSupersequence(string str1, string str2)
    {
        int m = str1.size();
        int n = str2.size();
        int dp[m + 1][n + 1];

        for (int i = 0; i <= m; i++)
            for (int j = 0; j <= n; j++)
                if (i == 0 || j == 0)
                    dp[i][j] = 0;

        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (str1[i - 1] == str2[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                }
            }
        }

        int i = m, j = n;
        string s;
        while (i > 0 && j > 0)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                s.push_back(str1[i - 1]);
                i--;
                j--;
            }
            else
            {
                if (dp[i][j - 1] > dp[i - 1][j])
                {
                    s.push_back(str2[j - 1]);
                    j--;
                }
                else
                {
                    s.push_back(str1[i - 1]);
                    i--;
                }
            }
        }

        while (i > 0)
        {
            s.push_back(str1[i - 1]);
            i--;
        }

        while (j > 0)
        {
            s.push_back(str2[j - 1]);
            j--;
        }

        reverse(s.begin(), s.end());
        return s;
    }
};