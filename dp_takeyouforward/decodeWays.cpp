// https://leetcode.com/problems/decode-ways/description/
// https://www.youtube.com/watch?v=mJfqNKwUavE&ab_channel=HelloWorld

class Solution
{
public:
    int fn(int i, string &s, vector<int> &dp)
    {
        int n = s.length();
        if (i >= n)
            return 1;
        if (dp[i] != -1)
            return dp[i];
        if (s[i] == '0')
            return dp[i] = 0;
        if (s[i] == '1' && i + 1 == n)
        {
            return dp[i] = fn(i + 1, s, dp);
        }
        if (s[i] == '1' && i + 1 < n)
        {
            return dp[i] = fn(i + 1, s, dp) + fn(i + 2, s, dp);
        }
        if (s[i] == '2' && i + 1 < n && s[i + 1] <= '6')
        {
            return dp[i] = fn(i + 1, s, dp) + fn(i + 2, s, dp);
        }
        else
        {
            return dp[i] = fn(i + 1, s, dp);
        }
    }

    int numDecodings(string s)
    {
        int n = s.length();
        vector<int> dp(n + 1, -1);
        return fn(0, s, dp);
    }
};