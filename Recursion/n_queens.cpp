#include <bits/stdc++.h>
using namespace std;







// The n-queens puzzle is the problem of placing n queens on an n x n chessboard 
// such that no two queens attack each other.

// Given an integer n, return all distinct solutions to the n-queens puzzle. 
// You may return the answer in any order.

// Each solution contains a distinct board configuration of the n-queens' placement, 
// where 'Q' and '.' both indicate a queen and an empty space, respectively.






class Solution {
public:
    bool isSafe(map<int, int> &mp, int row, int col){

        for(auto & i: mp){
            int j = abs(i.first - row);
            int k = abs(i.second - col);

            if(j == k or ( k == 0 and j)){
                return false;
            }
        }

        return true;
    }

    void solve(vector<vector<string>> &ans,  vector<string> &curr, int n, int cnt, int row, map<int, int> &mp){
        if(cnt == n){
            ans.push_back(curr);
            return ;
        }

        for(int i = 0; i< n; i++){
            if(isSafe(mp, row, i)){
                curr[row][i] = 'Q';
                mp[row] = i;
                solve(ans, curr, n, cnt+1, row+1, mp);

                //backtracking
                mp.erase(row);
                curr[row][i] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;

        vector<string> curr;
        string tmp = "";
        map<int, int> mp;

        for(int i = 0; i < n; i++){
            tmp+= ".";
        }
        for(int i = 0; i < n; i++){
            curr.push_back(tmp);
        }
        
        solve(ans, curr, n, 0, 0, mp);

        return ans;
    }
};

int main() {

    

return 0;
}