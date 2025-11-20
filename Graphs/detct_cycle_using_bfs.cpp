#include <bits/stdc++.h>
using namespace std;

//Kahn's algo
void cycle_detection_using_bfs(vector<vector<int>> &edges, int v){
    //building adjacency list 
    map<int, vector<int>> adj;
    for(int i = 0; i < edges.size(); i++){
        adj[edges[i][0]].push_back(edges[i][1]);
    }


    queue<int> q;

    //counting indegrees
    vector<int> indegree(v, 0);
    for(auto i: adj){
        for(auto j : i.second){
            indegree[j] += 1;
        }
    }

    for(int i = 0; i < v; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }

    int cnt = 0; 
    while(!q.empty()){
        int tmp = q.front();
        q.pop();
        cnt++;

        for(auto i: adj[tmp]){
            indegree[i]--;
            if(indegree[i] == 0) q.push(i);
        }
    }

    if(cnt == v){
        cout<<"No"<<endl;
    }else{
        cout<<"Yes"<<endl;
    }
    
}


int main() {


return 0;
}