// https://www.youtube.com/watch?v=HrybPYpOvz0&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=22&ab_channel=AdityaVerma
// https://practice.geeksforgeeks.org/problems/longest-common-substring1452/1?utm_source=geeksforgeeks&utm_medium=article_practice_tab&utm_campaign=article_practice_tab
// similar to longest common subsequence

class Solution
{
public:
    int longestCommonSubstr(string &text1, string &text2, int n1, int n2)
    {
        // your code here
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
                    dp[i][j] = 0;
                }
            }
        }
        // dp matrix is giving longest common substring in string s1 and s2 upto length i for s1 and j for s2
        int ans = 0;
        for (int i = 0; i <= n1; i++)
        {
            for (int j = 0; j <= n2; j++)
            {
                ans = max(ans, dp[i][j]);
            }
        }
        return ans;
    }
};