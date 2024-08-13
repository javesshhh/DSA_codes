// https://www.youtube.com/watch?v=fWX9xDmIzRI&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=15&ab_channel=takeUforward
// https://takeuforward.org/data-structure/subset-sum-equal-to-target-dp-14/
// https://practice.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=subset-sum-problem-1611555638
// for recursion - https://youtu.be/eQCS_v3bw0Q

// recursion

// User function template for C++

class Solution
{
public:
    bool fn(int i, vector<int> &arr, int sum)
    {
        if (i == arr.size())
        {
            if (sum == 0)
            {
                return true;
            }
            return false;
        }
        if (sum < 0)
        {
            return false;
        }
        if (fn(i + 1, arr, sum - arr[i]) == true)
            return true;
        if (fn(i + 1, arr, sum) == true)
            return true;
        return false;
    }

    bool isSubsetSum(vector<int> arr, int sum)
    {
        // code here
        return fn(0, arr, sum);
    }
};

// memoization

// User function template for C++

class Solution
{
public:
    bool fn(int i, vector<int> &arr, int sum, vector<vector<int>> &dp)
    {
        if (i == arr.size())
        {
            if (sum == 0)
            {
                return true;
            }
            return false;
        }
        if (sum < 0)
        {
            return false;
        }
        if (dp[i][sum] != -1)
        {
            return dp[i][sum];
        }
        if (fn(i + 1, arr, sum - arr[i], dp) == true)
            return dp[i][sum] = true;
        if (fn(i + 1, arr, sum, dp) == true)
            return dp[i][sum] = true;
        return dp[i][sum] = false;
    }

    bool isSubsetSum(vector<int> arr, int sum)
    {
        // code here
        int n = arr.size();
        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));
        return fn(0, arr, sum, dp);
    }
};

// tabulation

bool isSubsetSum(vector<int> arr, int sum)
{
    // code here
    int n = arr.size();
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
    return dp[0][sum];
}