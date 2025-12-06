#include <bits/stdc++.h>
using namespace std;

//strongly connected components in a graph
//step 1: find topo sort
//step 2: transpose graph i.e reverse every edge direction
//step 3: apply dfs in the order of topo stack
void dfs(int node, unordered_map<int, bool> &visited, stack<int> &topo_stack, unordered_map<int, vector<int>> &adj){
    visited[node] = true;
    for(auto &nbr: adj[node]){
        if(!visited[nbr]){
            dfs(nbr, visited, topo_stack, adj);
        }
    }
    topo_stack.push(node);
}

void new_dfs(vector<int> &comp, int node, unordered_map<int, bool> &visited, unordered_map<int, vector<int>> &adj){
    visited[node] = true;
    comp.push_back(node);

    for(auto &nbr: adj[node]){
        if(!visited[nbr]){
            new_dfs(comp, nbr, visited, adj);
        }
    }
    return;
}

/// @brief directed graph is given
/// @param edges 
/// @param n 
/// @return vector<vector<int>>
vector<vector<int>> strongly_connected_comp(vector<vector<int>> &edges, int n){
    //find topological sort
    stack<int> topo_stack;
    unordered_map<int, bool> visited;
    unordered_map<int, vector<int>> adj;

    for(int i = 0; i < edges.size(); i++){
        adj[edges[i][0]].push_back(edges[i][1]);   //directed graph
    }

    for(int i = 0; i < n; i++){
        if(!visited[i]){
            dfs(i, visited, topo_stack, adj);
        }
    }

    //step2: transpose graph 
    unordered_map<int, vector<int>> transpose_adj;
    for(int i = 0; i < edges.size(); i++){
        transpose_adj[edges[i][1]].push_back(edges[i][0]);
    }

    // reset visited
    for(auto &v: visited){
        v.second = false;
    }

    //step3: 
    vector<vector<int>> ans;
    while(!topo_stack.empty()){
        int node = topo_stack.top();
        topo_stack.pop();
        
        if(!visited[node]){
            vector<int> v;
            new_dfs(v,node, visited, transpose_adj);
            ans.push_back(v);
        }
    }

    return ans;
}

int main() {

    // --------- TESTCASE 1 ----------
    cout << "\nTESTCASE 1\n";
    vector<vector<int>> edges1 = {
        {0,1},{1,2},{2,0},   // 0-1-2 cycle
        {2,3},{3,4},{4,3}    // 3-4 cycle
    };
    int n1 = 5;
    
    auto scc1 = strongly_connected_comp(edges1, n1);
    int idx = 1;
    for(auto &comp : scc1){
        cout << "SCC " << idx++ << ": ";
        for(int node : comp) cout << node << " ";
        cout << "\n";
    }

    // --------- TESTCASE 2 ----------
    cout << "\nTESTCASE 2\n";
    vector<vector<int>> edges2 = {
        {0,1},{1,2},{2,3},{3,4}
    };
    int n2 = 5;

    auto scc2 = strongly_connected_comp(edges2, n2);
    idx = 1;
    for(auto &comp : scc2){
        cout << "SCC " << idx++ << ": ";
        for(int node : comp) cout << node << " ";
        cout << "\n";
    }

    // --------- TESTCASE 3 ----------
    cout << "\nTESTCASE 3\n";
    vector<vector<int>> edges3 = {
        {1,0},{0,2},{2,1},{0,3},{3,4}
    };
    int n3 = 5;

    auto scc3 = strongly_connected_comp(edges3, n3);
    idx = 1;
    for(auto &comp : scc3){
        cout << "SCC " << idx++ << ": ";
        for(int node : comp) cout << node << " ";
        cout << "\n";
    }

    return 0;
}
