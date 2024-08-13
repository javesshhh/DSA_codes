#include <bits/stdc++.h>
using namespace std;

void shortest_distance(vector<vector<int>> &matrix)
{
	// Code here
	int n = matrix.size();
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (matrix[i][j] == -1)
			{
				matrix[i][j] = 1e9; // just for convinience, 1e9 denotes imposible to reach that node, will reverse the same at the end
			}
			if (i == j)
				matrix[i][j] = 0; // node i to i is distance zero
		}
	}

	for (int k = 0; k < n; k++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (matrix[i][j] == 1e9)
			{
				matrix[i][j] = -1;
			}
		}
	}
}