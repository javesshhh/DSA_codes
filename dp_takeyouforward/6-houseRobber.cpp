// https://www.youtube.com/watch?v=3WaxQMELSkw&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=7&ab_channel=takeUforward
// https://takeuforward.org/data-structure/dynamic-programming-house-robber-dp-6/
// https://practice.geeksforgeeks.org/problems/stickler-theif-1587115621/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=stickler-theif-
// https://leetcode.com/problems/house-robber/description/
// https://leetcode.com/problems/house-robber-ii/description/

// recursion TLE

class Solution
{
public:
    int fn(int i, int arr[], int n)
    {
        if (i >= n)
        {
            return 0;
        }
        int two = arr[i] + fn(i + 2, arr, n);
        int one = 0 + fn(i + 1, arr, n);
        return max(one, two);
    }

    // Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n)
    {
        // Your code here
        return fn(0, arr, n);
    }
};

// memoization

class Solution
{
public:
    int fn(int i, int arr[], int n, vector<int> &dp)
    {
        if (i >= n)
        {
            return 0;
        }
        if (dp[i] != -1)
        {
            return dp[i];
        }
        int two = arr[i] + fn(i + 2, arr, n, dp);
        int one = 0 + fn(i + 1, arr, n, dp);
        return dp[i] = max(one, two);
    }

    // Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n)
    {
        // Your code here
        vector<int> dp(n, -1);
        return fn(0, arr, n, dp);
    }
};

// tabulation

class Solution
{
public:
    int rob(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> dp(n + 2, 0);
        // return fn(0,arr,n,dp);
        // dp[n - 1] = arr[n - 1];
        // dp[n] = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            int two = arr[i] + dp[i + 2];
            int one = 0 + dp[i + 1];
            dp[i] = max(one, two);
        }
        return dp[0];
    }
};

// space optimized

class Solution
{
public:
    // Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n)
    {
        // Your code here
        vector<int> dp(n + 1, -1);
        // return fn(0,arr,n,dp);
        int next = arr[n - 1];
        int next2 = 0;
        for (int i = n - 2; i >= 0; i--)
        {
            int two = arr[i] + next2;
            int one = 0 + next;
            int curr = max(one, two);
            next2 = next;
            next = curr;
        }
        return next;
    }
};