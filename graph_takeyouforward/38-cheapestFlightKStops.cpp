// https://leetcode.com/problems/cheapest-flights-within-k-stops/description/

#include <bits/stdc++.h>
using namespace std;

int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int k)  {
        // Code here
        vector<pair<int,int>>adj[n];
        // int n=flights.size();
        // int m=flights[0].size();
        for(auto it:flights){
            int u=it[0];
            int v=it[1];
            int w=it[2];
            adj[u].push_back({v,w});
        }
        queue<pair<int,pair<int,int>>>q;
        // stops,cost,node
        vector<int>ans(n,1e9);
        q.push({0,{0,src}});
        ans[src]=0;
        while(!q.empty()){
            int stop=q.front().first;
            int cost=q.front().second.first;
            int node=q.front().second.second;
            q.pop();
            if(stop>k){
                goto label;
            }
            for(auto it:adj[node]){
                int adjnode=it.first;
                int wt=it.second;
                if(cost+wt<ans[adjnode]){
                    ans[adjnode]=cost+wt;
                    q.push({stop+1,{cost+wt,adjnode}});
                }
            }
            label:
            continue;
        }
        if(ans[dst]==1e9) return -1;
        return ans[dst];
    }

int main() {

}