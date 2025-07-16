#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// class Solution {
    
    
    // private:
    vector<int> next_smaller_elem(vector<int>& heights){
        stack<int> s;
        vector<int> ans(heights.size());

        for(int i = heights.size() - 1; i >= 0; i--){
            while(!s.empty() and heights[s.top()] >= heights[i]){
                s.pop();
            }

            if(s.empty()){
                ans[i] = -1;
            }else{
                ans[i] = s.top();
            }

            s.push(i);
        }
        return ans;
    }


    vector<int> prev_smaller_elem(vector<int>& heights){
        stack<int> s;
        vector<int> ans(heights.size());

        for(int i = 0; i < heights.size(); i++){
            while(!s.empty() and heights[s.top()] >= heights[i]){
                s.pop();
            }

            if(s.empty()){
                ans[i] = -1;
            }else{
                ans[i] = s.top();
            }

            s.push(i);
        }
        return ans;
    }


    int largestRectangleArea(vector<int>& heights) {
        
        vector<int> right(heights.size());
        right = next_smaller_elem(heights);
        vector<int> left(heights.size());
        left = prev_smaller_elem(heights);


        int l = 0, b = 0, area = 0;
        for(int i = 0; i < heights.size(); i++){
            l = heights[i];
            if(right[i] == -1){
                right[i] = heights.size();
            }
            b = right[i] - left[i] - 1;
            if(area < l*b) area = l*b;
        }
        return area;
    }
   
    
//   public:
    int maxArea(vector<vector<int>> &mat) {
        
        int area = 0;
        int tmp_area = largestRectangleArea(mat[0]);
        if(area < tmp_area) 
            area = tmp_area;
        for(int i = 1; i < mat.size(); i++){
            for(int j = 0; j < mat[0].size(); j++){
                
                    if(mat[i][j])
                        mat[i][j] += mat[i-1][j];
                    else
                        mat[i][j] = 0;
                
            }
            tmp_area = largestRectangleArea(mat[i]);
            if(area < tmp_area)
                area = tmp_area;
        }
        
        
        return area;
    }
// };

int main() {
    vector<vector<int>> mat = 
        {{0,1,1,0},
         {1,1,1,1},
         {1,1,1,1},
         {1,1,0,0}};
         
    cout << maxArea(mat) << endl;
    
    return 0;
}