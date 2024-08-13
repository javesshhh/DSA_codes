// https://www.youtube.com/watch?v=TmhpgXScLyY&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=10&ab_channel=takeUforward
// https://leetcode.com/problems/unique-paths-ii/submissions/926183343/

// recursion

class Solution
{
public:
    int paths(vector<vector<int>> &grid, int m, int n)
    {
        if (m == 0 && n == 0 && grid[m][n] == 0)
        {
            return 1;
        }
        if (m < 0 || n < 0)
        {
            return 0;
        }
        if (grid[m][n] == 1)
        {
            return 0;
        }
        int up = paths(grid, m - 1, n);
        int left = paths(grid, m, n - 1);
        return up + left;
    }

    int uniquePathsWithObstacles(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        return paths(grid, m - 1, n - 1);
    }
};

// memoization

class Solution
{
public:
    int paths(vector<vector<int>> &grid, int m, int n, vector<vector<int>> &dp)
    {
        if (m == 0 && n == 0 && grid[m][n] == 0)
        {
            return dp[m][n] = 1;
        }
        if (m < 0 || n < 0)
        {
            return 0;
        }
        if (grid[m][n] == 1)
        {
            return 0;
        }
        if (dp[m][n] != -1)
        {
            return dp[m][n];
        }
        int up = paths(grid, m - 1, n, dp);
        int left = paths(grid, m, n - 1, dp);
        return dp[m][n] = up + left;
    }

    int uniquePathsWithObstacles(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return paths(grid, m - 1, n - 1, dp);
    }
};

// tabulation

class Solution
{
public:
    int paths(vector<vector<int>> &grid, int m, int n, vector<vector<int>> &dp)
    {
        // dp[0][0]=1;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0 && j == 0 && grid[i][j] == 0)
                {
                    dp[0][0] = 1;
                    continue;
                }
                int up = 0;
                int left = 0;
                if (i - 1 >= 0 && grid[i][j] == 0)
                    up = dp[i - 1][j];
                if (j - 1 >= 0 && grid[i][j] == 0)
                    left = dp[i][j - 1];
                dp[i][j] = up + left;
            }
        }
        return dp[m - 1][n - 1];
    }

    int uniquePathsWithObstacles(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return paths(grid, m, n, dp);
    }
};