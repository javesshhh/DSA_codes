// https://practice.geeksforgeeks.org/problems/number-of-provinces/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=number_of_provinces


#include <bits/stdc++.h>
using namespace std;

void dfs(int start,vector<int>adjl[],int vis[]){
    vis[start]=1;
    for(auto it:adjl[start]){
        if(vis[it]==0){
            dfs(it,adjl,vis);
        }
    }
}

int numProvinces(vector<vector<int>> adj, int V) {
        // changing adjacency matrix to adjacency list
        vector<int>adjl[V];
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(adj[i][j]==1 && i!=j){
                    adjl[i].push_back(j);
                    adjl[j].push_back(i);
                }
            }
        }
        int vis[V]={0};
        int cnt=0;
        for(int i=0;i<V;i++){
            if(vis[i]==0){
                cnt++;
                dfs(i,adjl,vis);
            }
        }
        return cnt;
    }

// Space Complexity: O(N) + O(N),Space for recursion stack space and visited array.
// Time Complexity: O(N) + O(V+2E), Where O(N) is for outer loop and inner loop runs in total a-
// -single DFS over entire graph, and we know DFS takes a time of O(V+2E)

int main() {

}