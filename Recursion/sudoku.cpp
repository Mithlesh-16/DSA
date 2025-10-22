#include <bits/stdc++.h>
using namespace std;







// Write a program to solve a Sudoku puzzle by filling the empty cells.

// A sudoku solution must satisfy all of the following rules:

// Each of the digits 1-9 must occur exactly once in each row.
// Each of the digits 1-9 must occur exactly once in each column.
// Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
// The '.' character indicates empty cells.







class Solution {
    bool isSafe(vector<vector<char>> &board, int row, int col, char val){
        for(int i = 0; i < board.size(); i++){

            if(board[row][i] == val) return false;

            if(board[i][col] == val) return false;

            if(board[(3*(row/3)) + i/3][(3*(col/3)) + i%3] == val) return false;
        }
        return true;
    }
    bool solve(vector<vector<char>> &board){
        
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board.size(); j++){

                if(board[i][j] == '.'){

                    for(char val = '1'; val <= '9'; val++){
                        if(isSafe(board, i, j, val)){
                            board[i][j] = val;

                            
                            if(solve(board)){
                                return true;
                            }else{
                                board[i][j] = '.';
                            }
                        }
                    }

                    return false;
                }
            }
        }
        return true;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {

        solve(board);
        
        // return;

        atexit([](){ std::ofstream("display_runtime.txt") << "0"; });
    }
};

int main() {


return 0;
}