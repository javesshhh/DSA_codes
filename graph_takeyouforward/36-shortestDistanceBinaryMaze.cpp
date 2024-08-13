// https://leetcode.com/problems/shortest-path-in-binary-matrix/description/

class Solution
{
public:
    int f(vector<vector<int>> &grid, pair<int, int> s, pair<int, int> d)
    {
        if (grid[0][0] == 1)
            return -1;
        if (s.first == d.first && s.second == d.second)
        {
            return 1;
        }

        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dist(n, vector<int>(m, 1e9));

        dist[0][0] = 1;
        // queue<pair<int, pair<int, int>>> q;
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;
        int dr[] = {-1, -1, 0, +1, +1, +1, 0, -1};
        int dc[] = {0, +1, +1, +1, 0, -1, -1, -1};
        q.push({1, {0, 0}});
        while (q.empty() == false)
        {
            auto it = q.top();
            int dis = it.first;
            int r = it.second.first;
            int c = it.second.second;
            q.pop();
            if (r == m - 1 and c == n - 1)
                return dis;
            for (int i = 0; i < 8; i++)
            {
                int nr = dr[i] + r;
                int nc = dc[i] + c;
                if (nr >= 0 && nc >= 0 && nr < n && nc < m && grid[nr][nc] == 0 && dis + 1 < dist[nr][nc])
                {
                    dist[nr][nc] = dis + 1;
                    q.push({1 + dis, {nr, nc}});
                }
            }
        }
        return -1;
    }
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        int n = grid.size();
        pair<int, int> s = {0, 0};
        pair<int, int> d = {n - 1, n - 1};
        return f(grid, s, d);
    }
};