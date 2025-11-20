#include <bits/stdc++.h>
using namespace std;

//topological sort -> only on Directed Acyclic Graphs 

// Kahn's Algo :
// i> make vector showing indegree of every element
// ii> push those elements whose indegrees = zero into queue
// iii> pop and add to the ans vector
// iv> see the adj list and decrease the indegrees of the neighbours by 1
// v> Again, Repeat the same

vector<int> topological_sort(vector<vector<int>> &edges, int v){

    //create adj list 
    map<int, vector<int>> adj;

    for(int i = 0; i < edges.size(); i++){
        adj[edges[i][0]].push_back(edges[i][1]);
    }

    //create the indegree vector
    vector<int> indegree(v);
    for(auto i: adj){
        for(auto j : i.second){
            indegree[j]++;
        }
    }
    
    queue<int> z_queue;
    vector<int> ans;
    int zero_cnt = 0;
    
        for(int i = 0; i < v; i++){
            if(indegree[i] == 0){
                z_queue.push(i);
            }
        }

        while(!z_queue.empty()){
            int tmp = z_queue.front();
            z_queue.pop();

            ans.push_back(tmp);
            for(auto neighbour: adj[tmp]){
                indegree[neighbour] -= 1;
                if(indegree[neighbour] == 0){
                    z_queue.push(neighbour);
                }
            }
            
        }   
        
    return ans;

}

int main() {

    vector<int> ans = {};


return 0;
}