#include <bits/stdc++.h>
using namespace std;
#define int long long

int ans=LLONG_MAX;

void fn(int st,vector<vector<pair<int,int>>> &adj,int end){
    priority_queue <pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> q;
    vector<int>dist(end+1);
        for(int i=1;i<end+1;i++){
            dist[i]=1e9;
        }
    q.push({0,{st,0}});
    dist[st]=0;
    while(!q.empty()){
        int cost=q.top().first;
        int node=q.top().second.first;
        int mx=q.top().second.second;
        q.pop();
        if(node==end){
            ans=min(ans,cost - mx + (mx/2));
            continue;
        }
        for(auto it:adj[node]){
            if(cost+it.second < dist[it.first]){
                dist[it.first]=cost+it.second;
                q.push({cost+ it.second ,{it.first,max(mx,it.second)}});
            }
        }
    }
}

signed main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int,int>>> adj(n+1);

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }

    fn(1,adj,n);
    cout<<ans<<endl;
    return 0;
}
