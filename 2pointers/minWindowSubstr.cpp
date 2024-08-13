// https://leetcode.com/problems/minimum-window-substring/description/
// https://www.youtube.com/watch?v=WJaij9ffOIY&ab_channel=takeUforward

class Solution
{
public:
    std::string minWindow(std::string s, std::string t)
    {
        if (s.empty() || t.empty() || s.length() < t.length())
        {
            return "";
        }

        std::vector<int> map(128, 0);
        int count = t.length();
        int start = 0, end = 0, minLen = INT_MAX, startIndex = 0;
        for (char c : t)
        {
            map[c]++;
        }

        while (end < s.length())
        {
            if (map[s[end]] > 0)
            {
                count--;
            }
            map[s[end]]--;
            end++;

            while (count == 0)
            {
                if (end - start < minLen)
                {
                    startIndex = start;
                    minLen = end - start;
                }

                map[s[start]]++;
                if (map[s[start]] > 0)
                {
                    count++;
                }
                start++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(startIndex, minLen);
    }
};
