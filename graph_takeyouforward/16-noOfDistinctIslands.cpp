// https://www.geeksforgeeks.org/problems/number-of-distinct-islands/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=number-of-distinct-islands
// https://www.youtube.com/watch?v=7zmgQSJghpo&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=16&ab_channel=takeUforward

#include <bits/stdc++.h>
using namespace std;

void dfs(int i1 , int j1 ,int n,int m,int row,int col,vector<vector<int>>& grid,vector<vector<int>>& vis,set<vector<pair<int,int>>>&s,vector<pair<int,int>>&v,int rowc[],int colc[]){
     vis[row][col]=1;
     v.push_back({i1-row,j1-col});
    for(int i=0;i<4;i++){
        int nrow=row+rowc[i];
        int ncol=col+colc[i];
        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1 && vis[nrow][ncol]==0){
            vis[nrow][ncol]=1;
            dfs(i1,j1,n,m,nrow,ncol,grid,vis,s,v,rowc,colc);
        }
    }
    return ;
}

int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n=grid.size();
        int m=grid[0].size();
        // set<pair<int,int>>s;
        set<vector<pair<int,int>>>s;
        vector<pair<int,int>>v;
        vector<vector<int>>vis(n,vector<int>(m,0));
        int rowc[]={-1,0,1,0};
        int colc[]={0,1,0,-1};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && vis[i][j]==0){
                    vis[i][j]=1;
                    dfs(i,j,n,m,i,j,grid,vis,s,v,rowc,colc);
                    s.insert(v);
                    v.clear();
                }
            }
        }
        return s.size();
    }

int main()
{
}