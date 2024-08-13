// https://www.youtube.com/watch?v=TTIjWRJ3TRw&list=PLzVLIdIx9dQwzso2IwXCQq3aEicK02iKF&ab_channel=AdhishK
// https://codeforces.com/contest/1454/problem/E
// https://codeforces.com/blog/entry/91329


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

// const int N=200005;
// vvi adj(N);
// vi par(N,-1);
// vi cycle(N);
// vi sub(N,0);
// vb onCycle(N,0);
// vb vis(N,0);
// bool found;


// void dfs(int u,int p){
//     if(found) return;
//     par[u]=p;
//     vis[u]=1;
//     for(auto it:adj[u]){
//         if(found) return;
//         if(vis[it]==0){
//             dfs(it,u);
//         }
//         if(vis[it]==1 && it!=p){
//             found=true;
//             while(u!=it){
//                 onCycle[u]=1;
//                 cycle.pb(u);
//                 u=par[u];
//             }
//             onCycle[u]=1;
//             cycle.pb(u);
//             return;
//         }
//     }
// }

// int dfs2(int u,int p){
//     sub[u]=1;
//     for(auto it:adj[u]){
//         if(onCycle[it]==false && it!=p){
//             sub[u]=sub[u]+dfs2(it,u);
//         }
//     }
//     return sub[u];
// }

// signed main() {
// ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//     int t;
//     cin>>t;
//     while(t--){
//         int n;
//         cin>>n;
//         for(int i=1;i<=n;i++){
//             int u,v;
//             cin>>u>>v;
//             adj[u].pb(v),adj[v].pb(u);
//         }
//         dfs(1,-1);
//         int ans=1LL*n*(n-1);
//         for(auto it:cycle){
//             int k=dfs2(it,-1);
//             ans=ans-(1LL*k*(k-1)/2);
//         }
//         cout<<ans<<endl;
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
vi par(n);
vb vis(n);
vi cycle;
bool found;
vb isOnCycle(n);//whether or not u is a cycle node
vi sub(n);

void dfs(int u,int p)
{
    if (found)return;//we dont explore any further since this dfs has accomplished its task
    par[u] = p;
    vis[u] = 1;
    for (int v:adj[u]){
        if (found)return;
        if (!vis[v])dfs(v,u);
        else if (v != p){//this means cycle contains u and v
            found = true;
            while (u != v){
                isOnCycle[u] = 1;
                cycle.pb(u);
                u = par[u];
            }
            isOnCycle[u] = 1;
            cycle.pb(u);//u == v
            return;
        }
    }
}
int dfs2(int u,int p)//finding the subtree sizes
{
    sub[u] = 1;
    for (int v:adj[u])
        if (!isOnCycle[v] && v != p)sub[u] += dfs2(v,u);
    return sub[u];
    
}
int main()
{
    // setIO();
    int t;
    cin>>t;
    while (t--){
        cin>>n;
        found = false;
        cycle.clear();
        for (int i = 1;i<=n;i++){
            adj[i].clear(),par[i] = -1,isOnCycle[i] = 0,vis[i] = 0,
            sub[i] = 0;
        }
        for (int i = 1;i<=n;i++){
            int u,v;
            cin>>u>>v;
            adj[u].pb(v),adj[v].pb(u);
        }
        dfs(1,-1);

        ll ans = 1ll * n * (1ll * n - 1);//complementary counting
        for (int u:cycle){
            dfs2(u,-1);
            ll val = sub[u];
            ans -= ((val - 1) * (val))/2;//subtree size choose 2
        }
        cout<<ans<<'\n';
    }
    return 0;
}