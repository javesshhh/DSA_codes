// https://leetcode.com/problems/making-a-large-island/description/

class DisjointSet
{

public:
    vector<int> rank, parent, size;
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (rank[ulp_u] < rank[ulp_v])
        {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u])
        {
            parent[ulp_v] = ulp_u;
        }
        else
        {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution
{
public:
    int largestIsland(vector<vector<int>> &grid)
    {
        // code here
        int n = grid.size();
        DisjointSet ds(n * n);

        // step-1: connecting components by union
        int rowc[] = {0, 1, 0, -1};
        int colc[] = {1, 0, -1, 0};
        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < n; col++)
            {
                if (grid[row][col] == 1)
                {
                    for (int k = 0; k < 4; k++)
                    {
                        int nrow = row + rowc[k];
                        int ncol = col + colc[k];
                        if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < n && grid[nrow][ncol] == 1)
                        {
                            ds.unionBySize(nrow * n + ncol, row * n + col);
                        }
                    }
                }
            }
        }
        // step-1 done

        // step-2 : brute force to change 0 -> 1 and find island size

        vector<int> ans;
        int res=0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                unordered_set<int> s;
                if (grid[i][j] == 0)
                {
                    for (int k = 0; k < 4; k++)
                    {
                        int nrow = i + rowc[k];
                        int ncol = j + colc[k];
                        if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < n && grid[nrow][ncol] == 1)
                        {
                            s.insert(ds.findUPar(nrow * n + ncol));
                        }
                    }
                }
                int totalsize = 0;
                for (auto it : s)
                {
                    totalsize = totalsize + ds.size[it];
                }
                // ans.push_back(totalsize + 1);
                res=max(res,totalsize);
            }
        }
        int zero = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 0)
                {
                    zero++;
                }
            }
        }
        if (zero == 0)
        {
            return n * n;
        }
        return res+1;
    }
};