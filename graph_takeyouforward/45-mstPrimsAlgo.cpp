// https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=minimum-spanning-tree

#include <bits/stdc++.h>
using namespace std;

//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here

        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>q;
        // wt,node,parent
        int vis[V]={0};
        q.push({0,{0,-1}});
        // vector<pair<int,int>>ans;
        int sum=0;
        while(!q.empty()){
            int wt=q.top().first;
            int node=q.top().second.first;
            int parent=q.top().second.second;
            q.pop();
            if(vis[node]==0){
                vis[node]=1;
                sum=sum+wt;
            }
            else if(vis[node]==1){
                goto labell;
            }
            for(auto it:adj[node]){
                if(vis[it[0]]==0){
                    q.push({it[1],{it[0],node}});
                }
            }
            labell:
            continue;
        }
        return sum;
    }

int main() {

}