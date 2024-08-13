// https://leetcode.com/problems/merge-sorted-array/description/

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        vector<int> v;
        int i = 0;
        int j = 0;
        while (i < m && j < n)
        {
            if (nums1[i] < nums2[j])
            {
                v.push_back(nums1[i]);
                i++;
            }
            else if (nums1[i] > nums2[j])
            {
                v.push_back(nums2[j]);
                j++;
            }
            else
            {
                v.push_back(nums2[j]);
                j++;
            }
        }
        while (i < m)
        {
            v.push_back(nums1[i]);
            i++;
        }
        while (j < n)
        {
            v.push_back(nums2[j]);
            j++;
        }
        int k = 0;
        for (auto it : v)
        {
            nums1[k] = it;
            k++;
        }
    }
};

// space O(1)

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;
        while (i >= 0 && j >= 0)
        {
            if (nums2[j] > nums1[i])
            {
                nums1[k] = nums2[j];
                k--;
                j--;
            }
            else
            {
                nums1[k] = nums1[i];
                k--;
                i--;
            }
        }
        while (j >= 0)
        {
            nums1[k] = nums2[j];
            j--;
            k--;
        }
        return;
    }
};