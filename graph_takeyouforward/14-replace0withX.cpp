// https://leetcode.com/problems/surrounded-regions/description/

#include <bits/stdc++.h>
using namespace std;

void dfs(int n,int m,int row,int col,vector<vector<char>> &mat,vector<vector<int>> &vis,int rowc[],int colc[]){
    vis[row][col]=1;
    for(int i=0;i<4;i++){
        int nrow=row+rowc[i];
        int ncol=col+colc[i];
        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]==0 && mat[nrow][ncol]=='O'){
            dfs(n,m,nrow,ncol,mat,vis,rowc,colc);
        }
    }
}

vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here
        vector<vector<int>>vis(n,vector<int>(m,0));
        vector<vector<char>> ans=mat;
        int rowc[]={-1,0,1,0};
        int colc[]={0,1,0,-1};
        for(int i=0;i<n;i++){
            if(mat[i][0]=='O' && vis[i][0]==0){
                dfs(n,m,i,0,mat,vis,rowc,colc);
            }
        }
        for(int i=0;i<m;i++){
            if(mat[0][i]=='O' && vis[0][i]==0){
                dfs(n,m,0,i,mat,vis,rowc,colc);
            }
        }
        for(int i=0;i<n;i++){
            if(mat[i][m-1]=='O' && vis[i][m-1]==0){
                dfs(n,m,i,m-1,mat,vis,rowc,colc);
            }
        }
        for(int i=0;i<m;i++){
            if(mat[n-1][i]=='O' && vis[n-1][i]==0){
                dfs(n,m,n-1,i,mat,vis,rowc,colc);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==0 && mat[i][j]=='O'){
                    ans[i][j]='X';
                }
            }
        }
        return ans;
    }

int main() {

}