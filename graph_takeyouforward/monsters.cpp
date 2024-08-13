// https://cses.fi/problemset/task/1194

#include <bits/stdc++.h>
using namespace std;

int st, ed;

bool bfs(int r, int c, vector<vector<char>> &path, vector<char> &ans, vector<vector<char>> &v, vector<vector<int>> &mon)
{
    queue<pair<int, pair<int, int>>> q;
    q.push({0, {r, c}});
    vector<int> row{-1, 0, 1, 0};
    vector<int> col{0, 1, 0, -1};
    int n = v.size();
    int m = v[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));
    vis[r][c] = 1;

    while (!q.empty())
    {
        int dis = q.front().first;
        int x = q.front().second.first;
        int y = q.front().second.second;
        q.pop();

        // Check if the current cell is on the border
        if (x == 0 || x == n - 1 || y == 0 || y == m - 1)
        {
            st = x;
            ed = y;
            return true;
        }

        for (int i = 0; i < 4; i++)
        {
            int nr = x + row[i];
            int nc = y + col[i];
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && v[nr][nc] != '#' && dis + 1 < mon[nr][nc] && vis[nr][nc] == 0)
            {
                vis[nr][nc] = 1;
                if (i == 0)
                    path[nr][nc] = 'U';
                if (i == 1)
                    path[nr][nc] = 'R';
                if (i == 2)
                    path[nr][nc] = 'D';
                if (i == 3)
                    path[nr][nc] = 'L';
                q.push({dis + 1, {nr, nc}});
            }
        }
    }
    return false;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> v(n, vector<char>(m));
    queue<pair<int, pair<int, int>>> q;
    int sx = -1, sy = -1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> v[i][j];
            if (v[i][j] == 'M')
                q.push({0, {i, j}});
            if (v[i][j] == 'A')
                sx = i, sy = j;
        }
    }

    vector<int> row{-1, 0, 1, 0};
    vector<int> col{0, 1, 0, -1};
    vector<vector<int>> mon(n, vector<int>(m, INT_MAX));

    // BFS for monsters to calculate time taken to reach each cell
    while (!q.empty())
    {
        int dis = q.front().first;
        int x = q.front().second.first;
        int y = q.front().second.second;
        q.pop();
        if (mon[x][y] <= dis)
            continue;
        mon[x][y] = dis;
        for (int i = 0; i < 4; i++)
        {
            int nr = x + row[i];
            int nc = y + col[i];
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && v[nr][nc] != '#' && mon[nr][nc] > dis + 1)
            {
                q.push({dis + 1, {nr, nc}});
            }
        }
    }

    vector<vector<char>> path(n, vector<char>(m));
    vector<char> ans;

    // BFS to find the path for 'A'
    if (bfs(sx, sy, path, ans, v, mon))
    {
        cout << "YES" << endl;
        int x = st, y = ed;
        while (x != sx || y != sy)
        {
            ans.push_back(path[x][y]);
            if (path[x][y] == 'R')
                y--;
            else if (path[x][y] == 'D')
                x--;
            else if (path[x][y] == 'U')
                x++;
            else if (path[x][y] == 'L')
                y++;
        }
        reverse(ans.begin(), ans.end());
        cout << ans.size() << endl;
        for (char c : ans)
        {
            cout << c;
        }
        cout << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}