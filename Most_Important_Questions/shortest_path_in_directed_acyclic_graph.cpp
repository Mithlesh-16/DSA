#include <bits/stdc++.h>
using namespace std;

void dfs(vector<bool> &visited, int node, stack<int> &s, unordered_map<int, vector<pair<int,int>>> &adj){
    visited[node] = true;

    for(auto neighbour: adj[node]){
        if(!visited[neighbour.first]){
            dfs(visited, neighbour.first, s, adj);
        }
    }
    s.push(node);
}

vector<int> shortestPathInDAG(int n, int m, vector<vector<int>> &edges)
{
    //create adjacency list
    unordered_map<int, vector<pair<int, int>>> adj;
    
    for(int i = 0; i < edges.size(); i++){
        adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
    }

    //finding topological order 
    stack<int> s;
    vector<bool> visited(n, false);
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            dfs(visited, i, s, adj);
        }
    }

    // Finding the ans :- 
    vector<int> ans(n, -1);
    ans[0] = 0;

    while(!s.empty()){
        int node = s.top();
        s.pop();

        if(ans[node] != -1){
            for(auto neighbour: adj[node]){

                int sum = ans[node] + neighbour.second;

                if(ans[neighbour.first] == -1){
                    ans[neighbour.first] = sum;
                }
                else if(ans[neighbour.first] > sum){
                    ans[neighbour.first] = sum;
                }
            }
        }
    }

    return ans;

}


int main(){

    


    return 0;
}
