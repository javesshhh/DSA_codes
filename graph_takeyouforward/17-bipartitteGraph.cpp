// https://leetcode.com/problems/is-graph-bipartite/description/

// linear graphs ✅
// cyclic graph with even cycle length ✅

class Solution
{
public:
    bool bfs(int start, int V, vector<vector<int>> &adj, int color[])
    {
        queue<int> q;
        q.push(start);
        color[start] = 0;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            for (auto adjnode : adj[node])
            {
                if (color[node] == 0 && color[adjnode] == -1)
                {
                    color[adjnode] = 1;
                    q.push(adjnode);
                }
                else if (color[node] == 1 && color[adjnode] == -1)
                {
                    color[adjnode] = 0;
                    q.push(adjnode);
                }
                else if (color[node] == color[adjnode])
                {
                    return false;
                }
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>> &adj)
    {
        int V = adj.size();
        int color[V];
        for (int i = 0; i < V; i++)
        {
            color[i] = -1;
        }
        for (int i = 0; i < V; i++)
        {
            if (color[i] == -1)
            {
                if (bfs(i, V, adj, color) == false)
                {
                    return false;
                }
            }
        }
        return true;
    }
};