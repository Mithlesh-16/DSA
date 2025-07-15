#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> next_greater_elem(vector<int> arr, int n){
    vector<int> ans(n);
    stack<int> s;
    for(int i = arr.size() - 1; i >= 0; i--){
        while(!s.empty() and s.top() <= arr[i]){
            s.pop();
        }
        
        if(s.empty()) 
            ans[i] = -1;
        else
            ans[i] = s.top();

        s.push(arr[i]);
    } 
    return ans;
}

int main() {


return 0;
}