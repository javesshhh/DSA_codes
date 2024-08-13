// https://www.youtube.com/watch?v=cKVl1TFdNXg&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=48&ab_channel=takeUforward
// https://leetcode.com/problems/number-of-longest-increasing-subsequence/description/

class Solution
{
public:
    int findNumberOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n, 1);
        vector<int> v(n, 1);
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[j] < nums[i])
                {
                    if (dp[j] + 1 > dp[i])
                    {
                        dp[i] = dp[j] + 1;
                        v[i] = v[j];
                    }
                    else if (dp[j] + 1 == dp[i])
                    {
                        v[i] = v[i] + v[j];
                    }
                    // dp[i]=max(dp[i],dp[j]+1);
                }
            }
        }
        // int index;
        int k = -1;
        for (int i = 0; i < n; i++)
        {
            k = max(k, dp[i]);
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (dp[i] == k)
            {
                ans = ans + v[i];
            }
        }
        return ans;
    }
};