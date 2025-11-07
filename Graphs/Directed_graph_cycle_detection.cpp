#include <bits/stdc++.h>
using namespace std;

// in Undirected Graph, we were using only visited data structure to keep track of the visited nodes
// in Directed Graph, we have to keep track of dfsVisited data structure,
//  will mark unvisited if the dfs returns from that node

bool detect_cycle(map<int, vector<int>> &adj, int node, vector<bool> &visited, vector<bool> &dfsVisited)
{

    visited[node] = true;
    dfsVisited[node] = true;

    for(auto neighbour: adj[node]){
        if(!visited[neighbour]){
            if(detect_cycle(adj, neighbour, visited, dfsVisited)){
                return true;
            }
        }
        else if(dfsVisited[neighbour]){
            return true;
        }
    }

    dfsVisited[node] = false;
    return false;

}

bool detect_cycle_using_dfs(vector<vector<int>> &edges, int v)
{
    // creating the adjacency list
    map<int, vector<int>> adj;
    for (int i = 0; i < edges.size(); i++)
    {
        adj[edges[i][0]].push_back(edges[i][1]);
    }

    vector<bool> visited(v, false), dfsVisited(v, false);

    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            if(detect_cycle(adj, i, visited, dfsVisited)){
                return true;
            }
            
        }
    }
    return false;
}

int main()
{

    vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 0}, {2, 3}};
    cout<<detect_cycle_using_dfs(edges, 4)<<endl;

    vector<vector<int>> edges2 = {{0, 1}, {0, 2}, {1, 2}, {2, 3}};
    cout<<detect_cycle_using_dfs(edges2, 4)<<endl;

    return 0;
}