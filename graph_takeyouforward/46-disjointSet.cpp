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
int main()
{
    DisjointSet ds(7);
    ds.unionBySize(1, 2);
    ds.unionBySize(2, 3);
    ds.unionBySize(4, 5);
    ds.unionBySize(6, 7);
    ds.unionBySize(5, 6);
    // if 3 and 7 same or not
    if (ds.findUPar(3) == ds.findUPar(7))
    {
        cout << "Same\n";
    }
    else
        cout << "Not same\n";

    ds.unionBySize(3, 7);
    if (ds.findUPar(3) == ds.findUPar(7))
    {
        cout << "Same\n";
    }
    else
        cout << "Not same\n";
    return 0;
}

//   https://www.geeksforgeeks.org/problems/disjoint-set-union-find/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=disjoint-set-union-find

class Disjoint
{
    vector<int> rank;
    vector<int> parent;

public:
    Disjoint(int n)
    {
        rank.resize(n + 1);
        parent.resize(n + 1);
        for (int i = 0; i < n + 1; i++)
        {
            rank[i] = 0;
            parent[i] = i;
        }
    }
    int upar(int x)
    {
        if (parent[x] == x)
            return x;
        return parent[x] = upar(parent[x]);
    }
    void union1(int x, int y)
    {
        int par1 = upar(x);
        int par2 = upar(y);
        if (rank[par1] > rank[par2])
        {
            parent[par2] = par1;
        }
        else if (rank[par1] < rank[par2])
        {
            parent[par1] = par2;
        }
        else
        {
            parent[par2] = par1;
            rank[par1]++;
        }
    }
};
/*Complete the functions below*/
int n = 100000;

int find(int A[], int X)

{

    // add code here.

    if (A[X] == X)

        return X;

    return A[X] = find(A, A[X]); // path compression.
}

void unionSet(int A[], int X, int Z)

{

    int u = find(A, X);

    int v = find(A, Z);

    vector<int> rank(n + 1, 0);

    if (u == v)
    {

        return; // if both have same ultimayte parent therefore they        were connected already .
    }

    if (rank[u] < rank[v])
    {

        A[u] = v; // rank will not is the smaller get connected to the larger .
    }

    else if (rank[u] > rank[v])
    {

        A[v] = u; // rank will not is the smaller get connected to the larger .
    }

    else
    {

        A[u] = v;

        rank[v]++; // rank of v increase as the v is connectiong to it .
    }
}

//       union by size method : easy and simplified solution

int find(int A[], int X)

{

    if (A[X] == X)

        return X;

    return A[X] = find(A, A[X]); // path compression.
}

void unionSet(int A[], int X, int Z)

{

    // add code here.

    int u = find(A, X);

    int v = find(A, Z);

    if (u == v)
    {

        return;
    }

    vector<int> size(n + 1, 1);

    if (size[u] > size[v])
    {

        A[v] = u;

        size[u] += size[v];
    }

    else
    {

        A[u] = v;

        size[v] += size[u];
    }
}