// https://cses.fi/problemset/task/1673/
// https://www.youtube.com/watch?v=2Epc8xZObIc

#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
#define int long long int

const int INF = 1e17;
const int NINF = INF * (-1);

int n, m;
vector<vector<int>> edges;
vector<int> dist;

void bellman_ford()
{
    // here n iterations bcoz of possibility of self cycle
    for (int i = 1; i <= n; ++i)
    {
        for (auto &e : edges)
        {
            int u = e[0];
            int v = e[1];
            int d = e[2];
            if (dist[u] == INF)
                continue;
            dist[v] = min(dist[v], d + dist[u]);
            dist[v] = max(dist[v], NINF);
        }
    } // n relaxations                // standard part to get shortest distance

    for (int i = 1; i <= n; ++i)    // here slight varation from standard
    {                              // instead of checking one time for negative cycle, n-1 iterations to make dist of v as NINF
        for (auto &e : edges)      // NINF denotes that is in negative cycle
        {                          // whenever dist is came smaller than previous n-1 iterations, means negative cycle's edge if found
            int u = e[0];          // we are not directly checking for negative cycle bcoz even if there is negative cycle at part of graph
            int v = e[1];          // there might be possible to reach from node 1 to n by avoiding negative cycle's path
            int d = e[2];
            if (dist[u] == INF)
                continue;
            dist[v] = max(dist[v], NINF);
            if (dist[u] + d < dist[v])
            {
                dist[v] = NINF;
            }
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    dist.resize(n + 1);
    edges.resize(m, vector<int>(3)); // Resize edges to hold m vectors of 3 integers each
    for (int i = 0; i < m; ++i)
    {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
        edges[i][2] *= -1; // Invert the weight
    }

    for (int i = 2; i <= n; ++i)
    {
        dist[i] = INF;
    }

    bellman_ford();
    if (dist[n] == NINF)
    {
        cout << -1 << endl;
        return 0;
    }
    cout << dist[n] * (-1) << endl;
}
