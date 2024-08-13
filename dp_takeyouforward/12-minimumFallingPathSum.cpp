// https://www.youtube.com/watch?v=N_aJ5qQbYA0&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=13&ab_channel=takeUforward
// https://takeuforward.org/data-structure/minimum-maximum-falling-path-sum-dp-12/
// https://leetcode.com/problems/minimum-falling-path-sum/description/

// recursion

class Solution
{
public:
    int fn(int i, int prev, vector<vector<int>> &triangle, int n)
    {
        if (i >= n)
        {
            return 0;
        }
        int sum = INT_MAX;
        for (int j = 0; j < n; j++)
        {
            if (j == prev || j == prev + 1 || j == prev - 1)
            {
                // prev=j;
                int k = triangle[i][prev] + fn(i + 1, j, triangle, n);
                sum = min(sum, k);
            }
        }
        return sum;
    }

    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int ans = INT_MAX;
        for (int z = 0; z < n; z++)
        {
            int casee = fn(0, z, matrix, n);
            ans = min(ans, casee);
        }
        return ans;
    }
};

// memoization

class Solution
{
public:
    int fn(int i, int prev, vector<vector<int>> &triangle, int n, vector<vector<int>> &dp)
    {
        if (i >= n)
        {
            return 0;
        }
        if (dp[i][prev] != -1)
        {
            return dp[i][prev];
        }
        int sum = INT_MAX;
        for (int j = 0; j < n; j++)
        {
            if (j == prev || j == prev + 1 || j == prev - 1)
            {
                // prev=j;
                int k = triangle[i][prev] + fn(i + 1, j, triangle, n, dp);
                sum = min(sum, k);
            }
        }
        return dp[i][prev] = sum;
    }

    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int ans = INT_MAX;
        vector<vector<int>> dp(n, vector<int>(n, -1));
        for (int z = 0; z < n; z++)
        {
            int casee = fn(0, z, matrix, n, dp);
            ans = min(ans, casee);
        }
        return ans;
    }
};

// tabulation

class Solution
{
public:
    int fn(int i, int prev, vector<vector<int>> &triangle, int n, vector<vector<int>> &dp)
    {
        if (i >= n)
        {
            return 0;
        }
        if (dp[i][prev] != -1)
        {
            return dp[i][prev];
        }
        int sum = INT_MAX;
        for (int j = 0; j < n; j++)
        {
            if (j == prev || j == prev + 1 || j == prev - 1)
            {
                // prev=j;
                int k = triangle[i][prev] + fn(i + 1, j, triangle, n, dp);
                sum = min(sum, k);
            }
        }
        return dp[i][prev] = sum;
    }

    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int ans = INT_MAX;
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int i = n - 1; i >= 0; i--)
        {
            for (int z = 0; z < n; z++)
            {
                int sum = INT_MAX;
                for (int j = 0; j < n; j++)
                {
                    if (j == z || j == z + 1 || j == z - 1)
                    {
                        // prev=j;
                        int k = matrix[i][z] + dp[i + 1][j];
                        sum = min(sum, k);
                    }
                }
                dp[i][z] = sum;
            }
        }

        for (int z = 0; z < n; z++)
        {
            int casee = dp[0][z];
            ans = min(ans, casee);
        }
        return ans;
    }
};