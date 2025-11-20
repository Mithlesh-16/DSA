#include <bits/stdc++.h>
using namespace std;

vector<int> shortest_path(vector<vector<int>> &edges, int v, int start_node, int end_node) {
    
    // Step 1: Create adjacency list
    unordered_map<int, vector<int>> adj;
    for (auto &edge : edges) {
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
    }

    // Step 2: BFS setup
    vector<bool> visited(v, false);
    vector<int> parent(v, -1);
    queue<int> q;

    q.push(start_node);
    visited[start_node] = true;

    // Step 3: BFS traversal
    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (auto neighbour : adj[node]) {
            if (!visited[neighbour]) {
                visited[neighbour] = true;
                parent[neighbour] = node;
                q.push(neighbour);
            }
        }
    }

    // Step 4: Backtrack from end_node to start_node
    vector<int> path;
    int current = end_node;

    while (current != -1) {
        path.push_back(current);
        current = parent[current];
    }

    reverse(path.begin(), path.end());

    // Step 5: If start_node is not reachable
    if (path.front() != start_node)
        return {}; // return empty vector

    return path;
}

int main() {
    vector<vector<int>> edges = {
        {0, 1}, {1, 2}, {2, 3}, {0, 4}, {4, 5}, {5, 3}
    };
    int v = 6;
    int start_node = 0, end_node = 3;

    vector<int> path = shortest_path(edges, v, start_node, end_node);

    cout << "Shortest Path: ";
    for (int node : path) cout << node << " ";
}
