#include <bits/stdc++.h>
using namespace std;

void dfs(unordered_map<int, vector<int>> &adj, vector<int> &ans, vector<int> &discovery, vector<int> &low, unordered_map<int, bool> &visited, int parent, int node, int &timer){
    
    visited[node] = true;
    low[node] = discovery[node] = timer++;
    int child = 0;
    
    for(auto &neighbour: adj[node]){

        if(neighbour == parent) continue;
        
        if(!visited[neighbour]){
            dfs(adj, ans, discovery, low, visited, node, neighbour, timer);
            low[node] = min(low[node], low[neighbour]);
            child++;
        }
        //Check if it's articulation point
        if(low[neighbour] >= discovery[node] and parent != -1){
            ans.push_back(node);
        }
        
        //Check if there is any back edge
        if(neighbour != parent){
            low[node] = min(low[node], discovery[neighbour]);
        } 
    }  

    //check if 
    if(parent == -1 && child > 1){
        ans.push_back(node);
    }
    return;
}

//will find the articulation vertices in the given graphs
//articulation points -> the vertex which when disconnected, it will divide the graph into two or more parts
vector<int> articualtion_points(vector<vector<int>> &edges, int v, int e){
    // finding adjacency list
    unordered_map<int, vector<int>> adj;
    for(int i = 0; i< edges.size(); i++){
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }

    vector<int> ans;
    unordered_map<int, bool> visited;
    vector<int> discovery(v);
    vector<int> low(v);

    for(int i = 0; i < v; i++){
        low[i] = -1;
        discovery[i] = -1;
    }
    int timer = 0;
    int parent = -1;
    
    for(int i = 0; i< v; i++){
        if(!visited[i]){
            dfs(adj, ans, discovery, low, visited, parent, i, timer);
        }
    }

    return ans;
}

