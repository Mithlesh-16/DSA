#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(vector<vector<int>> &edges, int V){

    //adjacency list
    unordered_map<int, vector<pair<int, int>>> adj;
    for(int i = 0; i < edges.size(); i++){
        adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
    }   
    
    set<pair<int, int>> s;
    s.insert({0, 0});
    vector<int> dist(V, INT_MAX);
    dist[0] = 0;

    while(!s.empty()){
        pair<int, int> tmp = *s.begin();
        int node = tmp.second;
        int weight = tmp.first;
        s.erase(s.begin());
        
        for(auto neighbour: adj[node]){
            if(dist[neighbour.first] > dist[node] + neighbour.second){
                if(dist[neighbour.first] != INT_MAX){
                    s.erase({dist[neighbour.first], neighbour.first});
                }
                dist[neighbour.first] = dist[node] + neighbour.second;
                s.insert({dist[neighbour.first], neighbour.first});
            }
        }

    }
    return dist;
}

int main() {


return 0;
}