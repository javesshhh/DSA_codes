// set is used becox while iterating, if we get dist other than 1e9 and currect dist is less than that,
// then that means there is some path stores in set which will eventually gives higher cost, so better remove it from set using erase fn
// this results in minimising some unwanted iterations but also add up logarithmic complexity
// so there is always trade off between using priority queue and set
// some bigger and complex graph might worls better with set, smaller might work best with priority queue

#include <bits/stdc++.h>
using namespace std;

//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        set<pair<int,int>>s;
        vector<int>dist(V,1e9);
        dist[S]=0;
        s.insert({0,S});
        while(!s.empty()){
            auto it=*(s.begin());
            int node=it.second;
            int dis=it.first;
            s.erase({dis,node});
            for(auto i:adj[node]){
                int adjnode=i[0];;
                int wt=i[1];
                if(dis+wt<dist[adjnode]){
                    if(dist[adjnode]!=1e9){
                        s.erase({dist[adjnode],adjnode});
                    }
                    dist[adjnode]=dis+wt;
                    s.insert({dist[adjnode],adjnode});
                }
            }
        }
        return dist;
    }

int main() {

}