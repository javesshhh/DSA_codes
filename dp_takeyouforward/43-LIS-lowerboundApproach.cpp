// https://www.youtube.com/watch?v=on2hvxBXJH4&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=45&ab_channel=takeUforward
// https://leetcode.com/problems/longest-increasing-subsequence/description/

class Solution
{
public:
    int lengthOfLIS(vector<int> &a)
    {
        vector<int> lis;
        int n = a.size();
        lis.push_back(a[0]);
        for (int i = 1; i < n; i++)
        {

            if (a[i] > lis.back())
            {
                lis.push_back(a[i]);
            }
            else
            {
                auto it = lower_bound(lis.begin(), lis.end(), a[i]);                  // returns an iterator pointing to the next smallest-
                *it = a[i];                                                           // -number just greater than or equal to that number.
            }
        }
        return lis.size();
    }
};