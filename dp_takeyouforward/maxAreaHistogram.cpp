// https://leetcode.com/problems/largest-rectangle-in-histogram/
// https://www.youtube.com/watch?v=X0X6G-eWgQ8&t=952s&ab_channel=takeUforward
// https://takeuforward.org/data-structure/area-of-largest-rectangle-in-histogram/

class Solution
{
public:
    int largestRectangleArea(vector<int> &v)
    {
        int n = v.size();
        vector<int> sr(n, -1);
        vector<int> sl(n, -1);
        stack<pair<int, int>> sr1;
        sr1.push({v[n - 1], n - 1});
        for (int i = n - 2; i >= 0; i--)
        {
            while (!sr1.empty() && sr1.top().first >= v[i])
            {
                sr1.pop();
            }
            if (sr1.empty())
            {
                sr[i] = -1;
            }
            else
            {
                sr[i] = sr1.top().second;
            }
            sr1.push({v[i], i});
        }
        stack<pair<int, int>> sl2;
        sl2.push({v[0], 0});
        for (int i = 1; i < n; i++)
        {
            while (!sl2.empty() && sl2.top().first >= v[i])
            {
                sl2.pop();
            }
            if (sl2.empty())
            {
                sl[i] = -1;
            }
            else
            {
                sl[i] = sl2.top().second;
            }
            sl2.push({v[i], i});
        }
        int ans = -1;
        for (int i = 0; i < n; i++)
        {
            if (sr[i] != -1 && sl[i] != -1)
            {
                ans = max(ans, (sr[i] - i + i - sl[i] - 1) * v[i]);
            }
            else if (sr[i] == -1)
            {
                ans = max(ans, (i - sl[i] + n - 1 - i) * v[i]);
            }
            else
            {
                ans = max(ans, (sr[i] - i + i) * v[i]);
            }
        }
        return ans;
    }
};