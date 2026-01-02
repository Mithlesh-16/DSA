#include <bits/stdc++.h>
using namespace std;

class solution{

    public:
    vector<int> plus_one(vector<int> &nums){
        
        for(int i = nums.size() - 1; i >= 0; i--){
            if(nums[i] < 9){
                nums[i]++;
                return nums;
            }
            nums[i] = 0;
        }
    }

};