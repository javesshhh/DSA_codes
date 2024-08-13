// https://www.geeksforgeeks.org/problems/shortest-path-in-weighted-undirected-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=shortest-path-in-weighted-undirected-graph

#include <bits/stdc++.h>
using namespace std;

vector<int> shortestPath(int n, int m, vector<vector<int>> &edges)
{
    // Code here
    vector<pair<int, int>> adj[n + 1];
    for (int i = 0; i < m; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({0, 1});
    vector<int> dist(n + 1, INT_MAX);
    dist[1] = 0;
    vector<int> par(n + 1);
    for (int i = 1; i <= n; i++)
    {
        par[i] = i;
    }
    while (!q.empty())
    {
        int node = q.top().second;
        int dis = q.top().first;
        q.pop();
        for (auto it : adj[node])
        {
            int nxt = it.first;
            int wt = it.second;
            if (dist[nxt] > dis + wt)
            {
                dist[nxt] = dis + wt;
                q.push({dis + wt, nxt});
                par[nxt] = node;
            }
        }
    }
    if (dist[n] == INT_MAX)
        return {-1};
    vector<int> ans;
    ans.push_back(n);
    int parent = par[n];
    while (parent != 1)
    {
        ans.push_back(parent);
        parent = par[parent];
    }
    ans.push_back(1);
    ans.push_back(dist[n]);
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
}