// https://leetcode.com/problems/redundant-connection/

class Solution
{
public:
    vector<int> findRedundantConnection(vector<vector<int>> &edges)
    {
        int n = edges.size();
        vector<int> indegree(n + 1, 0);
        vector<vector<int>> graph(n + 1);
        int m = 0;
        for (auto &x : edges)
        {
            indegree[x[0]]++;
            indegree[x[1]]++;
            graph[x[0]].push_back(x[1]);
            graph[x[1]].push_back(x[0]);
        }

        queue<int> q;
        for (int i = 0; i < n + 1; i++)
        {
            if (indegree[i] == 1)
            {
                q.push(i);
            }
        }

        while (!q.empty())
        {
            int curr = q.front();
            q.pop();
            for (auto &x : graph[curr])
            {
                indegree[x]--;
                if (indegree[x] == 1)
                {
                    q.push(x);
                }
            }
        }

        unordered_set<int> s;
        for (int i = 0; i < n + 1; i++)
        {
            if (indegree[i] > 1)
                s.insert(i);
        }

        vector<int> res;
        for (auto &x : edges)
        {
            if (s.find(x[0]) != s.end() && s.find(x[1]) != s.end())
            {
                res = {x[0], x[1]};
                // break;
            }
        }

        return res;
    }
};