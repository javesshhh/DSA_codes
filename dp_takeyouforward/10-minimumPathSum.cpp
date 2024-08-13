// https://www.youtube.com/watch?v=_rgTlyky1uQ&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=12&ab_channel=takeUforward
// https://takeuforward.org/data-structure/minimum-path-sum-in-a-grid-dp-10/
// https://leetcode.com/problems/minimum-path-sum/submissions/926570439/

// recursion

class Solution
{
public:
    int fn(vector<vector<int>> &grid, int m, int n)
    {
        if (m == 0 && n == 0)
        {
            return grid[0][0];
        }
        if (m < 0 || n < 0)
        {
            return INT_MAX - 200;
        }
        int left = INT_MAX;
        int up = INT_MAX;
        // if(n-1>=0)
        left = grid[m][n] + fn(grid, m, n - 1);
        // if(m-1>=0)
        up = grid[m][n] + fn(grid, m - 1, n);
        return min(left, up);
    }

    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        return fn(grid, m - 1, n - 1);
    }
};

// recursion

class Solution
{
public:
    int fn(vector<vector<int>> &grid, int m, int n)
    {
        if (m == 0 && n == 0)
        {
            return 0;
        }
        if (m < 0 || n < 0)
        {
            return INT_MAX - 200;
        }
        int left = INT_MAX;
        int up = INT_MAX;
        if (n - 1 >= 0)
            left = grid[m][n - 1] + fn(grid, m, n - 1);
        if (m - 1 >= 0)
            up = grid[m - 1][n] + fn(grid, m - 1, n);
        return min(left, up);
    }

    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        return fn(grid, m - 1, n - 1) + grid[m - 1][n - 1];
    }
};

// memoization

class Solution
{
public:
    int fn(vector<vector<int>> &grid, int m, int n, vector<vector<int>> &dp)
    {
        if (m == 0 && n == 0)
        {
            return 0;
        }
        if (m < 0 || n < 0)
        {
            return INT_MAX - 200;
        }
        if (dp[m][n] != -1)
        {
            return dp[m][n];
        }
        int left = INT_MAX;
        int up = INT_MAX;
        if (n - 1 >= 0)
            left = grid[m][n - 1] + fn(grid, m, n - 1, dp);
        if (m - 1 >= 0)
            up = grid[m - 1][n] + fn(grid, m - 1, n, dp);
        return dp[m][n] = min(left, up);
    }

    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return fn(grid, m - 1, n - 1, dp) + grid[m - 1][n - 1];
    }
};

// memoization

class Solution
{
public:
    int fn(vector<vector<int>> &grid, int m, int n, vector<vector<int>> &dp)
    {
        if (m == 0 && n == 0)
        {
            return grid[0][0];
        }
        if (m < 0 || n < 0)
        {
            return INT_MAX - 200;
        }
        if (dp[m][n] != -1)
        {
            return dp[m][n];
        }
        int left = INT_MAX;
        int up = INT_MAX;
        // if(n-1>=0)
        left = grid[m][n] + fn(grid, m, n - 1, dp);
        // if(m-1>=0)
        up = grid[m][n] + fn(grid, m - 1, n, dp);
        return dp[m][n] = min(left, up);
    }

    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return fn(grid, m - 1, n - 1, dp);
    }
};

// tabulation

class Solution
{
public:
    int fn(vector<vector<int>> &grid, int m, int n, vector<vector<int>> &dp)
    {
        // if(m==0 && n==0){
        //     return grid[0][0];
        // }
        // if(m<0 || n<0){
        //     return INT_MAX-200;
        // }
        // if(dp[m][n]!=-1){
        //     return dp[m][n];
        // }
        // int left=INT_MAX;
        // int up=INT_MAX;
        // // if(n-1>=0)
        // left=grid[m][n]+fn(grid,m,n-1,dp);
        // // if(m-1>=0)
        // up=grid[m][n]+fn(grid,m-1,n,dp);
        // return dp[m][n]=min(left,up);

        for (int i = 0; i <= m; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                int left = INT_MAX;
                int up = INT_MAX;
                if (i == 0 && j == 0)
                {
                    dp[0][0] = grid[0][0];
                    continue;
                }
                if (j - 1 >= 0)
                    left = grid[i][j] + dp[i][j - 1];
                if (i - 1 >= 0)
                    up = grid[i][j] + dp[i - 1][j];
                dp[i][j] = min(left, up);
            }
        }
        return dp[m][n];
    }

    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return fn(grid, m - 1, n - 1, dp);
    }
};