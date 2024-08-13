// https://youtu.be/mO8XpGoJwuo
// https://practice.geeksforgeeks.org/problems/rod-cutting0840/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=rod-cutting0840

// recursion

class Solution
{
public:
    int fn(int i, int len, int price[], int n, vector<vector<int>> &dp)
    {
        if (i == n)
        {
            if (len == 0)
                return 0;
            else
                return -1e8;
        }
        if (dp[i][len] != -1)
            return dp[i][len];
        int one = fn(i + 1, len, price, n, dp);
        int two = -1e8;
        if (len - i - 1 >= 0)
            two = price[i] + fn(i, len - i - 1, price, n, dp);
        return dp[i][len] = max(one, two);
    }

    int cutRod(int price[], int n)
    {
        // code here
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return fn(0, n, price, n, dp);
    }
};

// memoization

class Solution
{
public:
    int fn(int i, int len, int price[], vector<vector<int>> &dp)
    {
        int n = sizeof(price) / sizeof(price[0]);
        if (i == 0)
        {
            return len * price[0];
        }
        if (dp[i][len] != -1)
            return dp[i][len];
        if (i + 1 > len)
        {
            return dp[i][len] = fn(i - 1, len, price, dp);
        }
        else
        {
            return dp[i][len] = max(price[i] + fn(i, len - (i + 1), price, dp), fn(i - 1, len, price, dp));
        }
    }

    int cutRod(int price[], int len)
    {
        // code here
        vector<vector<int>> dp(len, vector<int>(len + 1, -1));
        return fn(len - 1, len, price, dp);
    }
};

// tabulation

// User function Template for C++

class Solution
{
public:
    // int fn(int i,int len,int price[] , vector<vector<int>>  &dp){
    //     int n=sizeof(price)/sizeof(price[0]);
    //     if(i==0){
    //         return len*price[0];
    //     }
    //     if(dp[i][len]!=-1)return dp[i][len];
    //     if(i+1>len){
    //         return dp[i][len]=fn(i-1,len,price ,dp);
    //     }
    //     else{
    //         return dp[i][len]=max(price[i]+fn(i,len-(i+1),price ,dp),fn(i-1,len,price , dp));
    //     }
    // }

    int cutRod(int price[], int len)
    {
        // code here
        //  int n=sizeof(price)/sizeof(price[0]);
        vector<vector<int>> dp(len, vector<int>(len + 1, 0));
        // return fn(len-1  ,len,price , dp);
        for (int l = 0; l <= len; l++)
        {
            dp[0][l] = l * price[0];
        }
        for (int i = 1; i < len; i++)
        {
            for (int j = 0; j <= len; j++)
            {
                if (i + 1 > j)
                {
                    dp[i][j] = dp[i - 1][j];
                }
                else
                {
                    dp[i][j] = max(price[i] + dp[i][j - (i + 1)], dp[i - 1][j]);
                }
            }
        }
        return dp[len - 1][len];
    }
};

// space optimization

// User function Template for C++

class Solution
{
public:
    // int fn(int i,int len,int price[] , vector<vector<int>>  &dp){
    //     int n=sizeof(price)/sizeof(price[0]);
    //     if(i==0){
    //         return len*price[0];
    //     }
    //     if(dp[i][len]!=-1)return dp[i][len];
    //     if(i+1>len){
    //         return dp[i][len]=fn(i-1,len,price ,dp);
    //     }
    //     else{
    //         return dp[i][len]=max(price[i]+fn(i,len-(i+1),price ,dp),fn(i-1,len,price , dp));
    //     }
    // }

    int cutRod(int price[], int len)
    {
        // code here
        //  int n=sizeof(price)/sizeof(price[0]);
        //  vector<vector<int>> dp(len , vector<int>(len+1 , 0));
        vector<int> prev(len + 1, 0), curr(len + 1, 0);
        // return fn(len-1  ,len,price , dp);
        for (int l = 0; l <= len; l++)
        {
            prev[l] = l * price[0];
        }
        for (int i = 1; i < len; i++)
        {
            for (int j = 0; j <= len; j++)
            {
                if (i + 1 > j)
                {
                    curr[j] = prev[j];
                }
                else
                {
                    curr[j] = max(price[i] + curr[j - (i + 1)], prev[j]);
                }
            }
            prev = curr;
        }
        return prev[len];
    }
};