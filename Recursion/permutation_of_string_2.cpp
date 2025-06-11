#include <iostream>
#include <vector> 
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

class solution{
    private:
        void solve(vector<int> &nums, vector<vector<int>> &ans, int index){
            
            //base case
            if(index >= nums.size()){
                ans.push_back(nums);
                return;
            }

            //recursive call
            for(int i = index; i < nums.size(); i++){
                swap(nums[index], nums[i]);
                solve(nums, ans, index + 1);

                //backtracking
                swap(nums[index], nums[i]);
            }
        }

    public:
        vector<vector<int>> permut(vector<int> &nums){
            vector<vector<int>> ans;
            solve(nums, ans, 0);

            return ans;
        }


};

int main() {

    int size = 0;
    cin>> size;
    vector<int> nums(size,0);
    for(int i = 0; i < size; i++){
        cin>>nums[i];
    }

    //solution object 
    solution S1;
    S1.permut(nums);

return 0;
}