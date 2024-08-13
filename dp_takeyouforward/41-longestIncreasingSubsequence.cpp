// memoization https://www.youtube.com/watch?v=ekcwMsSIzVc&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=42&ab_channel=takeUforward
// https://leetcode.com/problems/longest-increasing-subsequence/description/
// tabulation https://www.youtube.com/watch?v=IFfYfonAFGc&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=44&ab_channel=takeUforward

// recursion

class Solution
{
public:
    int fn(int i, int prev, vector<int> &nums)
    {
        int n = nums.size();
        // if(i==n-1){
        //     if(prev==-1){
        //         return 1;
        //     }

        // }
        if (i == n)
        {
            return 0;
        }
        if (prev == -1)
        {
            return max(1 + fn(i + 1, i, nums), fn(i + 1, prev, nums));
        }
        if (nums[i] > nums[prev])
        {
            return max(1 + fn(i + 1, i, nums), fn(i + 1, prev, nums));
        }
        else
        {
            return fn(i + 1, prev, nums);
        }
    }

    int lengthOfLIS(vector<int> &nums)
    {
        return fn(0, -1, nums);
    }
};

// memoization

class Solution
{
public:
    int fn(int i, int prev, vector<int> &nums, vector<vector<int>> &dp)
    {
        int n = nums.size();
        // if(i==n-1){
        //     if(prev==-1){
        //         return 1;
        //     }

        // }
        if (i == n)
        {
            return 0;
        }
        if (dp[i][prev + 1] != -1)
        {
            return dp[i][prev + 1];
        }
        if (prev == -1)
        {
            return dp[i][prev + 1] = max(1 + fn(i + 1, i, nums, dp), fn(i + 1, prev, nums, dp));
        }
        if (nums[i] > nums[prev])
        {
            return dp[i][prev + 1] = max(1 + fn(i + 1, i, nums, dp), fn(i + 1, prev, nums, dp));
        }
        else
        {
            return dp[i][prev + 1] = fn(i + 1, prev, nums, dp);
        }
    }

    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return fn(0, -1, nums, dp);
    }
};

// tabulation https://www.youtube.com/watch?v=IFfYfonAFGc&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=44&ab_channel=takeUforward

class Solution
{
public:
    int fn(int i, int prev, vector<int> &nums, vector<vector<int>> &dp)
    {
        int n = nums.size();
        // if(i==n-1){
        //     if(prev==-1){
        //         return 1;
        //     }

        // }
        if (i == n)
        {
            return 0;
        }
        if (dp[i][prev + 1] != -1)
        {
            return dp[i][prev + 1];
        }
        if (prev == -1)
        {
            return dp[i][prev + 1] = max(1 + fn(i + 1, i, nums, dp), fn(i + 1, prev, nums, dp));
        }
        if (nums[i] > nums[prev])
        {
            return dp[i][prev + 1] = max(1 + fn(i + 1, i, nums, dp), fn(i + 1, prev, nums, dp));
        }
        else
        {
            return dp[i][prev + 1] = fn(i + 1, prev, nums, dp);
        }
    }

    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<long long int>> dp(n + 1, vector<long long int>(n + 1, 0));
        // return fn(0,-1,nums,dp);
        for (int i = -1; i < n; i++)
        {
            dp[n][i + 1] = 0;
        }
        for (int i = n - 1; i >= 0; i--)
        {
            for (int prev = i - 1; prev >= -1; prev--)
            {
                if (prev == -1)
                {
                    dp[i][prev + 1] = max(1 + dp[i + 1][i + 1], dp[i + 1][prev + 1]);
                }
                else if (nums[i] > nums[prev])
                {
                    dp[i][prev + 1] = max(1 + dp[i + 1][i + 1], dp[i + 1][prev + 1]);
                }
                else
                {
                    dp[i][prev + 1] = dp[i + 1][prev + 1];
                }
            }
        }
        return dp[0][0];
    }
};

// https://www.youtube.com/watch?v=IFfYfonAFGc&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=44&ab_channel=takeUforward

class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> lis(n, 1);
        for (int i = 0; i < n; i++)
        {
            for (int j = i - 1; j >= 0; j--)
            {
                if (nums[j] < nums[i])
                {
                    lis[i] = max(lis[i], lis[j] + 1);
                }
            }
        }
        int ans = -1;
        for (int i = 0; i < n; i++)
        {
            ans = max(ans, lis[i]);
        }
        return ans;
    }
};