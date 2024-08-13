// https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/description/

class Solution
{
public:
    bool check(vector<int> &A)
    {
        int k = 0, n = A.size();
        for (int i = 0; i < n; ++i)
        {
            if (A[i] > A[(i + 1) % n])
            {
                k++;
            }
            if (k > 1)
            {
                return false;
            }
        }
        return true;
    }
};