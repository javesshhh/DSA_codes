// https://www.youtube.com/watch?v=xwomavsC86c&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=51&ab_channel=takeUforward
// https://leetcode.com/problems/minimum-cost-to-cut-a-stick/description/

// recursion

class Solution
{
public:
    int f(int i, int j, vector<int> &cuts)
    {

        // base case
        if (i > j)
            return 0;

        int mini = INT_MAX;

        for (int ind = i; ind <= j; ind++)
        {

            int ans = cuts[j + 1] - cuts[i - 1] +
                      f(i, ind - 1, cuts) +
                      f(ind + 1, j, cuts);

            mini = min(mini, ans);
        }

        return mini;
    }

    int minCost(int n, vector<int> &cuts)
    {
        // cuts.push_back(0);
        int c = cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        sort(cuts.begin(), cuts.end());

        return f(1, c, cuts);
    }
};

// memoization

class Solution
{
public:
    int f(int i, int j, vector<int> &cuts, vector<vector<int>> &dp)
    {

        // base case
        if (i > j)
            return 0;
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        int mini = INT_MAX;

        for (int ind = i; ind <= j; ind++)
        {

            int ans = cuts[j + 1] - cuts[i - 1] +
                      f(i, ind - 1, cuts, dp) +
                      f(ind + 1, j, cuts, dp);

            mini = min(mini, ans);
        }

        return dp[i][j] = mini;
    }

    int minCost(int n, vector<int> &cuts)
    {
        // cuts.push_back(0);
        int c = cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        sort(cuts.begin(), cuts.end());
        vector<vector<int>> dp(c + 1, vector<int>(c + 1, -1));
        return f(1, c, cuts, dp);
    }
};

// tabulation

class Solution
{
public:
    int f(int i, int j, vector<int> &cuts, vector<vector<int>> &dp)
    {

        // base case
        if (i > j)
            return 0;
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        int mini = INT_MAX;

        for (int ind = i; ind <= j; ind++)
        {

            int ans = cuts[j + 1] - cuts[i - 1] +
                      f(i, ind - 1, cuts, dp) +
                      f(ind + 1, j, cuts, dp);

            mini = min(mini, ans);
        }

        return dp[i][j] = mini;
    }

    int minCost(int n, vector<int> &cuts)
    {
        // cuts.push_back(0);
        int c = cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        sort(cuts.begin(), cuts.end());
        vector<vector<int>> dp(c + 2, vector<int>(c + 2, 0));
        // return f(1,c,cuts,dp);
        for (int i = c; i >= 1; i--)
        {
            for (int j = 1; j <= c; j++)
            {
                if (i > j)
                {
                    continue;
                }
                int mini = INT_MAX;
                for (int ind = i; ind <= j; ind++)
                {
                    int ans = cuts[j + 1] - cuts[i - 1] +
                              dp[i][ind - 1] +
                              dp[ind + 1][j];
                    mini = min(mini, ans);
                }
                dp[i][j] = mini;
            }
        }
        return dp[1][c];
    }
};