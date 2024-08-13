// https://www.interviewbit.com/problems/hotel-service/

vector<int> Solution::nearestHotel(vector<vector<int>> &grid, vector<vector<int>> &b)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));
    vector<vector<int>> dist(n, vector<int>(m, 0));
    queue<pair<pair<int, int>, int>> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1)
            {
                vis[i][j] = 1;
                q.push({{i, j}, 0});
            }
        }
    }

    int rowc[] = {-1, 0, 1, 0};
    int colc[] = {0, 1, 0, -1};

    while (!q.empty())
    {
        int row = q.front().first.first;
        int col = q.front().first.second;
        int dis = q.front().second;
        q.pop();
        dist[row][col] = dis;
        for (int i = 0; i < 4; i++)
        {
            int nrow = row + rowc[i];
            int ncol = col + colc[i];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] == 0 && grid[nrow][ncol] == 0)
            {
                vis[nrow][ncol] = 1;
                q.push({{nrow, ncol}, dis + 1});
            }
        }
    }
    vector<int> ans;
    for (int i = 0; i < b.size(); i++)
    {
        int x = b[i][0] - 1;
        int y = b[i][1] - 1;
        ans.push_back(dist[x][y]);
    }
    return ans;
}
