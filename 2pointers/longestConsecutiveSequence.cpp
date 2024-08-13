// https://leetcode.com/problems/longest-consecutive-sequence/description/
// https://takeuforward.org/data-structure/longest-consecutive-sequence-in-an-array/

#pragma GCC optimize("O3", "unroll-loops")
class Solution
{
public:
    int longestConsecutive(vector<int> &v)
    {
        std::ios_base::sync_with_stdio(0);
        cin.tie(0);
        int n = v.size();
        int ans = 0;
        int len = 0;
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;
        sort(v.begin(), v.end());
        for (int i = 0; i < n - 1; ++i)
        {
            if (v[i] + 1 == v[i + 1])
            {
                len++;
                ans = max(ans, len);
            }
            else if (v[i] == v[i + 1])
            {
                continue;
            }
            else
            {
                len = 0;
            }
        }
        return ++ans;
    }
};

//

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        // 1 2 3 4 100 200
        // 0 0 1 2 3 4 5 6 7 8 9
        int ans = 1;
        // int j=1;
        int n = nums.size();
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;
        unordered_set<int> s;
        for (int i = 0; i < n; i++)
        {
            s.insert(nums[i]);
        }
        for (auto i : s)
        {
            if (s.find(i - 1) != s.end())
                continue;
            else
            {
                int len = 1;
                // int k=i;
                while (s.find(i + 1) != s.end())
                {
                    len++;
                    ans = max(ans, len);
                    s.erase(i + 1);
                    i++;
                }
            }
        }
        return ans;
    }
};