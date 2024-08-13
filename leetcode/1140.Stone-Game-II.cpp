// https://www.youtube.com/watch?v=6hu5G-abkdg&t=423s&ab_channel=Fraz
// https://leetcode.com/problems/stone-game-ii/description/

// recursion

class Solution
{
public:
    int fn(bool alice, int m, int x, vector<int> &piles)
    {
        int n = piles.size();
        if (x >= n)
        {
            return 0;
        }
        int ans = 0;
        if (!alice)
        {
            ans = INT_MAX;
        }
        int total;
        for (int i = 1; i <= 2 * m, x + i - 1 < n; i++)
        {
            total = total + piles[x + i - 1];
            if (alice)
            {
                ans = max(ans, total + fn(false, max(m, i), x + i, piles));
            }
            else
            {
                ans = min(ans, fn(true, max(m, i), x + i, piles));
            }
        }
        return ans;
    }

    int f(int i, int m, vector<int> &piles)
    {
        if (i >= piles.size())
        {
            return 0;
        }
        int total = 0;
        int ans = INT_MIN;
        int n = piles.size();
        for (int j = 0; j < 2 * m; j++)
        {
            if (i + j < n)
                total = total + piles[i + j];
            ans = max(ans, total - f(i + j + 1, max(m, j + 1), piles));
        }
        return ans;
    }

    int stoneGameII(vector<int> &piles)
    {
        // return fn(1,1,0,piles);
        int sum = 0;
        for (auto it : piles)
        {
            sum = sum + it;
        }
        int diff = f(0, 1, piles);
        return (sum + diff) / 2;
        ;
    }
};

// memoization

class Solution
{
public:
    int fn(bool alice, int m, int x, vector<int> &piles)
    {
        int n = piles.size();
        if (x >= n)
        {
            return 0;
        }
        int ans = 0;
        if (!alice)
        {
            ans = INT_MAX;
        }
        int total;
        for (int i = 1; i <= 2 * m, x + i - 1 < n; i++)
        {
            total = total + piles[x + i - 1];
            if (alice)
            {
                ans = max(ans, total + fn(false, max(m, i), x + i, piles));
            }
            else
            {
                ans = min(ans, fn(true, max(m, i), x + i, piles));
            }
        }
        return ans;
    }

    int f(int i, int m, vector<int> &piles, vector<vector<int>> &dp)
    {
        if (i >= piles.size())
        {
            return 0;
        }
        int total = 0;
        int ans = INT_MIN;
        int n = piles.size();
        if (dp[i][m] != -1)
        {
            return dp[i][m];
        }
        for (int j = 0; j < 2 * m; j++)
        {
            if (i + j < n)
                total = total + piles[i + j];
            ans = max(ans, total - f(i + j + 1, max(m, j + 1), piles, dp));
        }
        return dp[i][m] = ans;
    }

    int stoneGameII(vector<int> &piles)
    {
        // return fn(1,1,0,piles);
        int sum = 0;
        for (auto it : piles)
        {
            sum = sum + it;
        }
        int n = piles.size();
        vector<vector<int>> dp(n + 1, vector<int>(2 * n + 1, -1));
        int diff = f(0, 1, piles, dp);
        return (sum + diff) / 2;
        ;
    }
};

// another

class Solution
{
public:
    // int fn(bool alice, int m,int x,vector<int>& piles){
    //     int n=piles.size();
    //     if(x>=n){
    //         return 0;
    //     }
    //     int ans=0;
    //     if(!alice){
    //         ans=INT_MAX;
    //     }
    //     int total;
    //     for(int i=1;i<=2*m,x+i-1<n;i++){
    //         total=total+piles[x+i-1];
    //         if(alice){
    //             ans=max(ans,total+fn(false,max(m,i),x+i,piles));
    //         }
    //         else{
    //             ans=min(ans,fn(true,max(m,i),x+i,piles));
    //         }
    //     }
    //     return ans;
    // }

    int f(int i, int m, vector<int> &piles, vector<vector<int>> &dp)
    {
        if (i >= piles.size())
        {
            return 0;
        }
        // int total=0;
        int ans = INT_MIN;
        int n = piles.size();
        if (dp[i][m] != -1)
        {
            return dp[i][m];
        }
        for (int j = i; j < min(i + 2 * m, n); j++)
        {
            // if(j<n)total=total+piles[i+j];
            ans = max(ans, accumulate(piles.begin() + i, piles.begin() + j + 1, 0) - f(j + 1, max(m, j - i + 1), piles, dp));
        }
        return dp[i][m] = ans;
    }

    int stoneGameII(vector<int> &piles)
    {
        // return fn(1,1,0,piles);
        int sum = 0;
        for (auto it : piles)
        {
            sum = sum + it; // here we get a + b
        }
        int n = piles.size();
        vector<vector<int>> dp(n + 1, vector<int>(2 * n + 1, -1));
        int diff = f(0, 1, piles, dp); // here we get a - b
        return (sum + diff) / 2;
        ; // here we get 2a/2=a -> alice
    }
};