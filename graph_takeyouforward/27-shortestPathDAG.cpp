// https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=shortest-path-in-undirected-graph

// bfs

vector<int> shortestPath(int n, int m, vector<vector<int>> &edges)
{
    // code here
    vector<int> ans(n, INT_MAX);
    ans[0] = 0;
    queue<pair<int, int>> q;
    vector<vector<int>> adj[n];
    for (int i = 0; i < m; i++)
    {
        adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
    }
    q.push({0, 0});
    while (!q.empty())
    {
        int node = q.front().first;
        int val = q.front().second;
        q.pop();
        for (auto it : adj[node])
        {
            int next = it[0];
            int wt = it[1];
            if (val + wt < ans[next])
            {
                q.push({next, val + wt});
                ans[next] = min(ans[next], val + wt);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (ans[i] == INT_MAX)
            ans[i] = -1;
    }
    return ans;
}

// toposort

void topo(int start, vector<pair<int, int>> adj[], int vis[], stack<int> &s)
{
    vis[start] = 1;
    for (auto it : adj[start])
    {
        int node = it.first;
        if (vis[node] == 0)
        {
            topo(node, adj, vis, s);
        }
    }
    s.push(start);
}

vector<int> shortestPath(int N, int M, vector<vector<int>> &edges)
{
    // code here
    vector<pair<int, int>> adj[N];
    for (int i = 0; i < M; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];
        adj[u].push_back({v, w});
    }
    int vis[N] = {0};
    stack<int> s;
    for (int i = 0; i < N; i++)
    {
        if (vis[i] == 0)
        {
            topo(i, adj, vis, s);
        }
    }
    vector<int> dist(N);
    for (int i = 0; i < N; i++)
    {
        dist[i] = 1e9;
    }
    int initial = 0;
    dist[initial] = 0;
    while (!s.empty())
    {
        int node = s.top();
        s.pop();
        for (auto it : adj[node])
        {
            int point = it.first;
            int wt = it.second;
            if (dist[node] + wt < dist[point])
            {
                dist[point] = dist[node] + wt;
            }
        }
    }
    for (int i = 0; i < N; i++)
    {
        if (dist[i] == 1e9)
        {
            dist[i] = -1;
        }
    }
    return dist;
}

// Why Topological Sort : In previous approach source(u) se kisi node(v) tak
// pahuchane ke multiple paths ho skte he par optimal path konsa hoga, ye nhi
// pata....  isliye ham saare paths se cost nikal rhe the aur optimal cost update
// kar rhe the. So agar hme ye pata chal jaye ki node(u) se node(v) tak jane ke
// jitne bhi paths he wo paths ke sare nodes agar ham node(v) tak pahuchne se
// pahle hi mil jaye so that ham node(v) jab par pahuchege to sare paths ke
// nodes ka process kar chuke ho. To esa order , Topological Sort se milata he.