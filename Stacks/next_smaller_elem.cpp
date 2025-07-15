#include <iostream>
#include <vector>
#include <stack>
using namespace std;
vector<int> find_next_smaller_element(vector<int>& arr, int n){
    vector<int> ans(n);
    stack <int> s;
    s.push(-1);
    for(int i = arr.size() - 1; i >= 0; i--){
        while(!s.empty() and s.top() >= arr[i]){
            s.pop();
        }    
        ans.push_back(s.top());

        s.push(arr[i]);
    }

    return ans;
}
int main() {

    

return 0;
}