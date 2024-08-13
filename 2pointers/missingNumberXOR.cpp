// https://leetcode.com/problems/missing-number/description/
// https://leetcode.com/problems/missing-number/solutions/4754401/beats-98-users-4-approaches-c-java-python-javascript-explained

class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int n = nums.size();
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            ans = ans ^ i;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            ans = ans ^ nums[i];
        }
        return ans;
    }
};
