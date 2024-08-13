// https://www.youtube.com/watch?v=Kmh3rhyEtB8&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=5&ab_channel=takeUforward
// https://takeuforward.org/data-structure/dynamic-programming-frog-jump-with-k-distances-dp-4/
// https://practice.geeksforgeeks.org/problems/minimal-cost/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=minimal-cost

// TLE recursion code

class Solution
{
public:
    int mini(vector<int> &height, int n, int k)
    {
        // Code here
        // vector<int>dp(n+1,-1);
        // dp[1]=0;
        if (n == 0)
        {
            return 0;
        }
        int ans = INT_MAX;
        for (int i = 1; i <= k; i++)
        {
            // int jump;
            if (n - i >= 0)
            {
                int jump = mini(height, n - i, k) + abs(height[n] - height[n - i]);
                ans = min(ans, jump);
            }
        }
        return ans;
    }

    int minimizeCost(vector<int> &height, int n, int k)
    {
        return mini(height, n - 1, k);
    }
};

// memoization code

class Solution
{
public:
    int mini(vector<int> &height, int n, int k, vector<int> &dp)
    {
        // Code here
        // vector<int>dp(n+1,-1);
        // dp[1]=0;
        if (n == 0)
        {
            return 0;
        }
        if (dp[n] != -1)
        {
            return dp[n];
        }
        int ans = INT_MAX;
        for (int i = 1; i <= k; i++)
        {
            // int jump;
            if (n - i >= 0)
            {
                int jump = mini(height, n - i, k, dp) + abs(height[n] - height[n - i]);
                ans = min(ans, jump);
            }
        }
        return dp[n] = ans;
    }

    int minimizeCost(vector<int> &height, int n, int k)
    {
        vector<int> dp(n, -1);
        // dp[0]=0;
        return mini(height, n - 1, k, dp);
    }
};

// tabulation code

class Solution
{
public:
    int mini(vector<int> &height, int n, int k, vector<int> &dp)
    {
        // Code here
        // vector<int>dp(n+1,-1);
        // dp[1]=0;
        // if(n==0){
        //     return 0;
        // }
        // if(dp[n]!=-1){
        //     return dp[n];
        // }

        for (int j = 1; j < n; j++)
        {
            int ans = INT_MAX;
            for (int i = 1; i <= k; i++)
            {
                // int jump;

                if (j - i >= 0)
                {
                    int jump = dp[j - i] + abs(height[j] - height[j - i]);
                    ans = min(ans, jump);
                }
            }
            dp[j] = ans;
        }
        return dp[n - 1];
    }

    int minimizeCost(vector<int> &height, int n, int k)
    {
        vector<int> dp(n, -1);
        dp[0] = 0;
        return mini(height, n, k, dp);
    }
};