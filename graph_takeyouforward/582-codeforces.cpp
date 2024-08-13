// https://www.youtube.com/watch?v=pXxzvcdIf68&ab_channel=CodeNCode
// https://codeforces.com/contest/1213/problem/G

#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct edge
{
    int a;
    int b;
    ll w;
};

edge ar[200000];
pair<int, int> br[200001];
ll res[200001];

int _par[200001];
ll _rank[200001];

bool comp(edge a, edge b)
{
    return a.w < b.w;
}

int find(int a)
{
    if (_par[a] == -1)
        return a;

    return _par[a] = find(_par[a]);
}

ll merge(int a, int b)
{
    a = find(a);
    b = find(b);

    ll res = _rank[a] * _rank[b];

    _rank[a] += _rank[b];
    _par[b] = a;

    return res;
}

int main()
{
    int n, q;
    cin >> n >> q;

    for (int i = 1; i < n; i++)
    {
        cin >> ar[i].a >> ar[i].b >> ar[i].w;
        _rank[i] = 1;
        _par[i] = -1;
    }

    _rank[n] = 1;
    _par[n] = -1;

    sort(ar + 1, ar + n, comp);

    for (int i = 1; i <= q; i++)
        cin >> br[i].first, br[i].second = i;

    sort(br + 1, br + q + 1);

    ll count = 0;
    int index = 1;
    for (int i = 1; i <= q; i++)
    {
        ll w = br[i].first;

        while (index < n && ar[index].w <= w)
        {
            count += merge(ar[index].a, ar[index].b);
            index++;
        }

        res[br[i].second] = count;
    }

    for (int i = 1; i <= q; i++)
        cout << res[i] << " ";
}