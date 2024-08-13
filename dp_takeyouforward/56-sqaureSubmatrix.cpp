// https://leetcode.com/problems/count-square-submatrices-with-all-ones/description/
// https://www.youtube.com/watch?v=auS1fynpnjo&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=57&ab_channel=takeUforward

class Solution
{
public:
    int countSquares(vector<vector<int>> &v)
    {
        int n = v.size();
        int m = v[0].size();
        int dp[n][m];
        for (int i = 0; i < m; i++)
        {
            dp[0][i] = v[0][i];
        }
        for (int i = 0; i < n; i++)
        {
            dp[i][0] = v[i][0];
        }
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                if (v[i][j] == 0)
                    dp[i][j] = 0;
                else
                {
                    dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                ans += dp[i][j];
            }
        }
        return ans;
    }
};