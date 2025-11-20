#include <bits/stdc++.h>
using namespace std;

void top_sort_util(map<int, vector<int>> &adj, int node, vector<bool> &visited, stack<int> &ans){

    visited[node] = true;

    for(auto neighbour: adj[node]){

        if(!visited[neighbour]){
            top_sort_util(adj, neighbour, visited, ans);
        }

    }

    // catch 
    ans.push(node);
    return ;
}

vector<int> topological_sort(vector<vector<int>> &edges, int v, int e){

    //creating adjacency list
    map<int, vector<int>> adj;
    for(int i = 0; i < edges.size(); i++){
        adj[edges[i][0]].push_back(edges[i][1]);
    }

    vector<bool> visited(v, false);
    stack<int> s;
    
    for(int i = 0; i < v; i++){
        if(!visited[i]){
            top_sort_util(adj, i, visited, s);
        }
    }

    for(int i = 0; i < v; i++){
        cout<<s.top()<<" ";
        s.pop();
    }

    cout<<endl;

}

int main() {

    vector<vector<int>> edges = {{}};
    topological_sort(edges, 4, 5);

return 0;
}