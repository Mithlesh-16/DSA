#include <bits/stdc++.h>
using namespace std;

int find_parent(int node, vector<int> &parent){
    if(parent[node] == node){
        return node;
    }
    return parent[node] = find_parent(parent[node], parent);
}

void union_set(vector<int> &parent, vector<int> &rank, int u, int v){

    u = find_parent(u, parent);
    v = find_parent(v, parent);

    if(rank[u] < rank[v]){
        parent[u] = v;
        rank[v]++;
    }
    else if(rank[u] >= rank[v]){
        parent[v] = u;
        rank[u]++;
    }
}

void makeSet(vector<int> &parent, vector<int>& rank, int size){
    for(int i = 0; i < size; i++){
        parent[i] = i;
        rank[i] = 0;
    }
}

bool comp(vector<int> &a, vector<int> &b){
    return a[2] < b[2];
}

int kruskal_algo(vector<vector<int>> &edges, int V){
    
    vector<int> parent(V);
    vector<int> rank(V, 0);
    makeSet(parent, rank, V);

    sort(edges.begin(), edges.end(), comp);
    int minWt = 0;

    for(int i = 0; i < edges.size(); i++){
        int u = find_parent(edges[i][0], parent);
        int v = find_parent(edges[i][1], parent);

        int wt = edges[i][2];

        if(u != v){
            minWt += wt;
            union_set(parent, rank, u, v);
        }
    }
    return minWt;
}

int main() {

    return 0;
}