// https://www.youtube.com/watch?v=ox7fOk3HjlA&ab_channel=CodeHelp-byBabbar
// https://leetcode.com/problems/unique-binary-search-trees/description/
// catalan number https://www.geeksforgeeks.org/c-program-for-program-for-nth-catalan-number/
// applications of catalan number https://www.geeksforgeeks.org/applications-of-catalan-numbers/

class Solution
{
private:
    int totalTrees(int n, int dp[])
    {
        if (n <= 1)
            return 1;
        if (dp[n])
            return dp[n];

        for (int i = 1; i <= n; i++)
        {
            dp[n] += totalTrees(i - 1, dp) * totalTrees(n - i, dp);
        }

        return dp[n];
    }

public:
    int numTrees(int n)
    {
        int dp[20] = {0};
        return totalTrees(n, dp);
    }
};

.

    class Solution
{
public:
    int numTrees(int n)
    {
        long long res = 1;
        for (int i = 1; i <= n; i++)
        {
            res *= (n + i);
            res /= i;
        }
        return res / (n + 1);
    }
};