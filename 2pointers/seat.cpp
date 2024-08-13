// https://www.interviewbit.com/problems/seats/
// https://www.youtube.com/watch?v=o6leQnC7qMw&list=PL7JyMDSI2Bfbu68oLUxhY4S-PFhlGyKfX&index=6

// brute
int Solution::seats(string s)
{
    int n = s.length();
    int ans = INT_MAX;
    int x = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'x')
            x++;
    }
    for (int i = 0; i <= n - x; i++)
    {
        int temp = 0;
        int z = i;
        for (int j = 0; j < n; j++)
        {
            if (s[j] == 'x')
            {
                temp += abs(j - z);
                z++;
            }
        }
        ans = min(ans, temp);
    }
    return ans;
}

// time oN , space oN

int Solution::seats(string s)
{
    int n = s.length();
    int ans = INT_MAX;
    int mod = 1e7 + 3;
    int x = 0;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'x')
            v.push_back(i);
    }
    int m = v.size();
    for (int i = 0; i < m; i++)
    {
        x += abs(v[m / 2] - v[i]) - abs(m / 2 - i);
        x = x % mod;
    }
    return x;
}

// time oN , space O1

int Solution::seats(string s)
{
    int n = s.length();
    int ans = INT_MAX;
    int mod = 1e7 + 3;
    int x = 0;
    vector<int> v;
    int l = -1, r = -1;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'x' && l == -1)
            l = i;
        r = i;
    }
    int lp = 0;
    int rp = 0;
    while (l <= r)
    {
        while (l <= r && s[l] == 'x')
        {
            l++;
            lp++;
        }
        while (l <= r && s[r] == 'x')
        {
            r--;
            rp++;
        }
        if (l <= r)
        {
            if (lp > rp)
            {
                x += rp;
                x = x % mod;
                r--;
            }
            else
            {
                x += lp;
                l++;
                x = x % mod;
            }
        }
    }
    return x % mod;
}