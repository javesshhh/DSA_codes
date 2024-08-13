// https://www.interviewbit.com/problems/3-sum/
// https://www.youtube.com/watch?v=n-JNgynPi6Q&t=309s
// https://leetcode.com/problems/3sum-closest/solutions/4661829/best-c-solution
// https://leetcode.com/problems/3sum-closest/description/

int Solution::threeSumClosest(vector<int> &nums, int target)
{
    sort(nums.begin(), nums.end());
    long long int diff = INT_MAX;
    long long int result = 0;
    for (int i = 0; i < nums.size() - 2; i++)
    {
        int j = i + 1;
        int k = nums.size() - 1;
        while (j < k)
        {
            long long int sum = nums[i] + nums[j] + nums[k];
            if (sum == target)
            {
                return sum;
            }
            else if (abs(sum - target) < abs(diff))
            {
                diff = sum - target;
                result = sum;
            }
            if (sum > target)
            {
                k--;
            }
            else
            {
                j++;
            }
        }
    }
    return result;
}
