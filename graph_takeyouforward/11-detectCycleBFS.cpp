// https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=detect-cycle-in-an-undirected-graph

#include <bits/stdc++.h>
using namespace std;

bool detectCycle(int node, int vertices, vector<int> adj[], int vis[])
{
    vis[node] = 1;
    queue<pair<int, int>> q;
    q.push({node, -1});
    while (!q.empty()){
        int child = q.front().first;
        int parent = q.front().second;
        q.pop();
        for (auto adjnode : adj[child]){
            if (vis[adjnode] == 0){
                vis[adjnode]=1;
                q.push({adjnode,child});
            }
            else if(parent!=adjnode){
                return true;
            }
        }
    }
    return false;
}

// Function to detect cycle in an undirected graph.
bool isCycle(int V, vector<int> adj[])
{
    int vis[V] = {0};
    vis[0] = 1;
    for (int i = 0; i < V; i++)
    {
        if (vis[i] == 0)
        {
            if (detectCycle(i,V,adj,vis) == true)
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
}