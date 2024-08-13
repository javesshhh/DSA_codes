// https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=matrix-chain-multiplication
// https://www.youtube.com/watch?v=vRVfmbCFW7Y&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=49&ab_channel=takeUforward
// https://www.youtube.com/watch?v=pDCXsbAw5Cg&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=51&ab_channel=takeUforward
// https://www.youtube.com/watch?v=kMK148J9qEE&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=33&ab_channel=AdityaVerma

// recursion

// User function Template for C++

class Solution
{
public:
    int fn(int i, int j, int n, int arr[])
    {
        if (i >= j)
        {
            return 0;                             // for invalid and least possible input
        }
        int ans = INT_MAX;
        for (int k = i; k <= j - 1; k++)
        {
            int steps = arr[i - 1] * arr[k] * arr[j] + fn(i, k, n, arr) + fn(k + 1, j, n, arr);
            ans = min(ans, steps);
        }
        return ans;
    }

    int matrixMultiplication(int n, int arr[])
    {
        // code here
        return fn(1, n - 1, n, arr);
    }
};

// memoization

// User function Template for C++

class Solution
{
public:
    int fn(int i, int j, int n, int arr[], vector<vector<int>> &dp)
    {
        if (i >= j)
        {
            return 0;
        }
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        int ans = INT_MAX;
        for (int k = i; k <= j - 1; k++)
        {
            int steps = arr[i - 1] * arr[k] * arr[j] + fn(i, k, n, arr, dp) + fn(k + 1, j, n, arr, dp);
            ans = min(ans, steps);
        }
        return dp[i][j] = ans;
    }

    int matrixMultiplication(int n, int arr[])
    {
        // code here
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return fn(1, n - 1, n, arr, dp);
    }
};

// tabulation

// User function Template for C++

class Solution
{
public:
    int fn(int i, int j, int n, int arr[], vector<vector<int>> &dp)
    {
        if (i >= j)
        {
            return 0;
        }
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        int ans = INT_MAX;
        for (int k = i; k <= j - 1; k++)
        {
            int steps = arr[i - 1] * arr[k] * arr[j] + fn(i, k, n, arr, dp) + fn(k + 1, j, n, arr, dp);
            ans = min(ans, steps);
        }
        return dp[i][j] = ans;
    }

    int matrixMultiplication(int n, int arr[])
    {
        // code here
        vector<vector<int>> dp(n, vector<int>(n, 0));
        // return fn(1,n-1,n,arr,dp);
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         if(i==j){
        //             dp[i][j]=0;
        //         }
        //     }
        // }
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = i + 1; j < n; j++)                  // maintaining base condition !(i>=j)
            {
                int ans = INT_MAX;
                for (int k = i; k <= j - 1; k++)
                {
                    int steps = arr[i - 1] * arr[k] * arr[j] + dp[i][k] + dp[k + 1][j];
                    ans = min(ans, steps);
                }
                dp[i][j] = ans;
            }
        }
        return dp[1][n - 1];
    }
};