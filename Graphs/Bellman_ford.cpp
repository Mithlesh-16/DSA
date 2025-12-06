#include <bits/stdc++.h>
using namespace std;

//given graph can have negative weights
vector<int> shortest_path(vector<vector<int>> &edges, int n, int src){
    vector<int> dist(n, 1e9);
    dist[src] = 0;

    //step 1: relax edges n - 1 times
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < edges.size(); j++){
            int u = edges[j][0];
            int v = edges[j][1];
            int weight = edges[j][2];

            if(dist[u] != 1e9 and dist[v] > dist[u] + weight){
                dist[v] = dist[u] + weight;
            }

        }
    }

    //step 2 : check for negative cycle present or not
    for(int i = 0; i < edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];
        int weight = edges[i][2];

        if(dist[u] != 1e9 and dist[v] > dist[u] + weight){
            cout<<"Negative Cycle is present!!"<<endl;
            return {};
        }

    }
    return dist;
}

int main() {


return 0;
}