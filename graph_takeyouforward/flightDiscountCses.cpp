https://cses.fi/problemset/task/1195
// https://www.youtube.com/watch?v=GZtZXhir7Wg&t=7s


#include <bits/stdc++.h>
using namespace std;
// #define long long  long long

long long ans = LLONG_MAX;

void fn(long long st, vector<vector<pair<long long, long long>>> &adj, long long end)
{
    priority_queue<pair<long long, pair<long long, bool>>, vector<pair<long long, pair<long long, bool>>>, greater<pair<long long, pair<long long, bool>>>> q;
    vector<vector<long long>> dist(end + 1, vector<long long>(2, LLONG_MAX));
    // vector<vector<long long >>dist
    // for (long long  i = 1; i < end + 1; i++)
    // {
    //     dist[i] = 1e9;
    // }
    q.push({0, {st, false}});
    dist[st][0] = 0;
    dist[st][1] = 0;
    while (!q.empty())
    {
        long long cost = q.top().first;
        long long node = q.top().second.first;
        bool coupon = q.top().second.second;
        q.pop();
        if (node == end)
        {
            ans = min<long long>(ans, cost);
            continue;
        }
        if (coupon == true)
        {
            if (dist[node][1] < cost)
                continue;
        }
        if (coupon == false)
        {
            if (dist[node][0] < cost)
                continue;
        }
        // Avoiding Redundant Processing:

        // When a node is dequeued from the priority queue, this block checks if the cost
        // associated with the node is greater than the already recorded
        // minimum cost (dist[node][1] or dist[node][0], depending on whether the coupon has been used or not).
        // If the current cost (cost) is greater than the stored minimum
        // cost (dist[node][1] or dist[node][0]), it means a better (shorter) path to this
        // node has already been found and processed. Therefore, there's no need to process
        // this node again, and the algorithm can continue to the next iteration of the loop.

        for (auto it : adj[node])
        {
            if (coupon)
            {
                if (cost + it.second < dist[it.first][1])
                {
                    dist[it.first][1] = cost + it.second;
                    q.push({dist[it.first][1], {it.first, true}});
                }
            }
            else
            {
                if (cost + it.second < dist[it.first][0])
                {
                    dist[it.first][0] = cost + it.second;
                    q.push({dist[it.first][0], {it.first, false}});
                }
                if (cost + (it.second / 2) < dist[it.first][1])
                {
                    dist[it.first][1] = cost + (it.second / 2);
                    q.push({dist[it.first][1], {it.first, true}});
                }
            }
        }
    }
}

signed main()
{
    long long n, m;
    cin >> n >> m;
    vector<vector<pair<long long, long long>>> adj(n + 1);

    for (long long i = 0; i < m; i++)
    {
        long long a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }

    fn(1, adj, n);
    cout << ans << endl;
    return 0;
}