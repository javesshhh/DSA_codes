// https://www.youtube.com/watch?v=GS_OqZb2CWc&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=17&ab_channel=takeUforward

// https://www.codingninjas.com/codestudio/problems/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum_842494?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0

#include <bits/stdc++.h>
int minSubsetSumDifference(vector<int> &arr, int n)
{
    long long int sum = 0;
    // int n = nums.size();
    // int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        sum = sum + arr[i];
    }
    vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));
    // return fn(0,arr,sum,dp);
    dp[n][0] = true;

    for (int i = n - 1; i >= 0; i--)
    {
        for (int s = 0; s <= sum; s++)
        {

            if (s - arr[i] >= 0 && dp[i + 1][s - arr[i]] == true)
                dp[i][s] = true;

            if (dp[i + 1][s] == true)
                dp[i][s] = true;
        }
    }
    long long int ans = 1e9;
    for (int k = 0; k <= sum; k++)
    {
        if (dp[0][k] == true)
        {
            ans = min(ans, abs(sum - k - k));
        }
    }
    return ans;
}

// another

int minSubsetSumDifference(vector<int> &arr, int n)
{
    long long int sum = 0;
    // int n = nums.size();
    // int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        sum = sum + arr[i];
    }
    vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));
    // return fn(0,arr,sum,dp);
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = true;
    }
    if (arr[0] <= sum)
    {
        dp[0][arr[0]] = true;
    }

    for (int i = 1; i < n; i++)
    {
        for (int s = 1; s <= sum; s++)
        {
            bool nottake = dp[i - 1] [s];
            bool take = false;
            if (arr[i] <= s)
            {
                take = dp[i - 1][s - arr[i]];
            }
            dp[i][s] = nottake || take;
        }
    }
    long long int ans = 1e9;
    for (int k = 0; k <= sum; k++)
    {
        if (dp[n - 1][k] == true)
        {
            ans = min(ans, abs(sum - k - k));
        }
    }
    return ans;
}

// https://leetcode.com/problems/partition-array-into-two-arrays-to-minimize-sum-difference/
