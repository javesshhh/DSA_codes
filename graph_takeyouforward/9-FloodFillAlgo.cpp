// https://leetcode.com/problems/flood-fill/description/

#include <bits/stdc++.h>
using namespace std;

void dfs(int row, int col, int newColor, int color, vector<vector<int>> &image, vector<vector<int>> &grid, int rowc[], int colc[])
{
    grid[row][col] = newColor;
    int n = image.size();
    int m = image[0].size();
    for (int i = 0; i < 4; i++)
    {
        int newr = row + rowc[i];
        int newc = col + colc[i];
        if (newr >= 0 && newr < n && newc >= 0 && newc < m && image[newr][newc] == color && grid[newr][newc] != newColor)
            dfs(newr, newc, newColor, color, image, grid, rowc, colc);
    }
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
{
    // Code here
    int color = image[sr][sc];
    vector<vector<int>> grid = image;
    int rowc[] = {-1, 0, 1, 0};
    int colc[] = {0, 1, 0, -1};
    dfs(sr, sc, newColor, color, image, grid, rowc, colc);
    return grid;
}

// Time Complexity: O(NxM + NxMx4) ~ O(N x M)
// For the worst case, all of the pixels will have the same colour, so DFS function will be called
// for (N x M) nodes and for every node we are traversing for 4 neighbours, so it will take O(N x M x 4) time

// Space Complexity: O(N x M) + O(N x M)
// O(N x M) for copied input array and recursive stack space takes up N x M locations at max

// ##########################               another method

class Solution
{
private:
    void bfs(int row, int col, vector<vector<int>> &image, int newcolor, int start, vector<vector<int>> &vis)
    {
        vis[row][col] = 1;
        image[row][col] = newcolor;
        queue<pair<int, int>> q;
        q.push({row, col});
        int n = image.size();
        int m = image[0].size();
        while (!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for (int i = -1; i <= 1; i++)
            {
                int nrow = row + i;
                if (nrow >= 0 && nrow < n && image[nrow][col] == start && !vis[nrow][col])
                {
                    vis[nrow][col] = 1;
                    image[nrow][col] = newcolor;
                    q.push({nrow, col});
                }
            }
            for (int i = -1; i <= 1; i++)
            {
                int ncol = col + i;
                if (ncol >= 0 && ncol < m && image[row][ncol] == start && !vis[row][ncol])
                {
                    vis[row][ncol] = 1;
                    image[row][ncol] = newcolor;
                    q.push({row, ncol});
                }
            }
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
    {
        // Code here
        int start = image[sr][sc];
        int n = image.size();
        int m = image[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));

        bfs(sr, sc, image, newColor, start, vis);

        return image;
    }
};

int main()
{
}