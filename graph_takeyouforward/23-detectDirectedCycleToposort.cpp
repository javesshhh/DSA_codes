// https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

#include <bits/stdc++.h>
using namespace std;

// Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        queue<int>q;
	    int indegree[V]={0};
	    for(int i=0;i<V;i++){
	        for(auto it:adj[i]){
	            indegree[it]++;
	        }
	    }
	    for(int i=0;i<V;i++){
	        if(indegree[i]==0){
	            q.push(i);
	        }
	    }
	    vector<int>ans;
	    while(!q.empty()){
	        int node=q.front();
	        q.pop();
	        if(indegree[node]==0){
	            ans.push_back(node);
	        }
	        for(auto adjnode:adj[node]){
	            indegree[adjnode]--;
	            if(indegree[adjnode]==0){
	                q.push(adjnode);
	            }
	        }
	    }

//                we know toposort works only on directed acyclic graph
//                so if no. of elements in toposort vector is exactly V, then we can say graph has no cycle, its acyclic
//                if elements are less than V, then it shows it has cycle(s), so here return true

	    if(ans.size()==V){
	        return false;
	    }
	    return true;
    }

int main() {

}