// https://www.geeksforgeeks.org/problems/alien-dictionary/1

#include <bits/stdc++.h>
using namespace std;

string findOrder(string dict[], int N, int K) {
        //code here
        // int len=dict.size();
        vector<int>adj[K];
        int indegree[K]={0};
        queue<int>q;
        for(int i=0;i<N-1;i++){
            for(int j=0;j<min(dict[i].size(),dict[i+1].size());j++){
                if(dict[i][j]==dict[i+1][j]){
                    continue;
                }
                else{
                    adj[dict[i][j]-'a'].push_back(dict[i+1][j]-'a');
                    break;
                }
            }
        }
        for(int i=0;i<K;i++){
            for(auto it:adj[i]){
                indegree[it]++;
            }
        }
        for(int i=0;i<K;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<int>topo;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            if(indegree[node]==0){
                topo.push_back(node);
            }
            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        string s="";
        for(auto it:topo){
            s.push_back(char(it+'a'));
        }
        return s;
    }

int main() {

}