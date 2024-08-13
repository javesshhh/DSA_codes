// https://www.youtube.com/watch?v=A0tAbJSbc5g&list=PLzVLIdIx9dQwzso2IwXCQq3aEicK02iKF&index=6&ab_channel=AdhishK
// https://codeforces.com/contest/1328/problem/D

// #include <bits/stdc++.h>
// #define int long long int
// #define mii map<int,int>
// #define umii unordered_map<int,int>
// #define pii pair<int,int>
// #define vi vector<int>
// #define vb vector<bool>
// #define vs vector<string>
// #define vpii vector<pair<int,int>>
// #define vvi vector<vector<int>>
// #define tc int t; cin>>t; while(t--)
// #define pb push_back
// #define ppb pop_back()
// #define gcd(a, b) __gcd(a, b)
// #define fr(a,b) for(int i = a; i < b; i++)
// #define frr(a,b) for(int i = a; i >= b; i--)
// #define vin(a,n) for(int i=0;i<n;i++) cin>>a[i]
// #define vout(a) for(auto x : a){cout<<x<<" ";} cout<<'\n'
// #define yes cout<<"YES"<<'\n'
// #define no cout<<"NO"<<'\n'
// #define ret(a) cout<<a<<'\n'
// #define mod 1000000007
// using namespace std;

// int power(int neeche, int upar) {
//     if (upar == 0)
//         return 1;
//     int rizzress = power(neeche, upar / 2);
//     if (upar % 2!=0)
//         return rizzress * rizzress * neeche;
//     else if (upar % 2==0)
//         return rizzress * rizzress;
// }

// int n;

// vector<int>vis(n+1,-1);
// vector<int>col(n+1,-1);

// void dfs(int u,vector<int>adj[]){
//     vis[u]=1;
//     for(auto it:adj[u]){
//         if(col[it]==col[u]){
//             col[it]=3;
//             vis[it]=1;
//         }
//         else if(vis[it]==0){
//             if(col[u]==1){
//                 col[it]=2;
//             }
//             else if(col[u]==2){
//                 col[it]=1;
//             }
//             else{
//                 col[it]=1;
//             }
//             dfs(it,adj);
//         }
//     }
// }

// signed main() {
// ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//     int t;
//     cin>>t;
//     while(t--){
//         // int n;
//         cin>>n;
//         int arr[n+1];
//         vector<int>adj[n+1];
//         for(int i=1;i<=n;i++){
//             cin>>arr[i];
//         }
//         for(int i=1;i<=n;i++){
//             if(i==n){
//                 if(arr[i]!=arr[1]){
//                     adj[i].push_back(1);
//                     adj[1].push_back(i);
//                 }
//                 continue;
//             }
//             if(arr[i]!=arr[i+1])
//             adj[i].push_back(i+1);
//             adj[i+1].push_back(i);
//         }
//         for(int i=1;i<=n;i++){
//             if(vis[i]==0){
//                 col[i]=1;
//                 dfs(i,adj);
//             }
//         }
//         unordered_set<int>ss;
//         for(auto it:col){
//             ss.insert(it);
//         }
//         cout<<ss.size()<<endl;
//         for(auto it:col){
//             cout<<it<<" ";
//         }
//         cout<<endl;
//     }
//     return 0;
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
int n = 2e5 + 5;
vvi adj(n);
vb vis(n);
vi col(n, -1);

void dfs(int u)
{
    vis[u] = 1;
    for (int v : adj[u])
    {
        if (col[v] == col[u])
        {               // discrepancy
            col[u] = 3; // we can also set col[v] = 3
            continue;
        }
        if (!vis[v])
        {
            if (col[u] == 1)
                col[v] = 2;
            else if (col[u] == 2)
                col[v] = 1;
            else
                col[v] = 1; // else col[u] == 3 hence set col[v] to be 1 or 2
            dfs(v);
        }
    }
}
void createGraph()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        adj[i].clear(), vis[i] = 0, col[i] = -1;
    vi t(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> t[i];

    for (int i = 1; i < n; i++)
    {
        if (t[i] != t[i + 1])
        {
            adj[i].pb(i + 1), adj[i + 1].pb(i); // because the graph is undirected
        }
    }

    if (t[1] != t[n])
    {
        adj[1].pb(n);
        adj[n].pb(1);
    }

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            col[i] = 1; // the colours are 1,2 or 3
            dfs(i);
        }
    }
    // output the # of colours
    int ans = 1;
    for (int i = 1; i <= n; i++)
        ans = max(ans, col[i]); // find the max colour # used
    cout << ans << '\n';
    for (int i = 1; i <= n; i++)
        cout << col[i] << " ";
    cout << '\n';
}
int main()
{
    setIO();
    int t;
    cin >> t;
    while (t--)
    {
        createGraph();
    }
    return 0;
}