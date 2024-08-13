// https://www.youtube.com/watch?v=b3GD8263-PQ&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=23&ab_channel=takeUforward
// https://leetcode.com/problems/target-sum/description/

// recursion

class Solution
{
public:
    int fn(int i, vector<int> &nums, int target)
    {
        int n = nums.size();
        if (i == n)
        {
            if (target == 0)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        int notpick = fn(i + 1, nums, target);
        int pick = 0;
        if (nums[i] <= target)
        {
            pick = fn(i + 1, nums, target - nums[i]);
        }
        return pick + notpick;
    }

    int findTargetSumWays(vector<int> &nums, int d)
    {
        int sum = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
        }
        int target = (sum - d) / 2;
        if (d > sum || (sum - d) % 2 == 1)
        {
            return 0;
        }
        else
        {
            return fn(0, nums, target);
        }
    }
};

// memoization

class Solution
{
public:
    int fn(int i, vector<int> &nums, int target, vector<vector<int>> &dp)
    {
        int n = nums.size();
        if (i == n)
        {
            if (target == 0)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        if (dp[i][target] != -1)
        {
            return dp[i][target];
        }
        int notpick = fn(i + 1, nums, target, dp);
        int pick = 0;
        if (nums[i] <= target)
        {
            pick = fn(i + 1, nums, target - nums[i], dp);
        }
        return dp[i][target] = pick + notpick;
    }

    int findTargetSumWays(vector<int> &nums, int d)
    {
        int sum = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
        }
        int target = (sum - d) / 2;
        if (d > sum || (sum - d) % 2 == 1)
        {
            return 0;
        }
        else
        {
            vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));
            return fn(0, nums, target, dp);
        }
    }
};

// tabulation

class Solution
{
public:
    int fn(int i, vector<int> &nums, int target, vector<vector<int>> &dp)
    {
        int n = nums.size();
        if (i == n)
        {
            if (target == 0)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        if (dp[i][target] != -1)
        {
            return dp[i][target];
        }
        int notpick = fn(i + 1, nums, target, dp);
        int pick = 0;
        if (nums[i] <= target)
        {
            pick = fn(i + 1, nums, target - nums[i], dp);
        }
        return dp[i][target] = pick + notpick;
    }

    int findTargetSumWays(vector<int> &nums, int d)
    {
        int sum = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
        }
        int target = (sum - d) / 2;
        if (sum - d < 0 || (sum - d) % 2 == 1)
        {
            return 0;
        }
        else
        {
            vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
            // return fn(0,nums,target,dp);
            dp[n][0] = 1;
            for (int i = n - 1; i >= 0; i--)
            {
                for (int j = 0; j <= target; j++)
                {
                    int notpick = dp[i + 1][j];
                    int pick = 0;
                    if (nums[i] <= j)
                    {
                        pick = dp[i + 1][j - nums[i]];
                    }
                    dp[i][j] = pick + notpick;
                }
            }
            return dp[0][target];
        }
    }
};

// space optimization

class Solution
{
public:
    int fn(int i, vector<int> &nums, int target, vector<vector<int>> &dp)
    {
        int n = nums.size();
        if (i == n)
        {
            if (target == 0)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        if (dp[i][target] != -1)
        {
            return dp[i][target];
        }
        int notpick = fn(i + 1, nums, target, dp);
        int pick = 0;
        if (nums[i] <= target)
        {
            pick = fn(i + 1, nums, target - nums[i], dp);
        }
        return dp[i][target] = pick + notpick;
    }

    int findTargetSumWays(vector<int> &nums, int d)
    {
        int sum = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
        }
        int target = (sum - d) / 2;
        if (sum - d < 0 || (sum - d) % 2 == 1)
        {
            return 0;
        }
        else
        {
            // vector<vector<int>>dp(n+1,vector<int>(target+1,0));
            vector<int> prev(target + 1, 0), curr(target + 1, 0);
            // return fn(0,nums,target,dp);
            prev[0] = 1;
            for (int i = n - 1; i >= 0; i--)
            {
                for (int j = 0; j <= target; j++)
                {
                    int notpick = prev[j];
                    int pick = 0;
                    if (nums[i] <= j)
                    {
                        pick = prev[j - nums[i]];
                    }
                    curr[j] = pick + notpick;
                }
                prev = curr;
            }
            return prev[target];
        }
    }
};