// https://leetcode.com/problems/rotting-oranges/description/

#include <bits/stdc++.h>
using namespace std;

// Function to find minimum time required to rot all oranges.
int orangesRotting(vector<vector<int>> &grid)
{
    // Code here
    int n = grid.size();
    int m = grid[0].size();
    int rowc[] = {-1, 0, 1, 0};
    int colc[] = {0, 1, 0, -1};
    queue<pair<pair<int, int>, int>> q; // {{row,col},time}
    int vis[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 2)
            {
                q.push({{i, j}, 0});
                vis[i][j] = 2;
            }
            else
            {
                vis[i][j] = 0;
            }
        }
    }
    int tm = 0;
    while (!q.empty())
    {
        int row = q.front().first.first;
        int col = q.front().first.second;
        int t = q.front().second;
        tm = max(tm, t);
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nrow = row + rowc[i];
            int ncol = col + colc[i];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1 && vis[nrow][ncol] != 2)
            {
                q.push({{nrow, ncol}, t + 1});
                vis[nrow][ncol] = 2;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1 && vis[i][j] != 2)
            {
                return -1;
            }
        }
    }
    return tm;
}

int main()
{
}