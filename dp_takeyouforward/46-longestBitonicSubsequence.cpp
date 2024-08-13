// https://www.youtube.com/watch?v=y4vN0WNdrlg&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=47&ab_channel=takeUforward
// https://practice.geeksforgeeks.org/problems/longest-bitonic-subsequence0824/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=longest-bitonic-subsequence0824

class Solution
{
public:
    int LongestBitonicSequence(vector<int> nums)
    {
        // code here
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
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if(v1[i]>1 && v2[i]>1)
            ans = max(ans, v1[i] + v2[i] - 1);
        }
        return ans;
    }
};