#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class solution{
    public:

    //space complexity : o(k); -> with heap
    //space complexity : o(n^2); -> without using heap
    
        int kth_largest_sum(vector<int>& nums, int k){
            priority_queue<int, vector<int>, greater<int>> mini;

            for(int i = 0; i < nums.size(); i++){
                int sum = 0;
                for(int j = i; j < nums.size(); j++){
                    sum += nums[j];
                    if(mini.size() < k){
                        mini.push(sum);
                    }
                    else{
                        if(sum > mini.top()){
                            mini.pop();
                            mini.push(sum);
                        }
                    }
                }
            }
            return mini.top();
        }
};

int main() {


return 0;
}