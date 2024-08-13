// https://cses.fi/problemset/task/1669/
// https://www.youtube.com/watch?v=qYyyj2SRsRc

#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
#define int long long int

int n, m;
int sv, ev;
vector<vector<int>> g;
vector<int> vis;
vector<int> parent;

bool dfs(int u, int p)
{
    vis[u] = true;
    parent[u] = p;

    for (auto v : g[u])
    {
        if (v == p)
            continue;

        if (vis[v])
        {
            sv = v;
            ev = u;
            return true;
        }

        if (!vis[v])
        {
            if (dfs(v, u))
            {
                return true;
            }
        }
    }
    return false;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    g.resize(n + 1);
    vis.resize(n + 1, 0);
    parent.resize(n + 1, -1);

    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    bool cycle_found = false;
    for (int i = 1; i <= n; ++i)
    {
        if (!vis[i])
        {
            if (dfs(i, -1))
            {
                cycle_found = true;
                break;
            }
        }
    }

    if (!cycle_found)
    {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    int tv = ev;
    vector<int> ans;
    ans.push_back(ev);

    while (tv != sv)
    {
        ans.push_back(parent[tv]);
        tv = parent[tv];
    }
    ans.push_back(ev);

    cout << ans.size() << endl;
    for (auto c : ans)
    {
        cout << c << " ";
    }
    cout << endl;

    return 0;
}

///

#include <bits/stdc++.h>
using namespace std;

bool dfs(int src, int parent, vector<int> &s, vector<int> &vis, vector<vector<int>> &graph, vector<int> &cycle)
{
    vis[src] = 1;
    s.push_back(src);
    for (auto &x : graph[src])
    {
        if (vis[x] == 0)
        {
            if (dfs(x, src, s, vis, graph, cycle))
            {
                return true;
            }
        }
        else if (vis[x] == 1)
        {
            if (x != parent)
            {
                cycle.push_back(x);
                int pos = s.size() - 1;
                while (pos >= 0 && s[pos] != x)
                {
                    cycle.push_back(s[pos]);
                    --pos;
                }
                cycle.push_back(x);
                return true;
            }
        }
    }
    vis[src] = 2;
    s.pop_back();
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
    vector<int> s;
    vector<int> cycle;

    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == 0)
        {
            if (dfs(i, -1, s, vis, adj, cycle))
            {
                break;
            }
        }
    }

    if (cycle.empty())
    {
        cout << "IMPOSSIBLE" << endl;
    }
    else
    {
        cout << cycle.size() << endl;
        for (int i = cycle.size() - 1; i >= 0; i--)
        {
            cout << cycle[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
