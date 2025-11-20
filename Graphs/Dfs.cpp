#include <bits/stdc++.h>
using namespace std; 

void dfsUtil(map<int, vector<int>> &adj, vector<int>&ans, vector<bool> &visited, int node){     
    
    visited[node] = true;
    ans.push_back(node);

    for(auto neighbour: adj[node]){
        if(!visited[neighbour]){
            cout<<"node : "<<neighbour<<endl;
            dfsUtil(adj, ans, visited, neighbour);

        }

    }

    return ;
}

void dfs(vector<vector<int>> &edges, int v){
    //first of all, build adjacency list
    map<int, vector<int>> adj;

    for(int i = 0; i < edges.size(); i++){
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }
    cout<<"adj_list created !!"<<endl;

    vector<bool> visited(v, false);
    vector<int> ans;
    for(int i = 0; i < v; i++){
        if(!visited[i]){
            cout<<"node : "<<i<<endl;
            dfsUtil(adj, ans, visited, i);
        }
    }


    //printing the dfs Traversal
    cout<<"ans : ";
    for(int i = 0; i < v; i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;

}

int main(){

    vector<vector<int>> edges = {{0, 1}, {1, 3}, {3, 2}, {2, 0}};
    dfs(edges, 4);

    vector<vector<int>> edges2 = {{0, 2}, {3, 1}, {4, 2}, {1, 4}, {5, 6}};
    dfs(edges2, 7);

    return 0;
}