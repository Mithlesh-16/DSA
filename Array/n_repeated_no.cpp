#include <bits/stdc++.h>
using namespace std;

class solution{
    public:
    int solve(vector<int> &nums){
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(i + 1 < n && nums[i + 1] == nums[i]) return nums[i];
            if(i + 2 < n && nums[i + 2] == nums[i]) return nums[i];
            if(i + 3 < n && nums[i + 3] == nums[i]) return nums[i];
        }
        return 0;
    }
};