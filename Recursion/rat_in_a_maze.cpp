#include <bits/stdc++.h>
using namespace std;

class Solution {
    void solve(vector<vector<int>> &maze, vector<string> &ans, string output, int k, int l){
        
        //base case
        if(k >= maze.size()-1 && l >= maze.size()-1){
            ans.push_back(output);
            return ;
        }
        
        // recursive calls
          maze[k][l] = 0;   //to ensure that it is not revisited
            
            //down
            if(k+1 < maze.size() and maze[k+1][l]){
                output.push_back('D');
                solve(maze, ans, output, k+1, l);
              
                
                //backtracking
                output.pop_back();
                maze[k+1][l] = 1;
            }
            
            //up
            if(k - 1 >= 0 and maze[k-1][l]){
                output.push_back('U');
                solve(maze, ans, output, k-1, l);
                
                //backtracking
                output.pop_back();
                maze[k-1][l] = 1;
            }
            
            //Right
            if(l+1 < maze.size() and maze[k][l+1]){
                output.push_back('R');
                solve(maze, ans, output, k, l+1);
                
                //backtracking
                output.pop_back();
                maze[k][l+1] = 1;
            }
            
            //left
            if(l-1 >= 0 and maze[k][l-1]){
                output.push_back('L');
                solve(maze, ans, output, k, l-1);
                
                //backtracking
                output.pop_back();
                maze[k][l-1] = 1;
            }
            
            // maze[k][l] = 1;
        // }
        
    }
  public:
    vector<string> ratInMaze(vector<vector<int>> & maze) {
        // code here
        vector<string> ans;
        solve(maze, ans,"", 0, 0);
        sort(ans.begin(), ans.end());
        return ans;
    }
};

int main(){

    return 0;
}