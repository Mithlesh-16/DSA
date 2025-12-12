#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        void rotate(vector<vector<int>>& matrix) {
            int start_row = 0;
            int start_col = 0;
            int end_row = matrix.size() - 1;
            int end_col = end_row;
            int cnt = matrix.size() - 1;
            int temp_cnt = 0;
    
            while (start_col < end_col) {
                while (temp_cnt < cnt) {
                    int temp_1 = matrix[start_col][start_col];
    
                    // first row Printing
                    for (int i = start_col + 1; i <= end_col; i++) {
                        int temp_2 = matrix[start_row][i];
                        matrix[start_row][i] = temp_1;
                        temp_1 = temp_2;
                    }
    
                    // last col Printing
                    for (int i = start_row + 1; i <= end_row; i++) {
                        int temp_2 = matrix[i][end_col];
                        matrix[i][end_col] = temp_1;
                        temp_1 = temp_2;
                    }
    
                    // last row Printing
                    for (int i = end_col - 1; i >= start_col; i--) {
                        int temp_2 = matrix[end_row][i];
                        matrix[end_row][i] = temp_1;
                        temp_1 = temp_2;
                    }
    
                    // first col Printing
                    for (int i = end_row - 1; i >= start_row; i--) {
                        int temp_2 = matrix[i][start_col];
                        matrix[i][start_col] = temp_1;
                        temp_1 = temp_2;
                    }
    
                    temp_cnt++;
                }
                temp_cnt = 0;
                cnt -= 2;
                start_col++;
                end_col--;
                start_row++;
                end_row--;
            }
        }
    };

int main() {

    vector<vector <int>> v1;
    v1 = {{1,2,3},{4,5,6},{7,8,9}};
    Solution S1;
    S1.rotate(v1);

return 0;
}