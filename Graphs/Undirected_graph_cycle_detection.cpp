#include <bits/stdc++.h>
using namespace std;

class Solution
{

public:
    bool isCycle(int V, vector<vector<int>> &edges)
    {

        queue<pair<int, int>> q;
        vector<bool> visited(V, false);
        vector<vector<int>> adj(V);

        // Build adjacency list
        for (int i = 0; i < edges.size(); i++)
        {

            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        for (int i = 0; i < V; i++)
        {

            if (!visited[i])
            {
                visited[i] = true;
                q.push({i, -1});

                while (!q.empty())
                {
                    pair<int, int> tmp = q.front();
                    int node = tmp.first;

                    q.pop();

                    for (int neighbour : adj[node])
                    {
                        if (visited[neighbour] and neighbour != tmp.second)
                        {
                            return true;
                        }
                        if (!visited[neighbour])
                        {

                            visited[neighbour] = true;
                            q.push({neighbour, node});
                        }
                    }
                }
            }
        }

        return false;
    }

    bool isCycle2(int node, int parent, vector<bool> &visited, vector<vector<int>> &adj)
    {
        
        visited[node] = true;

        for(auto neighbour: adj[node]){
            if(!visited[neighbour]){
                if(isCycle2(neighbour, node, visited, adj)) return true;
            }
            else if(parent != neighbour){
                return true;
            }
        }

        return false;
    }

    bool isCyclicDFS(int V, vector<vector<int>> &edges)
    {

        vector<bool> visited(V, false);
        queue<pair<int, int>> q;
        vector<vector<int>> adj(V);

        // create adjacency list
        for (int i = 0; i < V; i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        for(int i = 0; i < V; i++){
            if(!visited[i]){
                bool ans = isCycle2(i, -1, visited, adj);
                return ans;
            }
        }


        return false;
    }
};

int main()
{
}