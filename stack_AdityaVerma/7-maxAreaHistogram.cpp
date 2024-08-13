// https://www.youtube.com/watch?v=J2X70jj_I1o&list=PL_z_8CaSLPWdeOezg68SKkeLN4-T_jNHd&index=7&t=117s&ab_channel=AdityaVerma
// https://leetcode.com/problems/largest-rectangle-in-histogram/description/

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

//

class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        int n = heights.size();
        vector<int> nsr(n, 0);
        vector<int> nsl(n, 0);

        stack<int> s;

        for (int i = n - 1; i >= 0; i--)
        {
            while (!s.empty() && heights[i] <= heights[s.top()])
            {
                s.pop();
            }
            if (s.empty())
                nsr[i] = n;
            else
                nsr[i] = s.top();
            s.push(i);
        }

        while (!s.empty())
            s.pop();

        for (int i = 0; i < n; i++)
        {
            while (!s.empty() && heights[i] <= heights[s.top()])
            {
                s.pop();
            }
            if (s.empty())
                nsl[i] = -1;
            else
                nsl[i] = s.top();
            s.push(i);
        }

        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            ans = max(ans, heights[i] * (nsr[i] - nsl[i] - 1));
        }
        return ans;
    }
};