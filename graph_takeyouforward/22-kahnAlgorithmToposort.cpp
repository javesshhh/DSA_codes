// https://www.geeksforgeeks.org/problems/topological-sort/1

#include <bits/stdc++.h>
using namespace std;

vector<int> topoSort(int V, vector<int> adj[])
{
	// code here
	queue<int> q;
	int indegree[V] = {0};
	for (int i = 0; i < V; i++)
	{
		for (auto it : adj[i])
		{
			indegree[it]++;
		}
	}
	for (int i = 0; i < V; i++)
	{
		if (indegree[i] == 0)
		{
			q.push(i);
		}
	}
	vector<int> ans;
	while (!q.empty())
	{
		int node = q.front();
		q.pop();
		ans.push_back(node);
		for (auto adjnode : adj[node])
		{
			indegree[adjnode]--;
			if (indegree[adjnode] == 0)
			{
				q.push(adjnode);
			}
		}
	}
	return ans;
}

int main()
{
}