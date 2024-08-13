// https://youtu.be/QGfn7JeXK54
// https://practice.geeksforgeeks.org/problems/chocolates-pickup/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=chocolates-pickup
// https://takeuforward.org/data-structure/3-d-dp-ninja-and-his-friends-dp-13/

// recursion TLE

class Solution
{
public:
    int fn(vector<vector<int>> &grid, int n, int m, int i, int j1, int j2)
    {
        if (i == n - 1)
        {
            if (j1 == j2)
            {
                return grid[i][j1];
            }
            else
            {
                return grid[i][j1] + grid[i][j2];
            }
        }
        if (j1 < 0 || j1 >= m || j2 < 0 || j2 >= m)
        {
            return INT_MIN + 200;
        }
        int ans = INT_MIN + 200;
        for (int d1 = -1; d1 <= 1; d1++)
        {
            for (int d2 = -1; d2 <= 1; d2++)
            {
                int k;
                if (j1 == j2)
                {
                    k = grid[i][j1] + fn(grid, n, m, i + 1, j1 + d1, j2 + d2);
                }
                else
                {
                    k = grid[i][j1] + grid[i][j2] + fn(grid, n, m, i + 1, j1 + d1, j2 + d2);
                }
                ans = max(ans, k);
            }
        }
        return ans;
    }

    int solve(int n, int m, vector<vector<int>> &grid)
    {
        // code here
        return fn(grid, n, m, 0, 0, m - 1);
    }
};

// memoization

int fn(vector<vector<int>> &grid, int n, int m, int i, int j1, int j2, vector<vector<vector<int>>> &dp)
{
    if (j1 < 0 || j1 >= m || j2 < 0 || j2 >= m)
    {
        return INT_MIN + 2000;
    }

    if (i == n - 1)
    {
        if (j1 == j2)
        {
            return grid[i][j1];
        }
        else
        {
            return grid[i][j1] + grid[i][j2];
        }
    }

    if (dp[i][j1][j2] != -1)
    {
        return dp[i][j1][j2];
    }
    int ans = INT_MIN + 2000;

    for (int d1 = -1; d1 <= 1; d1++)
    {
        for (int d2 = -1; d2 <= 1; d2++)
        {
            int k = INT_MIN + 2000;
            if (j1 == j2)
            {
                k = grid[i][j1] + fn(grid, n, m, i + 1, j1 + d1, j2 + d2, dp);
            }
            else
            {
                k = grid[i][j1] + grid[i][j2] + fn(grid, n, m, i + 1, j1 + d1, j2 + d2, dp);
            }
            ans = max(ans, k);
        }
    }
    return dp[i][j1][j2] = ans;
}

int solve(int n, int m, vector<vector<int>> &grid)
{
    // code here
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
    return fn(grid, n, m, 0, 0, m - 1, dp);
}