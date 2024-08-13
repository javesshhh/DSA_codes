// https://www.geeksforgeeks.org/problems/topological-sort/1

// directed acyclic graph ✅

#include <bits/stdc++.h>
using namespace std;

void dfs(int start, int V, vector<int> adj[], int vis[], stack<int> &s)
{
	vis[start] = 1;
	for (auto adjnode : adj[start])
	{
		if (vis[adjnode] == 0)
		{
			dfs(adjnode, V, adj, vis, s);
		}
	}
	s.push(start);
}

// Function to return list containing vertices in Topological order.
vector<int> topoSort(int V, vector<int> adj[])
{
	// code here
	int vis[V] = {0};
	stack<int> s;
	for (int i = 0; i < V; i++)
	{
		if (vis[i] == 0)
		{
			dfs(i, V, adj, vis, s);
		}
	}
	vector<int> ans;
	while (!s.empty())
	{
		ans.push_back(s.top());
		s.pop();
	}
	return ans;
}

int main()
{
}