// https://www.youtube.com/watch?v=HsLG5QW9CFQ&ab_channel=NeetCodeIO
// https://www.youtube.com/watch?v=HsY3jFyaePU&t=16s&ab_channel=Fraz
// https://leetcode.com/problems/stone-game-iii/description/

// recursion

class Solution
{
public:
    int fn(int i, vector<int> &stone)
    {
        int n = stone.size();
        if (i >= n)
        {
            return 0;
        }
        // int z=0;
        // for(int j=1;j<=3,i+j-1<n;j++){
        //     for(int p=0;p<j;p++){

        //         z=z+stone[i+p];
        //     }
        //     ans=max(ans,z-fn(i+j,stone));
        // }
        int ans = INT_MIN;
        ans = max(ans, stone[i] - fn(i + 1, stone));
        if (i + 1 < n)
        {
            ans = max(ans, stone[i] + stone[i + 1] - fn(i + 2, stone));
        }
        if (i + 2 < n)
        {
            ans = max(ans, stone[i] + stone[i + 1] + stone[i + 2] - fn(i + 3, stone));
        }
        return ans;
    }

    string stoneGameIII(vector<int> &stone)
    {
        if (fn(0, stone) > 0)
        {
            return "Alice";
        }
        else if (fn(0, stone) == 0)
        {
            return "Tie";
        }
        else
        {
            return "Bob";
        }
    }
};

// memoization

class Solution
{
public:
    int fn(int i, vector<int> &stone, vector<int> &dp)
    {
        int n = stone.size();
        if (i >= n)
        {
            return 0;
        }
        if (dp[i] != -1)
        {
            return dp[i];
        }
        // int z=0;
        // for(int j=1;j<=3,i+j-1<n;j++){
        //     for(int p=0;p<j;p++){

        //         z=z+stone[i+p];
        //     }
        //     ans=max(ans,z-fn(i+j,stone));
        // }
        int ans = INT_MIN;
        ans = max(ans, stone[i] - fn(i + 1, stone, dp));
        if (i + 1 < n)
        {
            ans = max(ans, stone[i] + stone[i + 1] - fn(i + 2, stone, dp));
        }
        if (i + 2 < n)
        {
            ans = max(ans, stone[i] + stone[i + 1] + stone[i + 2] - fn(i + 3, stone, dp));
        }
        return dp[i] = ans;
    }

    string stoneGameIII(vector<int> &stone)
    {
        int n = stone.size();
        vector<int> dp(n + 1, -1);
        if (fn(0, stone, dp) > 0)
        {
            return "Alice";
        }
        else if (fn(0, stone, dp) == 0)
        {
            return "Tie";
        }
        else
        {
            return "Bob";
        }
    }
};

// other method by using loop

class Solution
{
public:
    int fn(int i, vector<int> &values, vector<int> &dp)
    {
        int n = values.size();
        if (i >= n)
        {
            return 0;
        }
        if (dp[i] != -1)
        {
            return dp[i];
        }
        // int z=0;
        // for(int j=1;j<=3,i+j-1<n;j++){
        //     for(int p=0;p<j;p++){

        //         z=z+stone[i+p];
        //     }
        //     ans=max(ans,z-fn(i+j,stone));
        // }
        // if (i == values.size())
        //     return 0;

        int res = INT_MIN;
        for (int j = i; j < min(i + 3, (int)values.size()); j++)
        {

            res = max(res, accumulate(values.begin() + i, values.begin() + j + 1, 0) - fn(j + 1, values, dp));
        }
        return dp[i] = res;
        // return dp[i]=ans;
    }

    string stoneGameIII(vector<int> &stone)
    {
        int n = stone.size();
        vector<int> dp(n + 1, -1);
        if (fn(0, stone, dp) > 0)
        {
            return "Alice";
        }
        else if (fn(0, stone, dp) == 0)
        {
            return "Tie";
        }
        else
        {
            return "Bob";
        }
    }
};