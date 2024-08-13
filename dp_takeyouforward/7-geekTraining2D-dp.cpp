// https://youtu.be/N_aJ5qQbYA0
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

int maximumPoints(vector<vector<int>> &points, int n)
{
    // Code here
    // vector<int>vis(3,0);
    vector<vector<int>> dp(n, vector<int>(4, -1));
    // int last=3;
    // return fn(n-1,points,n,last,dp);
    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][0], points[0][1]);
    dp[0][3] = max({points[0][1], points[0][2], points[0][0]});
    for (int i = 1; i < n; i++)
    {
        for (int last = 0; last <= 3; last++)
        {
            int sum = -1e6;
            for (int j = 0; j < 3; j++)
            {
                if (j != last)
                {
                    int k = dp[i - 1][j] + points[i][j];
                    sum = max(k, sum);
                }
            }
            dp[i][last] = sum;
        }
    }
    return dp[n - 1][3];
}


// another approach

for i in range(1,n):
            points[i][0]+=max(points[i-1][1],points[i-1][2])
            points[i][1]+=max(points[i-1][0],points[i-1][2])
            points[i][2]+=max(points[i-1][0],points[i-1][1])
        return max(points[n-1][0],points[n-1][1],points[n-1][2])