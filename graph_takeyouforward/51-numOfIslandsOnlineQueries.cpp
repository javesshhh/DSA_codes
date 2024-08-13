// https://www.geeksforgeeks.org/problems/number-of-islands/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=number-of-islands

#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
    vector<int> rank, parent, size;
public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
class Solution {
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // code here
        int k=operators.size();
        DisjointSet ds(n*m);
        int vis[n][m];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                vis[i][j]=0;
            }
        }
        vector<int>ans;
        int cnt=0;
        for(int i=0;i<k;i++){
            int row=operators[i][0];
            int col=operators[i][1];
            if(vis[row][col]==1){
                ans.push_back(cnt);
                continue;
            }
            vis[row][col]=1;
            cnt++;
            int rowc[]={0,1,0,-1};
            int colc[]={1,0,-1,0};
            for(int j=0;j<4;j++){
                int nrow=row+rowc[j];
                int ncol=col+colc[j];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m){
                    if(vis[nrow][ncol]==1){
                        if(ds.findUPar(row*m+col)!=ds.findUPar(nrow*m+ncol)){
                            ds.unionBySize(row*m+col,nrow*m+ncol);
                            cnt--;
                        }
                    }
                }
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};

int main() {

}