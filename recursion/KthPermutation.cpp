// https://www.youtube.com/watch?v=wT7gcXLYoao&t=5s&ab_channel=takeUforward
// https://leetcode.com/problems/permutation-sequence/description/

class Solution
{
public:
    string getPermutation(int n, int k)
    {
        string s;
        int i = 1;
        while (i <= n)
        {
            s.push_back('0' + i);
            i++;
        }
        sort(s.begin(), s.end());
        string ans;
        k--;
        if (k == 0)
        {
            return s;
        }
        while (next_permutation(s.begin(), s.end()))
        {
            if (k == 1)
            {
                ans = s;
                break;
            }
            k--;
        }
        return ans;
    }
};