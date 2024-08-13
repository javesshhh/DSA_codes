// https://leetcode.com/problems/max-consecutive-ones-iii/description/

// hint : Basically, in a given window, we can never have > K zeros

class Solution
{
public:
    int longestOnes(vector<int> &nums, int k)
    {
        int i = 0;
        int j = 0;
        int zero = 0;
        int ans = 0;
        while (i < nums.size() && j < nums.size())
        {
            if (nums[j] == 0)
                zero++;
            while (zero > k)
            {
                if (nums[i] == 0)
                {
                    zero--;
                }
                i++;
            }
            ans = max(ans, j - i + 1);
            j++;
        }
        return ans;
    }
};