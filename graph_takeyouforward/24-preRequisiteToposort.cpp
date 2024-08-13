#include <bits/stdc++.h>
using namespace std;

bool isPossible(int N, vector<pair<int, int>> &arrow)
{
	// Code here
	vector<int> adj[N];
	for (auto it : arrow)
	{
		adj[it.first].push_back(it.second);
	}
	queue<int> q;
	int indegree[N] = {0};
	for (int i = 0; i < N; i++)
	{
		for (auto it : adj[i])
		{
			indegree[it]++;
		}
	}
	for (int i = 0; i < N; i++)
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
		if (indegree[node] == 0)
		{
			ans.push_back(node);
		}
		for (auto adjnode : adj[node])
		{
			indegree[adjnode]--;
			if (indegree[adjnode] == 0)
			{
				q.push(adjnode);
			}
		}

		//                      same as toposort problem
		//                      if we are unable to form toposort then it has some cycles, so not possible, otherwise yes
		//                      for logic, can refer to video
	}
	if (ans.size() == N)
	{
		return true;
	}
	return false;
}

int main()
{
}