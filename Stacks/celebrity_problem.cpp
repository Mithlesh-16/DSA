#include <iostream>
#include <vector>
#include <stack>
using namespace std;

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