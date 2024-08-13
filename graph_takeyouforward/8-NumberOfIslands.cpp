// https://leetcode.com/problems/number-of-islands/description/

#include <bits/stdc++.h>
using namespace std;

void bfs(int row,int col,vector<vector<int>>&vis,vector<vector<char>>& grid){
    vis[row][col]=1;
    queue<pair<int,int>>q;
    q.push({row,col});
    int n=grid.size();
    int m=grid[0].size();
    while(!q.empty()){
        int one=q.front().first;
        int two=q.front().second;
        q.pop();
        for(int i=-1;i<=1;i++){
            for(int j=-1;j<=1;j++){
                int newrow=row+i;
                int newcol=col+j;
                if(newrow>=0&&newrow<n&&newcol>=0&&newcol<m&&grid[newrow][newcol]=='1' && !vis[newrow][newcol]){
                    vis[newrow][newcol]=1;
                    q.push({newrow,newcol});
                }
            }
        }
    }
}

// Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==0 && grid[i][j]=='1'){
                    cnt++;
                    bfs(i,j,vis,grid);
                }
            }
        }
        return cnt;
    }

int main() {

}