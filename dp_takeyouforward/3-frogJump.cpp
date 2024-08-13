// https://www.youtube.com/watch?v=EgG3jsGoPvQ&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=4&ab_channel=takeUforward
// https://takeuforward.org/data-structure/dynamic-programming-frog-jump-dp-3/
// https://practice.geeksforgeeks.org/problems/geek-jump/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=geek-jump

public:
int mini(vector<int> &height, int n, vector<int> &dp)
{
    // Code here
    if (n == 0)
    {
        return 0;
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }
    int two = INT_MAX;
    int one = mini(height, n - 1, dp) + abs(height[n] - height[n - 1]);
    if (n > 1)
    {
        two = mini(height, n - 2, dp) + abs(height[n] - height[n - 2]);
    }
    return dp[n] = min(one, two);
}

int minimumEnergy(vector<int> &height, int n)
{
    // Code here
    vector<int> dp(n, -1);
    return mini(height, n - 1, dp);
}

// tabulation optimised solution

int minimumEnergy(vector<int> &height, int n)
{
    // Code here
    vector<int> dp(n, -1);
    dp[0] = 0;
    for (int i = 1; i < n; i++)
    {
        int two = INT_MAX;
        int one = dp[i - 1] + abs(height[i] - height[i - 1]);
        if (i > 1)
        {
            two = dp[i - 2] + abs(height[i] - height[i - 2]);
        }
        dp[i] = min(one, two);
    }
    return dp[n - 1];
}

// space optimized solution

int minimumEnergy(vector<int> &height, int n)
{
    // Code here
    // vector<int>dp(n,-1);
    // dp[0]=0;
    int prev = 0;
    int prev2 = 0;
    for (int i = 1; i < n; i++)
    {
        int two = INT_MAX;
        // int one=dp[i-1]+abs(height[i]-height[i-1]);
        int one = prev + abs(height[i] - height[i - 1]);
        if (i > 1)
        {
            // two=dp[i-2]+abs(height[i]-height[i-2]);
            two = prev2 + abs(height[i] - height[i - 2]);
        }
        // dp[i]=min(one,two);
        int current = min(one, two);
        prev2 = prev;
        prev = current;
    }
    return prev;
}