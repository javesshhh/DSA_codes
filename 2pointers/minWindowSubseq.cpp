// https://www.geeksforgeeks.org/problems/minimum-window-subsequence/0
// https://www.youtube.com/watch?v=B6scRxy_Zwo&ab_channel=CodebyVANSH

class Solution
{
public:
    string minWindow(string s, string t)
    {
        // Write your Code here
        int n = s.size(), m = t.size();
        int i = 0, j = 0, k = 0;
        string ans;
        int sz = 1e9;
        for (i = 0, j = 0; i < n && k < m;)
        {
            if (s[i] == t[k])
            {
                k++;
            }

            // fixing end point
            if (k == m)
            {
                j = i;
                k = m - 1;

                // minimising our starting point
                while (k >= 0 && j >= 0)
                {
                    if (s[j] == t[k])
                        k--;
                    j--;
                }
                j++;

                // now this can be our substring i.e. s[j..i]
                if (sz > (i - j + 1))
                {
                    sz = i - j + 1;
                    ans = s.substr(j, sz);
                }
                i = j;
                k = 0;
            }
            i++;
        }
        return ans;
    }
};