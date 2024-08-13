#include <bits/stdc++.h>
using namespace std;

bool dfs(int start,int V,vector<int>adj[],int color[]){
    // color[start]=0;
    for(auto adjnode:adj[start]){
        if(color[adjnode]==-1 && color[start]==0){
            color[adjnode]=1;
            dfs(adjnode,V,adj,color);
        }
        else if(color[adjnode]==-1 && color[start]==1){
            color[adjnode]=0;
            dfs(adjnode,V,adj,color);
        }
        else if(color[adjnode]==color[start]){
            return false;
        }
    }
    return true;
}

bool isBipartite(int V, vector<int>adj[]){
    int color[V];
    for(int i=0;i<V;i++){
        color[i]=-1;
    }
    for(int i=0;i<V;i++){
        if(color[i]==-1){
            color[i]=0;
            if(dfs(i,V,adj,color)==false){
                return false;
            }
        }
    }
    return true;
}

int main() {

}