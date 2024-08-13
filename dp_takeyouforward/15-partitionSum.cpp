// https://www.youtube.com/watch?v=7win3dcgo3k&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=16&ab_channel=takeUforward
// https://leetcode.com/problems/partition-equal-subset-sum/description/
similar to previous problem

    // recursion

    class Solution
{
public:
    bool fn(int i, vector<int> &nums, int target, int n)
    {
        if (i == n)
        {
            if (target == 0)
            {
                return true;
            }
            return false;
        }
        if (target < 0)
        {
            return false;
        }
        if (fn(i + 1, nums, target - nums[i], n) == true)
        {
            return true;
        }
        if (fn(i + 1, nums, target, n) == true)
        {
            return true;
        }
        return false;
    }

    bool canPartition(vector<int> &nums)
    {
        int sum = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            sum = sum + nums[i];
        }
        if (sum % 2 == 1)
        {
            return false;
        }
        else
        {
            return fn(0, nums, sum / 2, n);
        }
    }
};

// memoization

class Solution
{
public:
    bool fn(int i, vector<int> &nums, int target, int n, vector<vector<int>> &dp)
    {
        if (i == n)
        {
            if (target == 0)
            {
                return true;
            }
            return false;
        }
        if (target < 0)
        {
            return false;
        }
        if (dp[i][target] != -1)
        {
            return dp[i][target];
        }
        if (fn(i + 1, nums, target - nums[i], n, dp) == true)
        {
            return dp[i][target] = true;
        }
        if (fn(i + 1, nums, target, n, dp) == true)
        {
            return dp[i][target] = true;
        }
        return dp[i][target] = false;
    }

    bool canPartition(vector<int> &nums)
    {
        int sum = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            sum = sum + nums[i];
        }
        if (sum % 2 == 1)
        {
            return false;
        }
        else
        {
            int target = sum / 2;
            vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));
            return fn(0, nums, target, n, dp);
        }
    }
};

// tabulation

class Solution
{
public:
    bool fn(int i, vector<int> &nums, int target, int n, vector<vector<int>> &dp)
    {
        if (i == n)
        {
            if (target == 0)
            {
                return true;
            }
            return false;
        }
        if (target < 0)
        {
            return false;
        }
        if (dp[i][target] != -1)
        {
            return dp[i][target];
        }
        if (fn(i + 1, nums, target - nums[i], n, dp) == true)
        {
            return dp[i][target] = true;
        }
        if (fn(i + 1, nums, target, n, dp) == true)
        {
            return dp[i][target] = true;
        }
        return dp[i][target] = false;
    }

    bool canPartition(vector<int> &nums)
    {
        int sum = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            sum = sum + nums[i];
        }
        if (sum % 2 == 1)
        {
            return false;
        }
        else
        {
            // int target=sum/2;
            // vector<vector<bool>>dp(n+1,vector<bool>(target+1,false));
            // // return fn(0,nums,target,n,dp);
            // dp[n][0]=true;
            // for(int i=n-1;i>=0;i--){
            //     for(int s=0;s<=target;s++){
            //         if(dp[i+1][s-nums[i]]==true && s-nums[i]>=0){
            //             dp[i][s]= true;
            //         }
            //         if(dp[i+1][s]==true){
            //             dp[i][s]= true;
            //         }
            //     }
            // }
            // return dp[0][target];
            sum = sum / 2;
            vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));
            // return fn(0,arr,sum,dp);

            dp[n][0] = true;

            for (int i = n - 1; i >= 0; i--)
            {
                for (int s = 0; s <= sum; s++)
                {

                    if (s - nums[i] >= 0 && dp[i + 1][s - nums[i]] == true)
                        dp[i][s] = true;

                    if (dp[i + 1][s] == true)
                        dp[i][s] = true;
                }
            }
            return dp[0][sum];
        }
    }
};