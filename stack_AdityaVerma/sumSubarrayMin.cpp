// https://leetcode.com/problems/sum-of-subarray-minimums/description/
// https://leetcode.com/problems/sum-of-subarray-minimums/solutions/4595335/beats-100-c-java-python-js-explained-with-video-monotonic-stack

// intuition was to d=find the contribution of each element in being minimum in a subarray
// to do so find next smallest on right and left, this element will be minimum inside that range
// With left[i] and right[i] determined, the number of subarrays in which arr[i] is the mini is equal (i - left[i]) * (right[i] - i).

using ll = long long;
const int MOD = 1e9 + 7;

class Solution
{
public:
    int sumSubarrayMins(vector<int> &nums)
    {
        int length = nums.size();
        vector<int> left(length, -1);
        vector<int> right(length, length);
        stack<int> stk;

        for (int i = 0; i < length; ++i)
        {
            while (!stk.empty() && nums[stk.top()] >= nums[i])
            {
                stk.pop();
            }
            if (!stk.empty())
            {
                left[i] = stk.top();
            }
            stk.push(i);
        }

        stk = stack<int>();

        for (int i = length - 1; i >= 0; --i)
        {
            while (!stk.empty() && nums[stk.top()] > nums[i])
            {
                stk.pop();
            }
            if (!stk.empty())
            {
                right[i] = stk.top();
            }
            stk.push(i);
        }

        ll sum = 0;

        for (int i = 0; i < length; ++i)
        {
            sum += static_cast<ll>(i - left[i]) * (right[i] - i) * nums[i] % MOD;
            sum %= MOD;
        }

        return sum;
    }
};