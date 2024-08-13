// https://www.youtube.com/watch?v=zoilQD1kYSg&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=19&ab_channel=takeUforward
// https://practice.geeksforgeeks.org/problems/partitions-with-given-difference/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=partitions-with-given-difference

// recursion

class Solution
{
public:
    int fn(int i, vector<int> &arr, int sum, int n)
    {
        if (i == 0)
        {
            if (sum == 0 && arr[0] == sum)
            {
                return 2;
            }
            if (sum == 0 || arr[0] == sum)
            {
                return 1;
            }
            return 0;
        }
        int nopick = fn(i - 1, arr, sum, n);
        int pick = 0;
        if (arr[i] <= sum)
        {
            pick = fn(i - 1, arr, sum - arr[i], n);
        }
        return pick + nopick;
    }

    int countPartitions(int n, int d, vector<int> &arr)
    {
        // Code here
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum = sum + arr[i];
        }
        int target = (sum - d) / 2;
        if (sum < d)
        {
            return 0;
        }
        if ((sum - d) % 2 == 1)
        {
            return 0;
        }
        return fn(n - 1, arr, target, n);
    }
};












// memoization

class Solution
{
public:
    int fn(int i, vector<int> &arr, int sum, int n, vector<vector<int>> &dp)
    {
        if (i == 0)
        {
            if (sum == 0 && arr[0] == sum)
            {
                return 2;
            }
            if (sum == 0 || arr[0] == sum)
            {
                return 1;
            }
            return 0;
        }
        if (dp[i][sum] != -1)
        {
            return dp[i][sum];
        }
        int nopick = fn(i - 1, arr, sum, n, dp);
        int pick = 0;
        if (arr[i] <= sum)
        {
            pick = fn(i - 1, arr, sum - arr[i], n, dp);
        }
        return dp[i][sum] = (pick + nopick) % (int)(pow(10, 9) + 7);
    }

    int countPartitions(int n, int d, vector<int> &arr)
    {
        // Code here
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum = sum + arr[i];
        }
        int target = (sum - d) / 2;
        if (sum < d)
        {
            return 0;
        }
        if ((sum - d) % 2 == 1)
        {
            return 0;
        }
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        return fn(n - 1, arr, target, n, dp);
    }
};












// tabulation

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int fn(int i, vector<int> &arr, int sum, int n, vector<vector<int>> &dp)
    {
        if (i == 0)
        {
            if (sum == 0 && arr[0] == sum)
            {
                return 2;
            }
            if (sum == 0 || arr[0] == sum)
            {
                return 1;
            }
            return 0;
        }
        if (dp[i][sum] != -1)
        {
            return dp[i][sum];
        }
        int nopick = fn(i - 1, arr, sum, n, dp);
        int pick = 0;
        if (arr[i] <= sum)
        {
            pick = fn(i - 1, arr, sum - arr[i], n, dp);
        }
        return dp[i][sum] = (pick + nopick) % (int)(pow(10, 9) + 7);
    }

    int countPartitions(int n, int d, vector<int> &arr)
    {
        // Code here
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum = sum + arr[i];
        }
        int target = (sum - d) / 2;
        if (sum < d)
        {
            return 0;
        }
        if ((sum - d) % 2 == 1)
        {
            return 0;
        }
        vector<vector<int>> dp(n, vector<int>(target + 1, 0));
        // return fn(n-1,arr,target,n,dp);
        if (arr[0] == 0)
        {
            dp[0][0] = 2;
        }
        else
        {
            dp[0][0] = 1;
        }
        if (arr[0] != 0)
        {
            if (arr[0] <= target)
            {
                dp[0][arr[0]] = 1;
            }
        }
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j <= target; j++)
            {
                int notPick = dp[i - 1][j];
                int pick = 0;
                if (arr[i] <= j)
                {
                    pick = dp[i - 1][j - arr[i]];
                }
                dp[i][j] = (pick + notPick) % (int)(pow(10, 9) + 7);
            }
        }
        return dp[n - 1][target];
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i)
        {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends