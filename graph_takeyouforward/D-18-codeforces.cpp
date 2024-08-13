// https://www.youtube.com/watch?v=d8SmH0GnFcs&ab_channel=AdhishK
// https://codeforces.com/contest/1037/problem/D
// https://codeforces.com/blog/entry/91329

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using vc = vector<char>;
using vvc = vector<vc>;
using vs = vector<string>;
const ll mod = 1e9 + 7,inf = 1e18;
#define pb push_back
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
void setIO()
{
    fast;
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
}
int n = 2e5 + 5;
vvi adj(n);
vi ind(n);
vi BFS()//returns the BFS ordering
{
    vi ordering;
    queue<int>q;
    vb vis(n + 1);
    vis[1] = 1;
    q.push(1);

    while (!q.empty()){
        int u = q.front();
        ordering.pb(u);
        q.pop();
        for (int v:adj[u]){
            if (!vis[v]){
                vis[v] = 1;
                q.push(v);
            }
        }
    }

    return ordering;
}
bool comp(int i,int j)
{
    return ind[i] < ind[j];
}
int main()
{
    // setIO();
    cin>>n;
    for (int i = 0;i<n - 1;i++){
        int u,v;
        cin>>u>>v;
        adj[u].pb(v),adj[v].pb(u);
    }
    vi a(n);
    for (int i = 0;i<n;i++){
        cin>>a[i];
        ind[a[i]] = i;//this is because a[i] occurs at position i
    }
    for (int i = 1;i<=n;i++)
        sort(adj[i].begin(),adj[i].end(),comp);

    if (BFS() == a)cout<<"Yes";
    else cout<<"No";
    return 0;
}