// https://www.youtube.com/watch?v=SqA0o-DGmEw&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=40&ab_channel=AdityaVerma
// https://leetcode.com/problems/scramble-string/
// https://www.interviewbit.com/problems/scramble-string/

// recursion

class Solution
{
public:
    bool fn(string s1, string s2)
    {
        if (s1 == s2)
        {
            return true;
        }
        if (s1.length() <= 1 || s2.length() <= 1)
        {
            return false;
        }
        bool ans = false;
        int n = s1.length();
        for (int i = 1; i <= n - 1; i++)
        {
            if (fn(s1.substr(0, i), s2.substr(0, i)) == true && fn(s1.substr(i, n - i), s2.substr(i, n - i)) == true)
            {
                ans = true;
                break;
            }
            if (fn(s1.substr(0, i), s2.substr(n - i, i)) == true && fn(s1.substr(i, n - i), s2.substr(0, n - i)) == true)
            {
                ans = true;
                break;
            }
        }
        return ans;
    }

    bool isScramble(string s1, string s2)
    {
        if (s1.length() != s2.length())
        {
            return false;
        }
        if (s1.length() == 0 && s2.length() == 0)
        {
            return false;
        }
        return fn(s1, s2);
    }
};

// memoization
// https://www.youtube.com/watch?v=VyHEglhbm-A&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=41&ab_channel=AdityaVerma

class Solution
{
public:
    bool fn(string s1, string s2, unordered_map<string, int> &mp)
    {
        if (s1 == s2)
        {
            return true;
        }
        if (s1.length() <= 1 || s2.length() <= 1)
        {
            return false;
        }
        string s = "";
        s = s1 + " " + s2;
        if (mp.find(s) != mp.end())
        {
            return mp[s];
        }
        bool ans = false;
        int n = s1.length();
        for (int i = 1; i <= n - 1; i++)
        {
            if (fn(s1.substr(0, i), s2.substr(0, i), mp) == true && fn(s1.substr(i, n - i), s2.substr(i, n - i), mp) == true)
            {
                ans = true;
                break;
            }
            if (fn(s1.substr(0, i), s2.substr(n - i, i), mp) == true && fn(s1.substr(i, n - i), s2.substr(0, n - i), mp) == true)
            {
                ans = true;
                break;
            }
        }
        return mp[s] = ans;
    }

    bool isScramble(string s1, string s2)
    {
        if (s1.length() != s2.length())
        {
            return false;
        }
        if (s1.length() == 0 && s2.length() == 0)
        {
            return false;
        }
        unordered_map<string, int> mp;
        return fn(s1, s2, mp);
    }
};