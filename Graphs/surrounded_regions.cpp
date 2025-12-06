#include <bits/stdc++.h>
using namespace std;

class Solution {
    int dRow[4] = {1, 0, -1, 0};
    int dCol[4] = {0, 1, 0, -1};

    void dfs(int row, int col, vector<vector<bool>> &visited, vector<vector<char>> &board){
        visited[row][col] = true;
        board[row][col] = '#';
        int m = board.size();
        int n = board[0].size();

        for(int i = 0; i < 4; i++){
            int nRow = row + dRow[i];
            int nCol = col + dCol[i];
            
            if(nRow < m and nRow >= 0 
                and nCol < n and nCol >= 0 
                and !visited[nRow][nCol] 
                and board[nRow][nCol] == 'O'){
                    dfs(nRow, nCol, visited, board);
            }
        }
        return;
    }
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        vector<vector<bool>> visited(m, vector<bool> (n, false));
        
        for(int i = 0; i < m; i++){
            if(board[i][0] == 'O')
            dfs(i, 0, visited, board);
            if(board[i][n - 1] == 'O')
            dfs(i, n-1, visited, board);
        }

        for(int i = 0; i < n; i++){
            if(board[0][i] == 'O')
            dfs(0, i, visited, board);
            if(board[m - 1][i] == 'O')
            dfs(m - 1, i, visited, board);
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == 'O') board[i][j] = 'X';
                else if(board[i][j] == '#') board[i][j] = 'O';
            }
        }
        return;
    }
};