// https://www.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=strongly-connected-components-kosarajus-algo

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void dfs(int node, int V, vector<int> adj[], vector<int> &vis, stack<int> &s)
    {
        vis[node] = 1;
        for (auto it : adj[node])
        {
            if (vis[it] == 0)
            {
                dfs(it, V, adj, vis, s);
            }
        }
        s.push(node);
    }

    void dfs1(int node, int V, vector<int> newadj[], vector<int> &vis)
    {
        vis[node] = 1;
        for (auto it : newadj[node])
        {
            if (vis[it] == 0)
            {
                dfs1(it, V, newadj, vis);
            }
        }
    }

    // Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<int> adj[])
    {
        // code here
        vector<int> vis(V, 0);
        stack<int> s;
        for (int i = 0; i < V; i++)
        {
            if (vis[i] == 0)
            {
                dfs(i, V, adj, vis, s);
            }
        }
        vector<int> newadj[V];
        for (int i = 0; i < V; i++)
        {
            for (auto it : adj[i])
            {
                newadj[it].push_back(i);
            }
        }
        for (int i = 0; i < V; i++)
        {
            vis[i] = 0;
        }
        int cnt = 0;
        while (!s.empty())
        {
            int i = s.top();
            s.pop();
            if (vis[i] == 0)
            {
                cnt++;
                dfs1(i, V, newadj, vis);
            }
        }
        return cnt;
    }
};

int main()
{
}