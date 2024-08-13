 // https://www.hackerearth.com/problem/algorithm/benny-and-the-broken-odometer/?purpose=login&source=problem-page&update=google
// https://www.youtube.com/watch?v=hxbqUX7IIvw&list=PLJSqVBBfSpyz_Lb0Baqg2V7cjAg3Rz3yz&index=3&ab_channel=ParasSaini

#include <bits/stdc++.h>
using namespace std;

#define int long long int
int dp[11][2][2];

int g(string s, int pos, int tight, int flag)
{
    if (pos == s.length())
    {
        if (flag == 1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else if (dp[pos][tight][flag] != -1)
        return dp[pos][tight][flag];
    else if (tight == 1)
    {
        int res = 0;
        for (int i = 0; i <= s[pos] - '0'; i++)
        {
            int flg = flag;
            if (i == 3)
                flg = 1;
            if (i == s[pos] - '0')
            {
                res = res + g(s, pos + 1, 1, flg);
            }
            else
            {
                res = res + g(s, pos + 1, 0, flg);
            }
        }
        dp[pos][tight][flag] = res;
        return res;
    }
    else if (tight == 0)
    {
        int res = 0;
        for (int i = 0; i <= 9; i++)
        {
            int flg = flag;
            if (i == 3)
                flg = 1;
            res = res + g(s, pos + 1, 0, flg);
        }
        dp[pos][tight][flag] = res;
        return res;
    }
}

signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int l;
        cin >> l;
        // string a=to_string(r);
        string b = to_string(l);
        // memset(dp,-1,sizeof(dp));
        //  int ans1=g(a,0,0,1);
        memset(dp, -1, sizeof(dp));
        int ans2 = g(b, 0, 1, 0);
        cout << l - ans2 << endl;
    }
}