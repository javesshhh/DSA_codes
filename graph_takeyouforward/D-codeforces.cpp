// https://www.youtube.com/watch?v=K5N6KoyQBKE&list=PLzVLIdIx9dQwzso2IwXCQq3aEicK02iKF&index=9&ab_channel=AdhishK
// https://codeforces.com/contest/1534/problem/D


// #include <bits/stdc++.h>
// using namespace std;
//     int n=2005;
// vector<int>dist(n);
// vector<vector<int>>edges;

// void query(int n){
//     cout<<"? "<<n<<endl;
//     for(int i=1;i<=n;i++){
//         cin>>dist[i];
//     }
// }
// void addEdge(int u,int v){
//     edges.push_back({u,v});
// }
// int main() {
//     cin>>n;
//     query(1);
//     vector<int>ini=dist;
//     vector<int>yellow;
//     vector<int>black;
//     for(int i=2;i<=n;i++){
//         if(dist[i]%2==0){
//             black.push_back(i);
//         }
//         else if(dist[i]%2!=0){
//             yellow.push_back(i);
//         }
//         if(dist[i]==1) addEdge(i,1);
//     }
//     if(black.size()<yellow.size()){
//         for(int it:black){
//             query(it);
//             for(int i=2;i<=n;i++){
//                 if(dist[i]==1){
//                     addEdge(i,it);
//                 }
//             }
//         }
//     }
//     else{
//         for(int it:yellow){
//             query(it);
//             for(int i=2;i<=n;i++){
//                 if(dist[i]==1){
//                     addEdge(i,it);
//                 }
//             }
//         }
//     }
//     cout<<"!"<<endl;
//     for(auto it:edges){
//         cout<<it[0]<<" "<<it[1]<<endl;
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
const ll mod = 1e9 + 7,inf = 1e18;
#define pb push_back
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
void setIO()
{
    fast;
}
int n = 2005;
vi dist(n);
vvi edges;
void query(int node)
{
    cout<<"? "<<node<<endl;
    for (int i = 1;i<=n;i++)
        cin>>dist[i];
}
void addEdge(int u,int v)
{
    edges.pb({u,v});
}
int main()
{
    setIO();
    cin>>n;
    query(1);
    vi InitialDistance = dist;
    //InitialDistance array stores the distances from every node to node 1
    vi blackNodes;
    vi yellowNodes;
    for (int i = 2;i<=n;i++){//run the loop from 2 to N because we know which nodes are adjacent to 1
        if (dist[i]%2 == 0)
            blackNodes.pb(i);
        else
            yellowNodes.pb(i);
        if (dist[i] == 1)
            addEdge(i,1);
    }
    if (blackNodes.size() < yellowNodes.size()){
        for (int node:blackNodes){
            query(node);
            for (int i = 2;i<=n;i++){
                if (dist[i] == 1)
                    addEdge(i,node);
            }
        }
    }
    else{
        for (int node:yellowNodes){
            query(node);
            for (int i = 2;i<=n;i++){
                if (dist[i] == 1)
                    addEdge(i,node);
            }
        }
    }
    cout<<"!"<<endl;
    for (auto edge:edges){
        cout<<edge[0]<<" "<<edge[1]<<endl;
    }
    return 0;
}