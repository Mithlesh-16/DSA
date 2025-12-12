#include <bits/stdc++.h>
using namespace std;

class Solution {
    double dfs(string &start, string &end, unordered_map<string, bool> &visited, unordered_map<string, vector<pair<string, double>>> &adj){
        if(start == end){
            visited[end] = true;
            return 1;
        }

        visited[start] = true;
        double res = -1;
        for(auto &nbr: adj[start]){
            if(!visited[nbr.first]){

                double tmp = dfs(nbr.first, end, visited, adj);
                if(tmp != -1) res = nbr.second* tmp;
                if(start == end) return res;
            }
        }
        return res;
    }
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>> adj;
        vector<double> ans;

        for(int i = 0; i < equations.size(); i++){
            adj[equations[i][0]].push_back({equations[i][1], values[i]});
            adj[equations[i][1]].push_back({equations[i][0], 1/values[i]});
        }

        for(int i = 0; i < queries.size(); i++){
            vector<string> query = queries[i];
            if(adj.find(query[0]) == adj.end() || adj.find(query[1]) == adj.end()){
                ans.push_back(-1);
                continue;
            }

            unordered_map<string, bool> visited;    
            ans.push_back(dfs(query[0], query[1], visited, adj));
        }

        return ans;
    }
};