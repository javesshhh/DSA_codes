// https://leetcode.com/problems/course-schedule/description/
// https://leetcode.com/problems/course-schedule-ii/description/

#include <bits/stdc++.h>
using namespace std;

vector<int> findOrder(int N, int m, vector<vector<int>> arrow)
{
	// code here
	vector<int> adj[N];
	for (int i = 0; i < m; i++)
	{
		adj[arrow[i][1]].push_back(arrow[i][0]);
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
	}
	if (ans.size() == N)
	{
		return ans;
	}
	return {};
}

int main()
{
}