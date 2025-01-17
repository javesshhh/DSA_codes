// https://leetcode.com/problems/length-of-longest-subarray-with-at-most-k-frequency/?envType=daily-question&envId=2024-03-28

class Solution
{
public:
    int maxSubarrayLength(vector<int> &v, int k)
    {
        int n = v.size();
        map<int, int> m;
        int i = 0, j = 0;
        int ans = 1;
        while (i < n && j < n)
        {
            m[v[j]]++;
            while (m[v[j]] > k)
            {
                m[v[i]]--;
                i++;
            }
            ans = max(ans, j - i + 1);
            j++;
        }
        return ans;
    }
};