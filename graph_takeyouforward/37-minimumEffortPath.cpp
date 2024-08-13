// https://leetcode.com/problems/path-with-minimum-effort/description/

#include <bits/stdc++.h>
using namespace std;

int MinimumEffort(vector<vector<int>>& heights) {
        // Code here
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>>diff(n,vector<int>(m,1e9));
        diff[0][0]=0;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>q;
        q.push({0,{0,0}});
        int rowc[]={-1,0,1,0};
        int colc[]={0,1,0,-1};
        while(!q.empty()){
            int row=q.top().second.first;
            int col=q.top().second.second;
            // int effort=max(effort,q.top().first);
            int effort=q.top().first;
            if(row==n-1 && col==m-1){
                return effort;
            }
            q.pop();
            for(int i=0;i<4;i++){
                int nrow=row+rowc[i];
                int ncol=col+colc[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m){
                    int neffort=max(effort,abs(heights[nrow][ncol]-heights[row][col]));
                    if(neffort<diff[nrow][ncol]){
                        diff[nrow][ncol]=neffort;
                        q.push({neffort,{nrow,ncol}});
                    }
                }
            }
        }
    }

int main() {

}