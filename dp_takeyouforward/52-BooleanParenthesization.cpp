// https://www.youtube.com/watch?v=pGVguAcWX4g&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=38&ab_channel=AdityaVerma
// https://www.youtube.com/watch?v=bzXM1Zond9U&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=39&ab_channel=AdityaVerma
// https://practice.geeksforgeeks.org/problems/boolean-parenthesization5610/1?utm_source=geeksforgeeks&utm_medium=article_practice_tab&utm_campaign=article_practice_tab

// recursion

// User function Template for C++

class Solution
{
public:
    int fn(int i, int j, string &s, bool b)
    {
        if (i > j)
        {
            return 0;
        }1
        if (i == j)
        {
            // if(s[i]==b)
            if (b == true && s[i] == 'T')
            {
                return 1;
            }
            else if (b == true && s[i] == 'F')
            {
                return 0;
            }
            else if (b == false && s[i] == 'F')
            {
                return 1;
            }
            else if (b == false && s[i] == 'T')
            {
                return 0;
            }
        }
        int ans = 0;
        for (int k = i + 1; k <= j - 1; k = k + 2)
        {
            int lf = fn(i, k - 1, s, false);
            int lt = fn(i, k - 1, s, true);
            int rf = fn(k + 1, j, s, false);
            int rt = fn(k + 1, j, s, true);
            if (s[k] == '^')
            {
                if (b == true)
                {
                    ans = (ans + lt * rf + lf * rt);
                }
                else
                    ans = (ans + lf * rf + lt * rt);
            }
            else if (s[k] == '&')
            {
                if (b == true)
                {
                    ans = (ans + lt * rt);
                }
                else
                    ans = (ans + lt * rf + lf * rt + lf * rf);
            }
            else if (s[k] == '|')
            {
                if (b == true)
                {
                    ans = (ans + lt * rt + lt * rf + lf * rt);
                }
                else
                    ans = (ans + lf * rf);
            }
        }
        return ans;
    }

    int countWays(int n, string s)
    {
        // code here
        return fn(0, n - 1, s, true);
    }
};

// memoization

// User function Template for C++

class Solution
{
public:
    int fn(int i, int j, string &s, bool b, vector<vector<vector<int>>> &dp)
    {
        if (i > j)
        {
            return 0;
        }
        if (i == j)
        {
            // if(s[i]==b)
            if (b == true && s[i] == 'T')
            {
                return 1;
            }
            else if (b == true && s[i] == 'F')
            {
                return 0;
            }
            else if (b == false && s[i] == 'F')
            {
                return 1;
            }
            else if (b == false && s[i] == 'T')
            {
                return 0;
            }
        }
        if (dp[i][j][b] != -1)
        {
            return dp[i][j][b];
        }
        int ans = 0;
        for (int k = i + 1; k <= j - 1; k = k + 2)
        {
            int lf = fn(i, k - 1, s, false, dp);
            int lt = fn(i, k - 1, s, true, dp);
            int rf = fn(k + 1, j, s, false, dp);
            int rt = fn(k + 1, j, s, true, dp);
            if (s[k] == '^')
            {
                if (b == true)
                {
                    ans = (ans + lt * rf + lf * rt) % 1003;
                }
                else
                    ans = (ans + lf * rf + lt * rt) % 1003;
            }
            else if (s[k] == '&')
            {
                if (b == true)
                {
                    ans = (ans + lt * rt) % 1003;
                }
                else
                    ans = (ans + lt * rf + lf * rt + lf * rf) % 1003;
            }
            else if (s[k] == '|')
            {
                if (b == true)
                {
                    ans = (ans + lt * rt + lt * rf + lf * rt) % 1003;
                }
                else
                    ans = (ans + lf * rf) % 1003;
            }
        }
        return dp[i][j][b] = ans;
    }

    int countWays(int n, string s)
    {
        // code here
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2, -1)));
        return fn(0, n - 1, s, true, dp);
    }
};

// another way to use map instead of 3d vector

// User function Template for C++

class Solution
{
public:
    unordered_map<string, int> m;
    int solve(string s, int i, int j, bool isTrue)
    {
        if (i > j)
            return 0;
        if (i == j)
        {
            if (isTrue == true)
            {
                return s[i] == 'T';
            }
            else
            {
                return s[i] == 'F';
            }
        }
        string temp = to_string(i);
        temp.push_back(' ');
        temp.append(to_string(j));
        temp.push_back(' ');
        temp.append(to_string(isTrue));
        if (m.find(temp) != m.end())
        {
            return m[temp];
        }

        int ans = 0;
        for (int k = i + 1; k <= j - 1; k = k + 2)
        {
            int lt = solve(s, i, k - 1, true);
            int lf = solve(s, i, k - 1, false);
            int rt = solve(s, k + 1, j, true);
            int rf = solve(s, k + 1, j, false);

            if (s[k] == '^')
            {
                if (isTrue == true)
                {
                    ans = (ans + lt * rf + lf * rt) % 1003;
                }
                else
                    ans = (ans + lf * rf + lt * rt) % 1003;
            }
            else if (s[k] == '&')
            {
                if (isTrue == true)
                {
                    ans = (ans + lt * rt) % 1003;
                }
                else
                    ans = (ans + lt * rf + lf * rt + lf * rf) % 1003;
            }
            else if (s[k] == '|')
            {
                if (isTrue == true)
                {
                    ans = (ans + lt * rt + lt * rf + lf * rt) % 1003;
                }
                else
                    ans = (ans + lf * rf) % 1003;
            }
        }
        return m[temp] = ans;
    }
    int countWays(int N, string S)
    {
        // code here
        int ans = solve(S, 0, N - 1, true);
        return ans;
    }
};

// tabulation

// User function Template for C++

class Solution
{
public:
    int countWays(int n, string &exp)
    {
        // int n = exp.size();
        vector<vector<vector<long long>>> dp(n, vector<vector<long long>>(n, vector<long long>(2, 0)));
        int mod = 1003;
        for (int i = 0; i < n; i++)
        {
            dp[i][i][1] = exp[i] == 'T';
            dp[i][i][0] = exp[i] == 'F';
        }

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = i + 1; j < n; j++)
            {
                for (int isTrue = 0; isTrue <= 1; isTrue++)
                {
                    long long ways = 0;
                    for (int ind = i + 1; ind <= j - 1; ind = ind + 2)
                    {
                        long long lT = dp[i][ind - 1][1];
                        long long lF = dp[i][ind - 1][0];
                        long long rT = dp[ind + 1][j][1];
                        long long rF = dp[ind + 1][j][0];
                        if (exp[ind] == '&')
                        {
                            if (isTrue)
                                ways = (ways + (lT * rT) % mod) % mod;
                            else
                                ways = (ways + (lT * rF) % mod + (lF * rF) % mod + (lF * rT) % mod) % mod;
                        }
                        else if (exp[ind] == '|')
                        {
                            if (isTrue)
                                ways = (ways + (lT * rT) % mod + (lT * rF) % mod + (lF * rT) % mod) % mod;
                            else
                                ways = (ways + (lF * rF) % mod) % mod;
                        }
                        else
                        {
                            if (isTrue)
                                ways = (ways + (lT * rF) % mod + (lF * rT) % mod) % mod;
                            else
                                ways = (ways + (lT * rT) % mod + (lF * rF) % mod) % mod;
                        }
                    }
                    dp[i][j][isTrue] = ways;
                }
            }
        }

        return dp[0][n - 1][1];
    }
};