// https://leetcode.com/problems/maximum-product-subarray/description/
// https://www.youtube.com/watch?v=hnswaLJvr6g&ab_channel=takeUforward

class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int prefix = 1;
        int suffix = 1;
        int n = nums.size();
        int maxi = INT_MIN;
        for (int i = 0; i < nums.size(); i++)
        {
            if (prefix == 0)
            {
                prefix = 1;
            }
            if (suffix == 0)
            {
                suffix = 1;
            }
            prefix *= nums[i];
            suffix *= nums[n - i - 1]; // to start suffix from the last end
            maxi = max(maxi, max(suffix, prefix));
        }
        return maxi;
    }
};