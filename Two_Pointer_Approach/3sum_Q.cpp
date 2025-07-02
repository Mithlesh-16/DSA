#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        sort(nums.begin(), nums.end());
        int i = 0, j = nums.size() - 1;

        vector<vector<int>> ans;
        while (i < nums.size()) {
            while (i < j) {
                if (i > 0 && nums[i] == nums[i - 1])
                    break;
                if (nums[i] <= 0 && nums[j] >= 0) {
                    if (binary_search(nums.begin() + i + 1, nums.begin() + j,
                                      -(nums[i] + nums[j]))) {
                        ans.push_back({nums[i], nums[j], -(nums[i] + nums[j])});
                    }
                }
                while (j < nums.size() && j > 0 && nums[j] == nums[j - 1]) {
                    j--;
                }
                j--;
            }
            j = nums.size() - 1;
            i++;
        }

        return ans;
    }
};

int main() {


return 0;
}