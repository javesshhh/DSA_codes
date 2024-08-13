#include <bits/stdc++.h>
using namespace std;

void fn(int node, vector<vector<int>> &adj, vector<int> &val, int &mx)
{
    queue<pair<int, int>> q;
    q.push({node, max(0, val[node])});
    while (!q.empty())
    {
        int i = q.front().first;
        int cur = q.front().second;
        q.pop();
        mx = max(mx, cur);
        for (auto it : adj[i])
        {
            if (cur + val[it] >= 0)
                q.push({it, cur + val[it]});
            else
                q.push({it, 0});
        }
    }
}

int main()
{
    // Directed tree structure
    vector<vector<int>> adj(6);
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(3);
    adj[1].push_back(4);
    adj[2].push_back(5);

    // Example values associated with each node
    vector<int> val = {-1, 2, 3, -12, -1, 2}; // Values for nodes 0, 1, 2, 3, 4, and 5 respectively

    int mx = INT_MIN;
    fn(0, adj, val, mx);

    cout << "Maximum value: " << mx << endl;

    return 0;
}
