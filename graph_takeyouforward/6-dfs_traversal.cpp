#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=dfs_of_graph

//algorithm that usually goes to depth and comes back is recursion
// so we will use recursion here to traverse it in depth

void dfsTraversal(vector<int>adj[],int start,int vis[],vector<int>&dfs){
        vis[start]=1;
        dfs.push_back(start);
        // traverse all its neighbours
        for(auto it : adj[start]){
            if(vis[it]==0)
            dfsTraversal(adj,it,vis,dfs);
        }
}

// Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        int vis[V]={0};
        int start=0;
        vector<int>dfs;
        dfsTraversal(adj,start,vis,dfs);
        return dfs;
}

// space complexity = O(3N) ~ O(N), Space for dfsTraversal recursion stack space, vis array and an adjacency list
// time complexity =  For an undirected graph, O(N) + O(2E), For a directed graph, O(N) + O(E)
//                    Because for every node we are calling the recursive function once, the time taken is O(N)
//                and 2E is for total degrees as we traverse for all adjacent nodes.


int main() {

}