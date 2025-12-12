#include <bits/stdc++.h>
using namespace std;

vector<int> prims(vector<vector<int>> &edges, int V){
    
    //adjacency list
    unordered_map<int, vector<pair<int, int>>> adj;
    for(int i = 0; i < edges.size(); i++){
        adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
        adj[edges[i][1]].push_back({edges[i][0], edges[i][2]});
    }

    vector<bool> inMst(V, false);
    vector<int> keys(V, INT_MAX);
    vector<int> parent(V, -1);

    set<pair<int, int>> s;
    s.insert({0, 0});
    keys[0] = 0;            //starting node

    while(!s.empty()){
        int node = s.begin() -> second;
        s.erase(s.begin());
        inMst[node] = true;

        
        for(auto neighbour: adj[node]){
            if(!inMst[neighbour.first] and keys[neighbour.first] > neighbour.second){
                if(keys[neighbour.first] != INT_MAX){
                    s.erase({keys[neighbour.first], neighbour.first});
                }
                keys[neighbour.first] = neighbour.second;
                s.insert({keys[neighbour.first], neighbour.first});
                parent[neighbour.first] = node;
            }
        }
    }

    return parent;

}

int main() {


return 0;
}