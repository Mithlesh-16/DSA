#include <bits/stdc++.h>
using namespace std;


/// @brief it is basically union find q
/// @param edges

class Solution {

    int findParent(int node, vector<int> &parent){
        if(node == parent[node]) return node;

        return parent[node] = findParent(parent[node], parent); 
    }

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n+1);
        vector<int> rank(n+1);
        for(int i = 0; i <= n; i++){
            parent[i] = i;
            rank[i] = 0;
        }

        vector<int> ans;
        for(int i = 0; i < edges.size(); i++){
            int u = findParent(edges[i][0], parent);
            int v = findParent(edges[i][1], parent);
            if(u == v){
                ans = edges[i];
                continue;
            }            
            if(rank[u] < rank[v]){
                parent[u] = v;
                rank[v]++;
            }else{
                parent[v] = u;
                rank[u]++;
            }
        }

        return ans;
        
    }
};