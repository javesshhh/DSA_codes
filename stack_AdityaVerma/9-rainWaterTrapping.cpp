// https://www.youtube.com/watch?v=FbGG2qpNp4U&list=PL_z_8CaSLPWdeOezg68SKkeLN4-T_jNHd&index=9&ab_channel=AdityaVerma
// https://leetcode.com/problems/trapping-rain-water/description/

class Solution
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size();
        vector<int> r(n, -1);
        int mx = height[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            mx = max(mx, height[i + 1]);
            if (mx > height[i])
            {
                r[i] = (mx);
            }
            else
            {
                r[i] = (-1);
            }
        }
        vector<int> l(n, -1);
        int mxx = height[0];
        for (int i = 1; i < n; i++)
        {
            mxx = max(mxx, height[i]);
            if (mxx > height[i])
            {
                l[i] = (mxx);
            }
            else
            {
                l[i] = (-1);
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (r[i] != -1 && l[i] != -1)
            {
                ans = ans + min(l[i], r[i]) - height[i];
            }
        }
        return ans;
    }
};