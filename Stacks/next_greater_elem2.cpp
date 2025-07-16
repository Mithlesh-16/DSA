#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> next_greater_elem(vector<int>& nums){
    int size = nums.size();
    vector<int> ans(size);
    stack<int> s;
    for(int i = 2*nums.size() - 1; i >= 0; i--){
        while(!s.empty() and s.top() <= nums[i % size]){
            s.pop();
        }

        if(s.empty()){
            ans[i % size] = -1;
        }else{
            ans[i % size] = s.top();
        }

        s.push(nums[i % size]);
    }
}

int main() {
    


return 0;
}