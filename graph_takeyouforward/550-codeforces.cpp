// https://codeforces.com/contest/1144/problem/F
// https://www.youtube.com/watch?v=_n-OeOJpnIY&list=PLzVLIdIx9dQwzso2IwXCQq3aEicK02iKF&index=4&ab_channel=AdhishK

// #include <bits/stdc++.h>
// using namespace std;
// int n, m;
// vector<int>vis(n,false);
// vector<vector<int>> adj(n);
// vector<int>col(n,-1);
// bool dfs(int u)
// {
//     vis[u] = 1;
//     for (auto it : adj[u])
//     {
//         if (col[it] == col[u])
//         {
//             return false;
//         }
//         else if (vis[it] == 0)
//         {
//             col[it] = !col[u];
//             if(dfs(it)==false){
//                 return false;
//             }
//         }
//     }
//     return true;
// }

// int main()
// {
//     cin >> n >> m;
//     vector<pair<int,int>>vv;
//     for (int i = 1; i <= m; i++)
//     {
//         int u, v;
//         cin >> u >> v;
//         adj[u].push_back(v);
//         adj[v].push_back(u);
//         vv.push_back({u,v});
//     }
//     // int vis[n];
//     col[1] = 0;
//     bool c = dfs(1);
//     string res="";
//     if(c==false){
//         cout<<"NO"<<endl;
//     }
//     else{
//         cout<<"YES"<<endl;
//         for(auto it:vv){
//             if(col[it.first]==0){
//                 res.push_back(1);
//             }
//             else{
//                 res.push_back(1);
//             }
//         }
//         cout<<endl;
//     }
// }

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
const ll mod = 1e9 + 7, inf = 1e18;
#define pb push_back
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
void setIO()
{
    fast;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
int n = 2e5 + 5, m;
vvi adj(n);
vi col(n, -1); // initialize to -1 so that a 0 value is not wrongly considered
vb vis(n);
bool dfs(int u)
{
    vis[u] = 1;
    for (int v : adj[u])
    {
        if (col[v] == col[u])
            return false;
        else if (!vis[v])
        {
            col[v] = !col[u];
            if (!dfs(v))
                return false;
        }
    }
    return true;
}
int main()
{
    setIO();
    cin >> n >> m;

    vvi el;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
        el.pb({u, v});
    }
    col[1] = 0;
    if (!dfs(1))
    {
        cout << "NO";
    }
    else
    {
        cout << "YES" << endl;
        string ans = "";
        for (int i = 0; i < m; i++)
        { // iterating over all edges
            int u = el[i][0], v = el[i][1];
            if (col[u] == 0)
            { // u is an outgoing node
                ans += "0";
            }
            else
            {
                ans += "1";
            }
        }
        cout << ans;
    }
    return 0;
}