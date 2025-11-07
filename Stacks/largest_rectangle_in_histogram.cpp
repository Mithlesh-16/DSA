#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void next_smaller_elem(vector<int> &next, vector<int> &heights){
    stack<int> s;
    for(int i = heights.size() - 1; i >= 0; i--){

        while(!s.empty() and heights[s.top()] >= heights[i]){
            s.pop();
        }

        if(!s.empty()){
            next[i] = s.top();
        }else{
            next[i] = i + 1;
        }
        
        s.push(i);
    }
}


int largest_rectangle_in_histogram(vector<int>& heights)
{
    vector<int> next(heights.size());

    next_smaller_elem(next, heights);

    int area = INT_MIN;
    
    for(int i = 0; i < heights.size(); i++){
        area = max(area, (next[i] - i)*heights[i]);
    }

    cout<<area<<endl;
}

int main()
{

    return 0;
}