// https://www.youtube.com/watch?v=wuOOOATz_IA&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=26&ab_channel=AdityaVerma
// https://www.youtube.com/watch?v=6i_T5kkfv4A&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=30&ab_channel=takeUforward
// https://leetcode.com/problems/longest-palindromic-subsequence/description/

class Solution {
public:
    int longestPalindromeSubseq(string text1) {
    //     string text2=text1;
    //     reverse(text2.begin(),text2.end());
    //     int l1 = text1.length(), l2 = text2.length();
    // int dp[l1 + 1][l2 + 1];

    // for (int i = 0; i <= l1; i++)
    // {
    //     for (int j = 0; j <= l2; j++)
    //     {
    //         if (i == 0 || j == 0)
    //             dp[i][j] = 0;

    //         else if (text1[i - 1] == text2[j - 1])
    //             dp[i][j] = 1 + dp[i - 1][j - 1];

    //         else
    //             dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    //     }
    // }

    // // Now to print the sequence, we go through the array
    // int i = l1, j = l2;
    // string ans="";
    // while (i > 0 && j > 0)
    // {
    //     if (text1[i - 1] == text2[j - 1])
    //     {
    //         ans.push_back(text1[i - 1]);
    //         i--;
    //         j--;
    //     }

    //     else
    //     {
    //         if (dp[i - 1][j] <= dp[i][j - 1])
    //         {
    //             j--;
    //         }

    //         else
    //             i--;
    //     }
    // }
    // return ans;
        string text2=text1;
        reverse(text2.begin(),text2.end());
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