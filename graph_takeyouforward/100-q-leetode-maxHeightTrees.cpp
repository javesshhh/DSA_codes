// https://leetcode.com/problems/minimum-height-trees/description/

#include <bits/stdc++.h>
using namespace std;

vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1) return {0};
        if(n==2) return {0,1};
        vector<int>adj[n];
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int>indegree(n,0);
        for(int i=0;i<n;i++){
            for(auto it:adj[i]){
                indegree[it]++;
            }
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(indegree[i]==1){
                q.push(i);
            }
        }

        // there can be max of two nodes for minimum height, can cross check by examples
        // so constantly removing 1 indegree leaf nodes as they can never give minimum height
        // so removing those nodes untill the remaining nodes are <=2

        while(n>2){
            int siz=q.size();
            n=n-q.size();
            for(int i=0;i<siz;i++){
                int node=q.front();
                q.pop();
                for(auto it:adj[node]){
                    indegree[it]--;
                    if(indegree[it]==1){
                        q.push(it);
                    }
                }
            }
        }
        vector<int>ans;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
        }
        return ans;
    }

int main() {

}