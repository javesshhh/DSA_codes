// https://leetcode.com/problems/rotate-array/description/

class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        int n = nums.size();
        if (n == 1 || k == 0)
        {
            return;
        }
        k = k % n;
        int ind = n - k - 1;
        int i = 0;
        int j = ind;
        while (i < j)
        {
            swap(nums[i], nums[j]);
            i++;
            j--;
        }
        i = ind + 1;
        j = n - 1;
        while (i < j)
        {
            swap(nums[i], nums[j]);
            i++;
            j--;
        }
        i = 0;
        j = n - 1;
        while (i < j)
        {
            swap(nums[i], nums[j]);
            i++;
            j--;
        }
        return;
    }
};