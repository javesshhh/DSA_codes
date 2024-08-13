// https://www.youtube.com/watch?v=ZHyb-A2Mte4&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=18&ab_channel=takeUforward
// https://practice.geeksforgeeks.org/problems/perfect-sum-problem5633/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=perfect-sum-problem

// recursion

class Solution
{

public:
    int fn(int i, int sum, int arr[])
    {
        // if(sum==0){
        //     return 1;
        // }
        // if(i==0){
        //     if(arr[i]==sum){                                       // coz 0 terms will be ignored in this case 
        //         return 1;
        //     }
        //     else return 0;
        // }
        if (i < 0)
        {
            return sum == 0;
        }
        int notPick = fn(i - 1, sum, arr);
        int pick = 0;
        if (arr[i] <= sum)
        {
            pick = fn(i - 1, sum - arr[i], arr);
        }
        return (pick + notPick) % (int)(pow(10, 9) + 7);
    }

    int perfectSum(int arr[], int n, int sum)
    {
        // Your code goes here
        return fn(n - 1, sum, arr);
    }
};

// memoization

class Solution
{

public:
    int fn(int i, int sum, int arr[], vector<vector<int>> &dp)
    {
        // if(sum==0){
        //     return 1;
        // }
        // if(i==0){
        //     if(arr[i]==sum){
        //         return 1;
        //     }
        //     else return 0;
        // }
        if (i < 0)
        {
            return sum == 0;
        }
        if (dp[i][sum] != -1)
        {
            return dp[i][sum];
        }
        int notPick = fn(i - 1, sum, arr, dp);
        int pick = 0;
        if (arr[i] <= sum)
        {
            pick = fn(i - 1, sum - arr[i], arr, dp);
        }
        return dp[i][sum] = (pick + notPick) % (int)(pow(10, 9) + 7);
    }

    int perfectSum(int arr[], int n, int sum)
    {
        // Your code goes here
        vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
        return fn(n - 1, sum, arr, dp);
    }
};

// just another base condition

class Solution
{

public:
    int fn(int i, int sum, int arr[], vector<vector<int>> &dp)
    {
        // if(i<0){
        //     if(sum==0){
        //         return 1;
        //     }
        //     else{
        //         return 0;
        //     }
        // }
        if (i == 0)
        {
            if (sum == 0 && arr[0] == sum)
                return 2;
            else if (arr[0] == sum || sum == 0)
                return 1;
            else
                return 0;
        }
        if (dp[i][sum] != -1)
        {
            return dp[i][sum];
        }
        int notPick = fn(i - 1, sum, arr, dp);
        int pick = 0;
        if (arr[i] <= sum)
        {
            pick = fn(i - 1, sum - arr[i], arr, dp);
        }
        return dp[i][sum] = (pick + notPick) % (int)(pow(10, 9) + 7);
    }

    int perfectSum(int arr[], int n, int sum)
    {
        // Your code goes here
        vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
        // return fn(n - 1, sum, arr, dp);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= sum; j++)
            {
                int notPick;
                if (i == 0 && sum == 0)
                {
                    notPick = 1;
                }
                else if (i == 0 && sum != 0)
                {
                    notPick = 0;
                }
                else
                    notPick = dp[i - 1][sum];
                int pick = 0;
                if (arr[i] <= sum)
                {
                    if (i == 0 && sum == 0)
                    {
                        pick = 1;
                    }
                    else if (i == 0 && sum != 0)
                    {
                        pick = 0;
                    }
                    else
                        pick = dp[i - 1][sum - arr[i]];
                }
                dp[i][sum] = (pick + notPick) % (int)(pow(10, 9) + 7);
            }
        }
        return dp[n - 1][sum];
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
    int fn(int i, int sum, int arr[], vector<vector<int>> &dp)
    {
        // if(i<0){
        //     if(sum==0){
        //         return 1;
        //     }
        //     else{
        //         return 0;
        //     }
        // }
        if (i == 0)
        {
            if (sum == 0 && arr[0] == sum)
                return 2;
            else if (arr[0] == sum || sum == 0)
                return 1;
            else
                return 0;
        }
        if (dp[i][sum] != -1)
        {
            return dp[i][sum];
        }
        int notPick = fn(i - 1, sum, arr, dp);
        int pick = 0;
        if (arr[i] <= sum)
        {
            pick = fn(i - 1, sum - arr[i], arr, dp);
        }
        return dp[i][sum] = (pick + notPick) % (int)(pow(10, 9) + 7);
    }

    int perfectSum(int arr[], int n, int sum)
    {
        // Your code goes here
        vector<vector<int>> dp(n, vector<int>(sum + 1, 0));
        // return fn(n-1,sum,arr,dp);
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
            if (arr[0] <= sum)
            {
                dp[0][arr[0]] = 1;
            }
        }
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j <= sum; j++)
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
        return dp[n - 1][sum];
    }
};

//{ Driver Code Starts.
int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];

        Solution ob;
        cout << ob.perfectSum(a, n, sum) << "\n";
    }
    return 0;
}

// } Driver Code Ends