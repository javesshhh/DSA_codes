// https://leetcode.com/problems/stone-game/description/

// greedy two pointer approach
class Solution
{
public:
    bool stoneGame(vector<int> &piles)
    {
        int s = 0, e = piles.size() - 1, alice = 1, a = 0, b = 0;

        while (s <= e)
        {
            if (alice)
            {
                if (piles[s] > piles[e])
                    a += piles[s++];
                else
                    a += piles[e--];
            }
            else
            {
                if (piles[s] > piles[e])
                    b += piles[e--];
                else
                    b += piles[s++];
            }
            alice = !alice;
        }

        return a > b;
    }
};

// recursion TLE
class Solution
{
public:
    int fn(int i, int j, bool alice, vector<int> &piles)
    {
        if (i > j)
        {
            return 0;
        }
        int ans = 0;
        if (alice)
        {
            return max(piles[i] + fn(i + 1, j, false, piles), piles[j] + fn(i, j - 1, false, piles));
        }
        else
        {
            return max(fn(i + 1, j, false, piles) - piles[i], fn(i, j - 1, false, piles) - piles[j]);
        }
    }

    bool stoneGame(vector<int> &piles)
    {
        // int i=0;
        // int j=piles.size()-1;
        // int alice=0;
        // int bob=0;
        // while(i<=j){
        //     if(piles[i]>=piles[j]){
        //         alice=alice+piles[i];
        //         i++;
        //     }
        //     else{
        //         alice=alice+piles[j];
        //         j--;
        //     }
        //     if(piles[i]>=piles[j]){
        //         bob=bob+piles[i];
        //         i++;
        //     }
        //     else{
        //         bob=bob+piles[j];
        //         j--;
        //     }
        // }
        // if(alice>bob){
        //     return true;
        // }
        // else{
        //     return false;
        // }
        if (fn(0, piles.size() - 1, true, piles))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

// memoization
class Solution
{
public:
    int fn(int i, int j, bool alice, vector<int> &piles, vector<vector<vector<int>>> &dp)
    {
        if (i > j)
        {
            return 0;
        }
        // int ans=0;
        if (dp[i][j][alice] != -1)
        {
            return dp[i][j][alice];
        }
        if (alice)
        {
            return dp[i][j][alice] = max(piles[i] + fn(i + 1, j, false, piles, dp), piles[j] + fn(i, j - 1, false, piles, dp));
        }
        else
        {
            return dp[i][j][alice] = max(fn(i + 1, j, false, piles, dp) - piles[i], fn(i, j - 1, false, piles, dp) - piles[j]);
        }
    }

    bool stoneGame(vector<int> &piles)
    {
        // int i=0;
        // int j=piles.size()-1;
        // int alice=0;
        // int bob=0;
        // while(i<=j){
        //     if(piles[i]>=piles[j]){
        //         alice=alice+piles[i];
        //         i++;
        //     }
        //     else{
        //         alice=alice+piles[j];
        //         j--;
        //     }
        //     if(piles[i]>=piles[j]){
        //         bob=bob+piles[i];
        //         i++;
        //     }
        //     else{
        //         bob=bob+piles[j];
        //         j--;
        //     }
        // }
        // if(alice>bob){
        //     return true;
        // }
        // else{
        //     return false;
        // }
        int n = piles.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(n + 1, vector<int>(2, -1)));
        if (fn(0, piles.size() - 1, true, piles, dp))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};