#include <bits/stdc++.h>
using namespace std;


//sort array according to the no formed by reversing the binary of any element of array

class Solution {
    int reflect(int x){
        int r = 0;
        while(x > 0){
            r = (r << 1) | (x & 1);
            x >>= 1;
        }

        return r;
    }
public:
    vector<int> sortByReflection(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [&] (int a, int b){
            int ra = reflect(a);
            int rb = reflect(b);

            return (ra < rb) || (ra == rb && a < b);
        });

        return nums;
    }
};