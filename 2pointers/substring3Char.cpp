// https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/description/
// https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/solutions/3459766/explained-w-images-made-easy-c

class Solution
{
public:
    int numberOfSubstrings(string s)
    {
        int a = 0, b = 0, c = 0;
        int i = 0;
        int j = 0;
        int ans = 0;
        int n = s.length();

        while (i < n)
        {
            while ((a < 1 || b < 1 || c < 1) && j < n)
            {
                if (s[j] == 'a')
                    a++;
                else if (s[j] == 'b')
                    b++;
                else if (s[j] == 'c')
                    c++;
                j++;
            }

            if (a >= 1 && b >= 1 && c >= 1)
            {
                ans += (n - j + 1);
            }

            if (s[i] == 'a')
                a--;
            else if (s[i] == 'b')
                b--;
            else if (s[i] == 'c')
                c--;
            i++;
        }

        return ans;
    }
};
