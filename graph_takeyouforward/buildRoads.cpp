// https://www.youtube.com/watch?v=57uBbR5vRvw
// https://cses.fi/problemset/task/1666/

#include <bits/stdc++.h>
using namespace std;

void dfs(int i, vector<vector<int>> &adj, vector<int> &vis)
{
    vis[i] = 1;
    for (auto it : adj[i])
    {
        if (vis[it] == 0)
            dfs(it, adj, vis);
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<int> comp;
    int ans = 0;
    vector<int> vis(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == 0)
        {
            ans++;
            comp.push_back(i);
            dfs(i, adj, vis);
        }
    }
    cout << ans - 1 << endl;
    int len = comp.size();
    for (int i = 0; i < len - 1; i++)
    {
        cout << comp[i] << " " << comp[i + 1];
        if (i != len - 2)
            cout << endl;
    }
}