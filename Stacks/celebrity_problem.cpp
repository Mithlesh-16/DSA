#include <iostream>
#include <vector>
#include <stack>
using namespace std;





// A celebrity is a person who is known to all but does not know anyone at a party. 
// A party is being organized by some people. 
// A square matrix mat[][] of size n*n is used to represent people at the party 
// such that if an element of row i and column j is set to 1 it means ith person knows jth person. 
// You need to return the index of the celebrity in the party, if the celebrity does not exist, return -1.

// Note: Follow 0-based indexing.

// Examples:

// Input: mat[][] = [[1, 1, 0],
//                 [0, 1, 0],
//                 [0, 1, 1]]
// Output: 1
// Explanation: 0th and 2nd person both know 1st person and 1st person does not know anyone. Therefore, 1 is the celebrity person.

// Input: mat[][] = [[1, 1], 
//                 [1, 1]]
// Output: -1
// Explanation: Since both the people at the party know each other. Hence none of them is a celebrity person.

// Input: mat[][] = [[1]]
// Output: 0

// Constraints:
// 1 ≤ mat.size() ≤ 1000
// 0 ≤ mat[i][j] ≤ 1
// mat[i][i] = 1

// Expected Complexities
// Time Complexity: O(n)
// Auxiliary Space: O(1)

class Solution {
  public:
    int celebrity(vector<vector<int> >& mat) {
        stack<int> s;
         
        for(int i = 0; i < mat.size(); i++){
            s.push(i);
        }
        
        int a = 0, b = 0;
        while(s.size() > 1){
            a = s.top();
            s.pop();
            b = s.top();
            s.pop();
            
            if(mat[a][b] == 1){
                s.push(b);
            }
            else{
                s.push(a);
            }
        }
        
        // step3: verify top elem
        //row check
        
        int candidate = s.top();
        int zero_cnt = 0;
        for(int i = 0; i < mat.size(); i++){
            if(mat[candidate][i] == 0) 
                zero_cnt++;
            
        }
        if(zero_cnt != mat.size() - 1) 
            return -1;
        
        //col check
        for(int i = 0; i < mat.size(); i++){
            if(mat[i][candidate] == 0) 
                return -1;
        }
        
        return candidate;
    }
};

int main() {


return 0;
}