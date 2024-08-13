// https://leetcode.com/problems/number-of-operations-to-make-network-connected/description/

class DisjointSet
{
    vector<int> rank, parent, size;

public:
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
    int makeConnected(int n, vector<vector<int>> &edge)
    {
        // code here
        DisjointSet ds(n);
        int m = edge.size();
        int ans = 0;
        for (auto it : edge)
        {
            ds.unionBySize(it[0], it[1]);
        }
        set<int> s;
        for (int i = 0; i < n; i++)
        {
            s.insert(ds.findUPar(i));
        }
        int k = s.size();
        if (m >= n - 1)
        {
            return k - 1;
        }
        return -1;
    }
};


//


#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
    vector<int> rank, parent, size;

public:
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

    int unionBySize(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return 1;
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
        return 0;
    }
};

class Solution
{
public:
    int makeConnected(int n, vector<vector<int>> &edge)
    {
        // code here
        DisjointSet ds(n);
        int m = edge.size();
        int extra = 0;
        for (auto it : edge)
        {
            extra += ds.unionBySize(it[0], it[1]);
        }
        int connectedComp = 0;
        for (int i = 0; i < n; i++)
        {
            if (ds.findUPar(i) == i)
                ++connectedComp;
        }
        if (connectedComp - 1 <= extra)
            return connectedComp - 1;
        return -1;
        // set<int> s;
        // for (int i = 0; i < n; i++)
        // {
        //     s.insert(ds.findUPar(i));
        // }
        // int k = s.size();
        // if (m >= n - 1)
        // {
        //     return k - 1;
        // }
        // return -1;
    }
};