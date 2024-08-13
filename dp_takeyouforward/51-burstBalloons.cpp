// https://www.youtube.com/watch?v=Yz4LlDSlkns&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=52&ab_channel=takeUforward
// https://leetcode.com/problems/burst-balloons/description/

// recursion

class Solution
{
public:
    int fn(int i, int j, vector<int> &nums)
    {
        if (i > j)
        {
            return 0;
        }
        int ans = INT_MIN;
        for (int k = i; k <= j; k++)
        {
            int points = nums[i - 1] * nums[k] * nums[j + 1] + fn(i, k - 1, nums) + fn(k + 1, j, nums);
            ans = max(ans, points);
        }
        return ans;
    }

    int maxCoins(vector<int> &nums)
    {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        return fn(1, n, nums);
    }
};

// memoization

class Solution
{
public:
    int fn(int i, int j, vector<int> &nums, vector<vector<int>> &dp)
    {
        if (i > j)
        {
            return 0;
        }
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        int ans = INT_MIN;
        for (int k = i; k <= j; k++)
        {
            int points = nums[i - 1] * nums[k] * nums[j + 1] + fn(i, k - 1, nums, dp) + fn(k + 1, j, nums, dp);
            ans = max(ans, points);
        }
        return dp[i][j] = ans;
    }

    int maxCoins(vector<int> &nums)
    {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, -1));
        return fn(1, n, nums, dp);
    }
};

// tabulation

class Solution
{
public:
    int fn(int i, int j, vector<int> &nums, vector<vector<int>> &dp)
    {
        if (i > j)
        {
            return 0;
        }
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        int ans = INT_MIN;
        for (int k = i; k <= j; k++)
        {
            int points = nums[i - 1] * nums[k] * nums[j + 1] + fn(i, k - 1, nums, dp) + fn(k + 1, j, nums, dp);
            ans = max(ans, points);
        }
        return dp[i][j] = ans;
    }

    int maxCoins(vector<int> &nums)
    {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
        // return fn(1,n,nums,dp);
        for (int i = n; i >= 1; i--)
        {
            for (int j = 1; j <= n; j++)
            {
                if (i > j)
                {
                    continue;
                }
                int ans = INT_MIN;
                for (int k = i; k <= j; k++)
                {
                    int points = nums[i - 1] * nums[k] * nums[j + 1] + dp[i][k - 1] + dp[k + 1][j];
                    ans = max(ans, points);
                }
                dp[i][j] = ans;
            }
        }
        return dp[1][n];
    }
};