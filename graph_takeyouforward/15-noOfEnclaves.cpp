// https://leetcode.com/problems/number-of-enclaves/description/

#include <bits/stdc++.h>
using namespace std;

void dfs(int n, int m, int row, int col, vector<vector<int>> &grid, vector<vector<int>> &vis, int rowc[], int colc[])
{
    vis[row][col] = 1;
    for (int i = 0; i < 4; i++)
    {
        int nrow = row + rowc[i];
        int ncol = col + colc[i];
        if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1 && vis[nrow][ncol] == 0)
        {
            dfs(n, m, nrow, ncol, grid, vis, rowc, colc);
        }
    }
}

int numberOfEnclaves(vector<vector<int>> &grid)
{
    // Code here
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));
    int rowc[] = {-1, 0, 1, 0};
    int colc[] = {0, 1, 0, -1};
    for (int i = 0; i < n; i++)
    {
        if (grid[i][0] == 1 && vis[i][0] == 0)
        {
            dfs(n, m, i, 0, grid, vis, rowc, colc);
        }
    }
    for (int i = 0; i < m; i++)
    {
        if (grid[0][i] == 1 && vis[0][i] == 0)
        {
            dfs(n, m, 0, i, grid, vis, rowc, colc);
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (grid[i][m - 1] == 1 && vis[i][m - 1] == 0)
        {
            dfs(n, m, i, m - 1, grid, vis, rowc, colc);
        }
    }
    for (int i = 0; i < m; i++)
    {
        if (grid[n - 1][i] == 1 && vis[n - 1][i] == 0)
        {
            dfs(n, m, n - 1, i, grid, vis, rowc, colc);
        }
    }
    int cnt = 0;
    for (int i = 1; i < n - 1; i++)
    {
        for (int j = 1; j < m - 1; j++)
        {
            if (grid[i][j] == 1 && vis[i][j] == 0)
            {
                cnt++;
                // dfs(n,m,i,j,grid,vis,rowc,colc);
            }
        }
    }
    return cnt;
}

//                    another method by BFS

// int numberOfEnclaves(vector<vector<int>> &grid) {
//         queue<pair<int,int>> q;
//         int n = grid.size();
//         int m = grid[0].size();
//         int vis[n][m] = {0};
//         // traverse boundary elements
//         for(int i = 0;i<n;i++) {
//             for(int j = 0;j<m;j++) {
//                 // first row, first col, last row, last col
//                 if(i == 0 || j == 0 || i == n-1 || j == m-1) {
//                     // if it is a land then store it in queue
//                     if(grid[i][j] == 1) {
//                         q.push({i, j});
//                         vis[i][j] = 1;
//                     }
//                 }
//             }
//         }

//         int delrow[] = {-1, 0, +1, 0};
//         int delcol[] = {0, +1, +0, -1};

//         while(!q.empty()) {
//             int row = q.front().first;
//             int col = q.front().second;
//             q.pop();

//             // traverses all 4 directions
//             for(int i = 0;i<4;i++) {
//                 int nrow = row + delrow[i];
//                 int ncol = col + delcol[i];
//                 // check for valid coordinates and for land cell
//                 if(nrow >=0 && nrow <n && ncol >=0 && ncol < m
//                 && vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1) {
//                     q.push({nrow, ncol});
//                     vis[nrow][ncol] = 1;
//                 }
//             }

//         }

//         int cnt = 0;
//         for(int i = 0;i<n;i++) {
//             for(int j = 0;j<m;j++) {
//                 // check for unvisited land cell
//                 if(grid[i][j] == 1 & vis[i][j] == 0)
//                     cnt++;
//             }
//         }
//         return cnt;
//     }

int main()
{
}