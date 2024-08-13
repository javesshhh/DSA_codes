// https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=detect-cycle-in-an-undirected-graph

#include <bits/stdc++.h>
using namespace std;

bool detectCycle(int start,int parent,vector<int> adj[],int vis[]){
    vis[start]=1;
    for(auto adjacent:adj[start]){
        if(vis[adjacent]==0){
            detectCycle(adjacent,start,adj,vis);
        }
        else if(vis[adjacent]==1&&adjacent!=parent){
            return true;
        }
    }
    return false;
}

// Function to detect cycle in an undirected graph.
bool isCycle(int V, vector<int> adj[]){
    int vis[V]={0};
    vis[0]=1;
    for(int i=0;i<V;i++){
        if(vis[i]==0){
            if(detectCycle(i,-1,adj,vis)==true){
                return true;
            }
        }
    }
    return false;
}

int main() {

}