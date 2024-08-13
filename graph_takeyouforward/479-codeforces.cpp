// https://codeforces.com/contest/977/problem/E
// https://www.youtube.com/watch?v=-ZMi6jfKUuM&list=PLzVLIdIx9dQwzso2IwXCQq3aEicK02iKF&index=7&ab_channel=AdhishK

// #include <bits/stdc++.h>
// using namespace std;

// bool dfs(int u,vector<int>&out,vector<int>adj[],int vis[]){
//     vis[u]=1;
//     for(auto it:adj[u]){
//         if(out[it]>=3){
//             return false;
//         }
//         else if(out[it]<=1){
//             return false;
//         }
//         else if(out[it]==2){
//             if(dfs(it,out,adj,vis)==false){
//                 return false;
//             }
//         }
//     }
//     return false;
// }

// int main() {
//     int n,m;
//     cin>>n>>m;
//     vector<int>adj[n+1];
//     for(int i=0;i<m;i++){
//         int u,v;
//         cin>>u>>v;
//         adj[u].push_back(v);
//         adj[v].push_back(u);
//     }
//     vector<int>out(n+1,0);
//     for(int i=1;i<n+1;i++){
//         int k=0;
//         for(auto it:adj[i]){
//             k++;
//         }
//         out[i]=k;
//     }
//     int vis[n+1];
//     for(int i=1;i<n+1;i++){
//         vis[i]=0;
//     }
//     int ans=0;
//     for(int i=1;i<n+1;i++){
//         if(vis[i]==0){
//             if(dfs(i,out,adj,vis)==true){
//                 ans++;
//             }
//         }
//     }
//     cout<<ans<<endl;
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
vb vis(n);
bool isCycle;
void dfs(int u)
{
    // if the # of adjacent nodes to u is exactly 2
    // adj[u].size() gives the # of adjacent nodes to u
    vis[u] = 1;
    if (adj[u].size() != 2)
    { // dont return here but visit all nodes in this cc
        isCycle = false;
    }
    for (int v : adj[u])
    {
        if (!vis[v])
        {
            dfs(v);
        }
    }
}
int main()
{
    setIO();
    cin >> n >> m;
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v), adj[v].pb(u);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            isCycle = true;
            dfs(i);
            if (isCycle)
                ans++;
        }
    }
    cout << ans;
    return 0;
}