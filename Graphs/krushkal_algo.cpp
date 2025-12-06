#include <bits/stdc++.h>
using namespace std;


int findParent(vector<int> &parent, int node){
    if(parent[node] == node){
        return node;
    }
    return parent[node] = findParent(parent, parent[node]);
}

void unionSet(int u, int v, vector<int> &parent, vector<int> &rank){
    u = findParent(parent, u);
    v = findParent(parent, v);

    if(rank[u] < rank[v]){
        parent[u] = v;
        rank[v]++;
    }else{
        parent[v] = u;
        rank[u]++;
    }
}

//comparator function for comparing the edges weights
bool cmp(vector<int> &a, vector<int> &b){
    return a[2] < b[2];
}

int minimumSpanningTree(vector<vector<int>> &edges, int n){
    vector<int> parent(n);
    vector<int> rank(n);
    for(int i = 0; i < n; i++){
        parent[i] = i;
        rank[i] = 0;
    }
    //edges -> u-v-weight
    //sort according to the weight of the edges 
    sort(edges.begin(), edges.end(), cmp);
    int min_weight = 0;

    for(int i = 0; i < edges.size(); i++){
        int u = findParent(parent, edges[i][0]);
        int v = findParent(parent, edges[i][1]);
        if(u != v){
            unionSet(u, v, parent, rank);
            min_weight += edges[i][2];
        }
    }

    return min_weight;

}

int main() {


return 0;
}