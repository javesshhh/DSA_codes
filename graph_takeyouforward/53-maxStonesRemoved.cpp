// https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/description/

#include <bits/stdc++.h>
using namespace std;

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
    int maxRemove(vector<vector<int>> &stones, int n)
    {
        // Code here
        // int maxr=0;
        // int maxc=0;
        int k = 0;
        int m = 0;
        for (auto it : stones)
        {
            k = max(it[0], k);
            m = max(it[1], m);
        }
        // int k=stones.size();
        // int m=stones[0].size();
        DisjointSet ds(k + m + 1);
        for (auto it : stones)
        {
            ds.unionBySize(it[0], it[1] + k + 1);
        }
        int cnt = 0;
        for (int i = 0; i < k + 1; i++)
        {
            if (ds.findUPar(i) == i)
            {
                if (ds.size[i] > 1)
                {
                    cnt++;
                }
                // cnt=cnt+ds.size[i]-1;
                // cnt++;
            }
        }
        return n - cnt;
    }
};


// dfs


class Solution
{
public:
    void dfs(vector<vector<int>> &stones, int index, vector<bool> &visited, int &n)
    {
        visited[index] = true;
        // int result=0;
        for (int i = 0; i < n; i++)
            if (!visited[i] && (stones[i][0] == stones[index][0] || stones[i][1] == stones[index][1]))
            {
                visited[i] = true;
                dfs(stones, i, visited, n);
            }
        return;
    }
    int removeStones(vector<vector<int>> &stones)
    {
        int n = stones.size();
        vector<bool> visited(n, 0);
        int result = 0;
        for (int i = 0; i < n; i++)
        {
            if (visited[i])
            {
                continue;
            }
            result++;
            dfs(stones, i, visited, n);
        }
        return n - result;
    }
};