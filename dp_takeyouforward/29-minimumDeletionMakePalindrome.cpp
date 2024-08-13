// https://www.youtube.com/watch?v=CFwCCNbRuLY&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=27&ab_channel=AdityaVerma
// https://practice.geeksforgeeks.org/problems/minimum-number-of-deletions4610/1?utm_source=geeksforgeeks&utm_medium=article_practice_tab&utm_campaign=article_practice_tab

int minDeletions(string text1, int n)
{
    // complete the function here
    string text2 = text1;
    reverse(text2.begin(), text2.end());
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
    int len = dp[n1][n2];
    return n - len;
}