// https://www.geeksforgeeks.org/problems/mobile-numeric-keypad5456/1
// https://www.youtube.com/watch?v=xaKENHcJts4&ab_channel=Yogesh%26Shailesh%28CodeLibrary%29

public:
    vector<vector<int>> a = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {-1, 0, -1}};
long long dp[4][3][26];

long long fn(int i, int j, int n)
{
    if (n == 1)
    {
        return 1;
    }
    if (dp[i][j][n] != -1)
    {
        return dp[i][j][n];
    }
    long long ans = 0;

    ans += fn(i, j, n - 1);
    if (j + 1 < 3 && a[i][j + 1] != -1)
        ans += fn(i, j + 1, n - 1);
    if (j - 1 >= 0 && a[i][j - 1] != -1)
        ans += fn(i, j - 1, n - 1);
    if (i + 1 < 4 && a[i + 1][j] != -1)
        ans += fn(i + 1, j, n - 1);
    if (i - 1 >= 0 && a[i - 1][j] != -1)
        ans += fn(i - 1, j, n - 1);

    return dp[i][j][n] = ans;
}
long long getCount(int n)
{
    memset(dp, -1, sizeof(dp));
    long long anss = 0;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (a[i][j] != -1)
                anss += fn(i, j, n);
        }
    }

    return anss;
}