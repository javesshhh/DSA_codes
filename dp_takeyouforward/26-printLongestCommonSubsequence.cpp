// https://www.youtube.com/watch?v=-zI4mrF2Pb4&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=27&ab_channel=takeUforward
// https://www.youtube.com/watch?v=x5hQvnUcjiM&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=24&ab_channel=AdityaVerma
// https://practice.geeksforgeeks.org/problems/print-all-lcs-sequences3413/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=print-all-lcs-sequences

// when we have to  print any of the longest common subsequence

int longestCommonSubsequence(string text1, string text2)
{
    int l1 = text1.length(), l2 = text2.length();
    int dp[l1 + 1][l2 + 1];

    for (int i = 0; i <= l1; i++)
    {
        for (int j = 0; j <= l2; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;

            else if (text1[i - 1] == text2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];

            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    // Now to print the sequence, we go through the array
    int i = l1, j = l2;

    while (i > 0 && j > 0)
    {
        if (text1[i - 1] == text2[j - 1])
        {
            cout << text1[i - 1];
            i--;
            j--;
        }

        else
        {
            if (dp[i - 1][j] <= dp[i][j - 1])
            {
                j--;
            }
            else
                i--;
        }
    }
}

// but in above prooblem, we have to print all longest common subsequences

class Solution
{
public:
    int Lcs(string s, string t)
    {

        int n = s.size();

        int m = t.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 0; i <= n; i++)
        {

            for (int j = 0; j <= m; j++)
            {
                if (i == 0 || j == 0)
                    dp[i][j] = 0;

                else if (s[i - 1] == t[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];

                else
                {

                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[n][m];
    }

    set<string> st;

    void solve(string s, string t, int i, int j, string &temp, vector<string> &ans, int count)
    {

        if (count == 0)
        {

            if (st.find(temp) == st.end())
            {

                st.insert(temp);

                ans.push_back(temp);
            }

            return;
        }

        if (i >= s.size() || j >= t.size())
            return;

        for (int r = i; r < s.size(); r++)
        {

            for (int c = j; c < t.size(); c++)
            {

                if (s[r] == t[c])
                {

                    temp.push_back(s[r]);

                    solve(s, t, r + 1, c + 1, temp, ans, count - 1);

                    temp.pop_back();
                }
            }
        }
    }

    vector<string> all_longest_common_subsequences(string s, string t)

    {

        // Code here

        int cnt = Lcs(s, t);

        vector<string> ans;

        string temp = "";

        solve(s, t, 0, 0, temp, ans, cnt);

        sort(ans.begin(), ans.end());

        return ans;
    }
};
