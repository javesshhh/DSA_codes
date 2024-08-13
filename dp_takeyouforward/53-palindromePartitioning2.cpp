// recursion https://www.youtube.com/watch?v=szKVpQtBHh8&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=35&ab_channel=AdityaVerma
// memoization https://www.youtube.com/watch?v=fOUlNlawdAU&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=36&ab_channel=AdityaVerma
// optimized https://www.youtube.com/watch?v=9h10fqkI7Nk&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=37&ab_channel=AdityaVerma

// https://leetcode.com/problems/palindrome-partitioning-ii/description/

// recursion

class Solution
{
public:
    bool palindrome(string &s, int i, int j)
    {
        if (i >= j)
        {
            return true;
        }
        if (s[i] == s[j])
        {
            return palindrome(s, i + 1, j - 1);
        }
        return false;
    }

    int fn(string &s, int i, int j)
    {
        if (i >= j)
        {
            return 0;
        }
        if (palindrome(s, i, j))
        {
            return 0;
        }
        int ans = INT_MAX;
        for (int k = i; k <= j - 1; k++)
        {
            int mini = fn(s, i, k) + fn(s, k + 1, j) + 1;
            ans = min(ans, mini);
        }
        return ans;
    }

    int minCut(string s)
    {
        int n = s.length();
        return fn(s, 0, n - 1);
    }
};

// memoization

class Solution
{
public:
    bool palindrome(string &s, int i, int j)
    {
        if (i >= j)
        {
            return true;
        }
        if (s[i] == s[j])
        {
            return palindrome(s, i + 1, j - 1);
        }
        return false;
        // while(i<j){
        //     if(s[i]!=s[j]){
        //         return false;
        //     }
        //     i++;
        //     j--;
        // }
        // return true;
    }

    int fn(string &s, int i, int j, vector<vector<int>> &dp)
    {
        if (i >= j)
        {
            return 0;
        }
        if (palindrome(s, i, j))
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
            int mini = fn(s, i, k, dp) + fn(s, k + 1, j, dp) + 1;
            ans = min(ans, mini);
        }
        return dp[i][j] = ans;
    }

    int minCut(string s)
    {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return fn(s, 0, n - 1, dp);
    }
};

// optimized - still TLE

class Solution
{
public:
    // int palin[n][n]={-1};
    bool palindrome(string &s, int i, int j, vector<vector<int>> &palin)
    {
        if (i >= j)
        {
            return true;
        }
        // if(s[i]==s[j]){
        //     return palin[i][j]=palindrome(s,i+1,j-1,palin);
        // }
        // return palin[i][j]=false;
        while (i < j)
        {
            if (s[i] != s[j])
            {
                return palin[i][j] = false;
            }
            i++;
            j--;
        }
        return palin[i][j] = true;
    }

    int fn(string &s, int i, int j, vector<vector<int>> &dp, vector<vector<int>> &palin)
    {
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        if (i >= j)
        {
            return dp[i][j] = 0;
        }
        if (palin[i][j] != -1)
        {
            if (palin[i][j] == 1)
            {
                return dp[i][j] = 0;
            }
        }
        else
        {
            if (palindrome(s, i, j, palin))
            {
                return dp[i][j] = 0;
            }
        }
        int ans = INT_MAX;
        for (int k = i; k <= j - 1; k++)
        {
            int left, right;
            if (dp[i][k] != -1)
            {
                left = dp[i][k];
            }
            else
            {
                dp[i][k] = fn(s, i, k, dp, palin);
                left = dp[i][k];
            }
            if (dp[k + 1][j] != -1)
            {
                right = dp[k + 1][j];
            }
            else
            {
                dp[k + 1][j] = fn(s, k + 1, j, dp, palin);
                right = dp[k + 1][j];
            }
            int mini = left + right + 1;
            ans = min(ans, mini);
        }
        return dp[i][j] = ans;
    }

    int minCut(string s)
    {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        vector<vector<int>> palin(n, vector<int>(n, -1));
        return fn(s, 0, n - 1, dp, palin);
    }
};

// above code still giving TLE

// striver approach of checking if front of partition is apalindrome or not
// then only calling function for that partition
// https://www.youtube.com/watch?v=_H8V5hJUGd0&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=54&ab_channel=takeUforward

class Solution
{
public:
    int helper(string &s, int i, int j, vector<vector<int>> &dp)
    {
        if (i >= j || isPallindrome(s, i, j))
        {
            dp[i][j] = 0;
            return 0;
        }

        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        int mn = INT_MAX;

        for (int k = i; k <= j; k++)
        {
            if (isPallindrome(s, i, k))
            { // doing so that we call function for possible partition if front partiotion is a palindrome or not
                mn = min(mn, 1 + helper(s, k + 1, j, dp));
            }
        }
        return dp[i][j] = mn;
    }
    bool isPallindrome(string &s, int i, int j)
    {
        while (i <= j)
        {
            if (s[i] != s[j])
            {
                return false;
            }
            else
            {
                j--;
                i++;
            }
        }
        return true;
    }

    int minCut(string s)
    {
        // memset(dp,-1, sizeof(dp));
        vector<vector<int>> dp(s.length(), vector<int>(s.length(), -1));
        return helper(s, 0, s.length() - 1, dp);
    }
};