// https://www.youtube.com/watch?v=PhWWJmaKfMc&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=55&ab_channel=takeUforward
// https://leetcode.com/problems/partition-array-for-maximum-sum/description/

// recursion

class Solution
{
public:
    int fn(int i, vector<int> &arr, int k)
    {
        if (i == arr.size())
        {
            return 0;
        }
        int ans = INT_MIN;
        int maxi = INT_MIN;
        int n = arr.size();
        int len = 0;
        for (int j = i; j < min(n, i + k); j++)
        {
            len++;
            maxi = max(maxi, arr[j]);
            int mini = maxi * len + fn(j + 1, arr, k);
            ans = max(ans, mini);
        }
        return ans;
    }

    int maxSumAfterPartitioning(vector<int> &arr, int k)
    {
        return fn(0, arr, k);
    }
};

// memoization

class Solution
{
public:
    int fn(int i, vector<int> &arr, int k, vector<int> &dp)
    {
        if (i == arr.size())
        {
            return 0;
        }
        if (dp[i] != -1)
        {
            return dp[i];
        }
        int ans = INT_MIN;
        int maxi = INT_MIN;
        int n = arr.size();
        int len = 0;
        for (int j = i; j < min(n, i + k); j++)
        {
            len++;
            maxi = max(maxi, arr[j]);
            int mini = maxi * len + fn(j + 1, arr, k, dp);
            ans = max(ans, mini);
        }
        return dp[i] = ans;
    }

    int maxSumAfterPartitioning(vector<int> &arr, int k)
    {
        int n = arr.size();
        vector<int> dp(n + 1, -1);
        return fn(0, arr, k, dp);
    }
};

// another

class Solution
{
public:
    int fn2(int i, int j, int k, vector<int> &arr)
    {
        int mx = -1;
        for (int z = i; z <= j; z++)
        {
            mx = max(mx, arr[z]);
        }
        return (j - i + 1) * mx;
    }

    int fn(int i, int j, int k, vector<int> &arr, vector<vector<int>> &dp)
    {
        if (i > j)
            return dp[i][j] = 0;
        if (i == j)
            return dp[i][j] = arr[i];
        if (j - i + 1 <= k)
        {
            return dp[i][j] = fn2(i, j, k, arr);
        }
        if (dp[i][j] != -1)
            return dp[i][j];
        int temp = 0;
        int ans = INT_MIN;
        for (int z = i; z < min(j, i + k); z++)
        {
            temp = fn(i, z, k, arr, dp) + fn(z + 1, j, k, arr, dp);
            ans = max(ans, temp);
        }
        return dp[i][j] = ans;
    }

    int maxSumAfterPartitioning(vector<int> &arr, int k)
    {
        int n = arr.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return fn(0, n - 1, k, arr, dp);
    }
};