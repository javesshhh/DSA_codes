#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    // adjacency matrix for undirected graph
    // time complexity: O(n)
    int adj[n+1][n+1];
    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1  // this statement will be removed in case of directed graph
    }
    // space complexity O(n*n)
    // can be improved by list, that is array/vector

    vector<int>a[n+1]; // Now every index is containing an empty vector
    for(int i = 0; i < m; i++)
    {   // for undirected graph
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);             // this statement will be removed in case of directed graph
    }
    // space complexity O(2*edges)  for undirected graph
    // space complexity O(edges)    for directed graph
    return 0;
}