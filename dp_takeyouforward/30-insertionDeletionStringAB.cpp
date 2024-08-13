// https://www.youtube.com/watch?v=-fx6aDxcWyg&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=25&ab_channel=AdityaVerma
// https://leetcode.com/problems/delete-operation-for-two-strings/description/

class Solution
{
public:
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

    int minDistance(string word1, string word2)
    {
        int len = longestCommonSubsequence(word1, word2);
        int n = word1.length();
        int m = word2.length();
        return n - len + m - len;
    }
};