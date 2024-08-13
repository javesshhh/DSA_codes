// https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1

// dijkstra will not work with negative weights becoz it will keep on adding weights and loop runs for infinite time due to negative weights

// priority queue is used in place of queue bcoz if using queue then in worst case it will give O(n2) complexity becoz
// it may search all paths if bigger distance paths comes before the shorter dist paths and it will iterste for all entries in queue
// priority queue works greedily by choosing shorter dist paths
// it reduces iterations with complexity E log v

#include <bits/stdc++.h>
using namespace std;

	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        vector<int>dist(V);
        for(int i=0;i<V;i++){
            dist[i]=1e9;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        dist[S]=0;
        q.push({0,S});
        while(!q.empty()){
            int dis=q.top().first;
            int node=q.top().second;
            q.pop();
            for(auto it:adj[node]){
                int wt=it[1];
                int adjnode=it[0];
                if(dis+wt<dist[adjnode]){
                    dist[adjnode]=dis+wt;
                    q.push({dist[adjnode],adjnode});
                }
            }
        }
        return dist;
    }

int main() {

}