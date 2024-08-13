// https://youtu.be/SrP-PiLSYC0
// https://leetcode.com/problems/triangle/description/
// https://takeuforward.org/data-structure/minimum-path-sum-in-triangular-grid-dp-11/

// recursion

class Solution
{
public:
    int fn(int i, int prev, vector<vector<int>> &triangle)
    {
        if (i >= triangle.size())
        {
            return 0;
        }
        int sum = INT_MAX;
        for (int j = 0; j <= i + 1; j++)
        {
            if (j == prev || j == prev + 1)
            {
                // prev=j;
                int k = triangle[i][prev] + fn(i + 1, j, triangle);
                sum = min(sum, k);
            }
        }
        return sum;
    }

    int minimumTotal(vector<vector<int>> &triangle)
    {
        int prev = 0;
        return fn(0, prev, triangle);
    }
};

// memoization

class Solution
{
public:
    int fn(int i, int prev, vector<vector<int>> &triangle, vector<vector<int>> &dp)
    {
        if (i >= triangle.size())
        {
            return 0;
        }
        if (dp[i][prev] != -1)
        {
            return dp[i][prev];
        }
        int sum = INT_MAX;
        for (int j = 0; j <= i + 1; j++)
        {
            if (j == prev || j == prev + 1)
            {
                // prev=j;
                int k = triangle[i][prev] + fn(i + 1, j, triangle, dp);
                sum = min(sum, k);
            }
        }
        return dp[i][prev] = sum;
    }

    int minimumTotal(vector<vector<int>> &triangle)
    {
        int prev = 0;
        // vector<vector<int>>dp=triangle;
        // for(int i=0;i<triangle.size();i++){
        //     for(int j=0;j<triangle[0].size();j++){
        //         dp[i][j]=-1;
        //     }
        // }
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return fn(0, prev, triangle, dp);
    }
};

// tabulation

int fn(int i, int prev, vector<vector<int>> &triangle, vector<vector<int>> &dp)
{
    if (i >= triangle.size())
    {
        return 0;
    }
    if (dp[i][prev] != -1)
    {
        return dp[i][prev];
    }
    int sum = INT_MAX;
    for (int j = 0; j <= i + 1; j++)
    {
        if (j == prev || j == prev + 1)
        {
            // prev=j;
            int k = triangle[i][prev] + fn(i + 1, j, triangle, dp);
            sum = min(sum, k);
        }
    }
    return dp[i][prev] = sum;
}

int minimumTotal(vector<vector<int>> &triangle)
{
    // int prev=0;
    // vector<vector<int>>dp=triangle;
    // for(int i=0;i<triangle.size();i++){
    //     for(int j=0;j<triangle[0].size();j++){
    //         dp[i][j]=-1;
    //     }
    // }
    int n = triangle.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    // return fn(0,prev,triangle,dp);

    for (int i = n - 1; i >= 0; i--)
    {
        for (int k = 0; k < i + 1; k++)
        {

            int sum = INT_MAX;
            for (int j = 0; j <= i + 1; j++)
            {
                if (j == k || j == k + 1)
                {
                    // prev=j;
                    int k1 = triangle[i][k] + dp[i + 1][j];
                    sum = min(sum, k1);
                }
            }
            dp[i][k] = sum;
        }
    }
    return dp[0][0];
}