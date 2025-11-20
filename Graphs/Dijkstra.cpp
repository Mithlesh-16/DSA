#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int n, vector<vector<int>> &edges) {
    // Build adjacency list
    unordered_map<int, vector<pair<int,int>>> adj;
    
    for(auto &e : edges) {
        int u = e[0], v = e[1], w = e[2];
        adj[u].push_back({v, w});
        
        // if graph is undirected:
        // adj[v].push_back({u, w});
    }

    vector<int> ans(n, INT_MAX);
    ans[0] = 0; // start from node 0

    set<pair<int,int>> s;  // {distance, node}
    s.insert({0, 0});

    while(!s.empty()) {
        auto top = *(s.begin());
        s.erase(s.begin());

        int dist = top.first;
        int node = top.second;

        for(auto &neighbour : adj[node]) { 
            int adjNode = neighbour.first;
            int edgeWeight = neighbour.second;

            if(dist + edgeWeight < ans[adjNode]) {
                if(ans[adjNode] != INT_MAX) {
                    s.erase({ans[adjNode], adjNode});
                }
                ans[adjNode] = dist + edgeWeight;
                s.insert({ans[adjNode], adjNode});
            }
        }
    }

    return ans;
}

int main() {
    vector<vector<int>> edges = {
        {0,1,4}, {0,2,1}, {2,1,2}, {1,3,1}, {2,3,5}
    };

    vector<int> dist = dijkstra(4, edges);

    for(int d : dist) cout << d << " ";
    return 0;
}
