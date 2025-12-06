#include <bits/stdc++.h>
using namespace std;

//trying to detect the bridge in graph 
//using the data structure low, discovery and visited

//dfs
void dfs(unordered_map<int, vector<int>> &adj, unordered_map<int, bool> &vis, vector<int> &discovery, vector<int> &low, int node, int parent, int &timer, vector<vector<int>> &result){
    vis[node] = true;
    discovery[node] = timer;
    low[node] = timer;
    
    for(auto &neighbour: adj[node]){
        if(!vis[neighbour]){
            dfs(adj, vis, discovery, low, neighbour, node, ++timer,result);
            low[node] = min(low[node], low[neighbour]);
        }

        //check if it's a bridge or not
        if(discovery[node] < low[neighbour]){
            result.push_back({node, neighbour});
        }
        
        // check if there is back edges through which will get connect to the node and reduce the low val of node
        if(vis[neighbour] and neighbour != parent){
            //Back Edge
            low[node] = min(low[node], discovery[neighbour]);
        }

        
    }

    return;

}

vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e){
    //adj list
    unordered_map<int, vector<int>> adj;
    for(int i = 0; i < edges.size(); i++){
        adj[edges[i][0]].push_back(edges[i][0]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }

    int timer = 0;
    vector<int> discovery(v);   
    vector<int> low(v);         //lowest possible time to reach the node
    int parent = -1;
    unordered_map<int, bool> vis;   //visited
    
    for(int i = 0; i < v; i++){
        discovery[i] = -1;
        low[i] = -1;
    }

    //dfs
    vector<vector<int>> result;
    for(int i = 0; i < v; i++){
        if(!vis[i]){
            dfs(adj, vis, discovery, low, i, parent, timer, result);
        }
    }
    return result;
}

