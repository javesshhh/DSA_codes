// https://www.youtube.com/watch?v=_-0mx0SmYxA&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=40&ab_channel=takeUforward
// https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/description/

class Solution
{
public:
    int countPaths(int n, vector<vector<int>> &roads)
    {
        int mod = 1e9 + 7;
        vector<pair<long long, long long>> adj[n];
        for (int i = 0; i < roads.size(); i++)
        {
            adj[roads[i][0]].push_back({roads[i][1], roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0], roads[i][2]});
        }

        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> q;
        q.push({0, 0});
        vector<long long> time(n, LONG_MAX);
        vector<long long> path(n, 0);
        time[0] = 0;
        path[0] = 1;

        while (!q.empty())
        {
            long long tim = q.top().first;
            long long node = q.top().second;
            q.pop();

            for (auto it : adj[node])
            {
                long long wt = it.second;
                long long nxt = it.first;
                if (tim + wt < time[nxt])
                {
                    time[nxt] = tim + wt;
                    q.push({time[nxt], nxt});
                    path[nxt] = path[node];
                }
                else if (tim + wt == time[nxt])
                {
                    path[nxt] = (path[nxt] + path[node]) % mod;
                }
            }
        }

        return path[n - 1];
    }
};
