// https://leetcode.com/problems/find-eventual-safe-states/description/

#include <bits/stdc++.h>
using namespace std;

bool detect(int start,int V,vector<int> adj[],int vis[],int path[],int end[]){
        vis[start]=1;
        path[start]=1;
        for(auto adjnode:adj[start]){
            if(vis[adjnode]==0){
                if(detect(adjnode,V,adj,vis,path,end)==true){
                    return true;
                }
            }
            else if(vis[adjnode]==1 && path[adjnode]==1){
                return true;
            }
        }
        end[start]=1;
        path[start]=0;
        return false;
    }

    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        int vis[V]={0};
        int path[V]={0};
        int end[V]={0};
        vector<int>ans;
        for(int i=0;i<V;i++){
            if(vis[i]==0){
                detect(i,V,adj,vis,path,end);
            }
        }
        for(int i=0;i<V;i++){
            if(end[i]==1){
                ans.push_back(i);
            }
        }
        return ans;
    }

int main() {

}