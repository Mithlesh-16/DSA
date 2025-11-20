#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        vector<bool> visited(adj.size(), false);
        queue<int> q;
        vector<int> ans;

        for(int i = 0; i < adj.size(); i++){
            
            if(!visited[i]){
                q.push(i);
                visited[i] = true;

                while(!q.empty()){
                    int node = q.front();
                    q.pop();
                    ans.push_back(node);

                    for(int j = 0; j < adj[node].size(); j++){
                        int index = adj[node][j];
                        if(!visited[index]){
                            q.push(index);
                            visited[index] = true;
                        }
                    }
                }
                
            }
        }
        return ans;

    }
};

int main() {


    vector<vector<int>> adj = {
        {0, 1}, {0, 2}, {1, 3}, {1, 4}
    };

    Solution s;
    vector<int> res = s.bfs(adj);

    for(int x : res) cout << x << " ";
    cout << endl;


return 0;
}