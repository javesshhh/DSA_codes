// https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

#include <bits/stdc++.h>
using namespace std;

    bool detect(int start,int V,vector<int> adj[],int vis[],int path[]){
        vis[start]=1;
        path[start]=1;
        for(auto adjnode:adj[start]){
            if(vis[adjnode]==0){
                if(detect(adjnode,V,adj,vis,path)==true){
                    return true;
                }
            }
            else if(vis[adjnode]==1 && path[adjnode]==1){
                return true;
            }
        }
        path[start]=0;
        return false;
    }

// Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        int vis[V]={0};
        int path[V]={0};
        for(int i=0;i<V;i++){
            if(vis[i]==0){
                if(detect(i,V,adj,vis,path)==true){
                    return true;
                }
            }
        }
        return false;
    }

int main() {

}