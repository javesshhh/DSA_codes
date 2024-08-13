// https://leetcode.com/problems/longest-repeating-character-replacement/description/

class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        unordered_map<char, int> m;
        int ans = -1;
        int i = 0, j = 0;
        int temp = -1;
        while (j < s.length())
        {
            m[s[j]]++;
            temp = max(temp, m[s[j]]);
            if (j - i + 1 - temp > k)
            {
                m[s[i]]--;
                i++;
            }
            ans = max(ans, j - i + 1);
            j++;
        }
        return ans;
    }
};