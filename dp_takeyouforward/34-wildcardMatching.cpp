// https://www.youtube.com/watch?v=ZmlQ3vgAOMo&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=35&ab_channel=takeUforward
// https://leetcode.com/problems/wildcard-matching/

// tried different approach but wrong results

// class Solution {
// public:

//     bool fn(int n1,int n2,string &s,string &p){
//         if(n1==0 && n2==0){
//             return true;
//         }
//         // if((n1==0 && n2!=0) || (n2==0 && n1!=0)){
//         //     return false;
//         // }
//         if(p[n2-1]=='?' && n2-1>=0){
//             return fn(n1-1,n2-1,s,p);
//         }
//         if(s[n1-1]==p[n2-1] && n1-1>=0 && n2-1>=0){
//              return fn(n1-1,n2-1,s,p);
//         }
//         if(p[n2-1]=='*' && n2-1>=0){
//             if(s[n1-1]==p[n2-2] && n1-1>=0 && n2-1>=0){
//                 return fn(n1-1,n2-2,s,p);
//             }
//             else{
//                 return fn(n1-1,n2,s,p);
//             }
//         }
//         return false;
//     }

//     bool isMatch(string s, string p) {
//         int n1=s.size();
//         int n2=p.size();
//         return fn(n1,n2,s,p);
//     }
// };

// recursion

class Solution
{
public:
    bool fn(int n1, int n2, string &s, string &p)
    {
        if (n1 == 0 && n2 == 0)
        {
            return true;
        }
        if ((n2 == 0 && n1 != 0))
        {
            return false;
        }
        if ((n1 == 0 && n2 != 0))
        {
            for (int i = 0; i < n2; i++)
            {
                if (p[i] != '*')
                {
                    return false;
                }
            }
            return true;
        }
        if (p[n2 - 1] == '?' && n2 - 1 >= 0)
        {
            return fn(n1 - 1, n2 - 1, s, p);
        }
        if (s[n1 - 1] == p[n2 - 1] && n1 - 1 >= 0 && n2 - 1 >= 0)
        {
            return fn(n1 - 1, n2 - 1, s, p);
        }
        if (p[n2 - 1] == '*' && n2 - 1 >= 0)
        {
            return fn(n1, n2 - 1, s, p) || fn(n1 - 1, n2, s, p);
        }
        return false;
    }

    bool isMatch(string s, string p)
    {
        int n1 = s.size();
        int n2 = p.size();
        return fn(n1, n2, s, p);
    }
};

// memoization

class Solution
{
public:
    bool fn(int n1, int n2, string &s, string &p, vector<vector<int>> &dp)
    {
        if (n1 == 0 && n2 == 0)
        {
            return true;
        }
        if ((n2 == 0 && n1 != 0))
        {
            return false;
        }
        if ((n1 == 0 && n2 != 0))
        {
            for (int i = 0; i < n2; i++)
            {
                if (p[i] != '*')
                {
                    return false;
                }
            }
            return true;
        }
        if (dp[n1][n2] != -1)
        {
            return dp[n1][n2];
        }
        if (p[n2 - 1] == '?' && n2 - 1 >= 0)
        {
            return dp[n1][n2] = fn(n1 - 1, n2 - 1, s, p, dp);
        }
        if (s[n1 - 1] == p[n2 - 1] && n1 - 1 >= 0 && n2 - 1 >= 0)
        {
            return dp[n1][n2] = fn(n1 - 1, n2 - 1, s, p, dp);
        }
        if (p[n2 - 1] == '*' && n2 - 1 >= 0)
        {
            return dp[n1][n2] = fn(n1, n2 - 1, s, p, dp) || fn(n1 - 1, n2, s, p, dp);
        }
        return false;
    }

    bool isMatch(string s, string p)
    {
        int n1 = s.size();
        int n2 = p.size();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, -1));
        return fn(n1, n2, s, p, dp);
    }
};

// tabulation

class Solution
{
public:
    bool fn(int n1, int n2, string &s, string &p, vector<vector<int>> &dp)
    {
        if (n1 == 0 && n2 == 0)
        {
            return true;
        }
        if ((n2 == 0 && n1 != 0))
        {
            return false;
        }
        if ((n1 == 0 && n2 != 0))
        {
            for (int i = 0; i < n2; i++)
            {
                if (p[i] != '*')
                {
                    return false;
                }
            }
            return true;
        }
        if (dp[n1][n2] != -1)
        {
            return dp[n1][n2];
        }
        if (p[n2 - 1] == '?' && n2 - 1 >= 0)
        {
            return dp[n1][n2] = fn(n1 - 1, n2 - 1, s, p, dp);
        }
        if (s[n1 - 1] == p[n2 - 1] && n1 - 1 >= 0 && n2 - 1 >= 0)
        {
            return dp[n1][n2] = fn(n1 - 1, n2 - 1, s, p, dp);
        }
        if (p[n2 - 1] == '*' && n2 - 1 >= 0)
        {
            return dp[n1][n2] = fn(n1, n2 - 1, s, p, dp) || fn(n1 - 1, n2, s, p, dp);
        }
        return false;
    }

    bool isMatch(string s, string p)
    {
        int n1 = s.size();
        int n2 = p.size();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
        // return fn(n1,n2,s,p,dp);
        for (int j = 1; j <= n1; j++)
        {
            dp[j][0] = false;
        }
        for (int j = 1; j <= n2; j++)
        {
            int res = 1;
            for (int i = 0; i < j; i++)
            {
                if (p[i] != '*')
                {
                    res = 0;
                    break;
                }
            }
            if (res == 1)
                dp[0][j] = true;
            else
            {
                dp[0][j] = false;
            }
        }
        dp[0][0] = true;
        for (int i = 1; i <= n1; i++)
        {
            for (int j = 1; j <= n2; j++)
            {
                if (p[j - 1] == '?')
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else if (s[i - 1] == p[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else if (p[j - 1] == '*')
                {
                    dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
                }
                else
                    dp[i][j] = false;
            }
        }
        return dp[n1][n2];
    }
};