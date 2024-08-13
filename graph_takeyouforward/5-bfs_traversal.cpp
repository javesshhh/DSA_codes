// https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=bfs_of_graph

#include <bits/stdc++.h>
using namespace std;

// Function to return Breadth First Traversal of given graph.
vector<int> bfsOfGraph(int V, vector<int> adj[])
{
    // Code here
    int vis[V] = {0};
    queue<int> q;
    q.push(0);
    vis[0] = 1;
    vector<int> v;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        v.push_back(node);
        for (auto it : adj[node])
        {
            if (vis[it] == 0)
            {
                q.push(it);
                vis[it] = 1;
            }
        }
    }
    return v;
}

// space complexity = vector v + queue q + vis array = V +V +V = O(3V)=O(V)
// time complexity = for loop runs for all neighbours of nodes and while runs till queue is empty for all nodes
//                   O(2*edges)   +     O(nodes)    =   O(2E)+O(V)   =  O(E+V)

int main()
{
}