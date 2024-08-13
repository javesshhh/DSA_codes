// https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/solutions/3491274/easy-explanation-two-pointers-cpp-java-python-javascript/?languageTags=cpp
// https://www.youtube.com/watch?v=sjS_TzEgxZA&ab_channel=CodeFreaks
// https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/description/

// For each pair of indices (left, right), if nums[left] + nums[right] <= target,
// then count all the subsequences of nums that can be formed using the elements
// from nums[left+1] to nums[right], and add it to the final result.
// Left+1 bczz we have to always include the left element i.e. smallest element to satisfy sum condition
// we can use the formula 2^(right-left), because for each element in this range, we can either
// choose to include it or exclude it from the subsequence, thus giving us 2 choices, and
// we have (right-left) such elements
// For clarity, refer video

class Solution
{
public:
    int numSubseq(vector<int> &nums, int target)
    {
        const int mod = 1e9 + 7;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int left = 0, right = nums.size() - 1;
        int result = 0;
        int pows[n];
        pows[0] = 1;
        for (int i = 1; i < n; ++i)
            pows[i] = (pows[i - 1] * 2) % mod;
        while (left <= right)
        {
            if (nums[left] + nums[right] <= target)
            {
                result = (result + pows[right - left]) % mod;
                left++;
            }
            else
            {
                right--;
            }
        }
        return result;
    }
};