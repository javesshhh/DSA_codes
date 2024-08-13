// https://cses.fi/problemset/task/1667/

#include <bits/stdc++.h>
using namespace std;

vector<int> par;
vector<int> ans;

bool bfs(int i, vector<vector<int>> &adj, vector<int> &vis, int n)
{
    queue<int> q;
    q.push(i);
    vis[i] = 1;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        if (node == n)
        {
            while (node != 1)
            {
                ans.push_back(node);
                node = par[node];
            }
            ans.push_back(1); // Push the start node as well
            return true;
        }
        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                q.push(it);
                vis[it] = 1;
                par[it] = node;
            }
        }
    }
    return false;
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
    vector<int> vis(n + 1, 0);
    par.resize(n + 1, -1);

    if (bfs(1, adj, vis, n))
    {
        cout << ans.size() << endl;
        reverse(ans.begin(), ans.end());
        for (int i : ans)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "IMPOSSIBLE" << endl;
    }
}
