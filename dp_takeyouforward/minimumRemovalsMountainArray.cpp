// similar to https://www.youtube.com/watch?v=y4vN0WNdrlg&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=47&ab_channel=takeUforward
// https://leetcode.com/problems/minimum-number-of-removals-to-make-mountain-array/description/

// bitonic array and mountain array are different
// bitonic array can be completely increasing or completely decreasing or can be both i.e. mountain array
// mountain array should be first inc then dec,  therefore last condition is v1[i]>1 and v2[i]>1

class Solution
{
public:
    int minimumMountainRemovals(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> v1(n, 1);
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[j] < nums[i])
                {
                    v1[i] = max(v1[i], v1[j] + 1);
                }
            }
        }
        // int n = nums.size();
        vector<int> v2(n, 1);
        for (int i = n - 2; i >= 0; i--)
        {
            for (int j = n - 1; j > i; j--)
            {
                if (nums[j] < nums[i])
                {
                    v2[i] = max(v2[i], v2[j] + 1);
                }
            }
        }
        int ans = -1;
        for (int i = 1; i < n - 1; i++)
        {
            if (v1[i] > 1 && v2[i] > 1)
            { // if length of lis from left and right > 1 than update ans
                ans = max(ans, v1[i] + v2[i] - 1);
            }
        }
        return n - ans;
    }
};