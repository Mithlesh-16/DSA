#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        void moveZeroes(vector<int>& nums) {
            int size = nums.size(),lastIndx=0;
            for(int i =0;i<size;i++){
                if(nums[i]!=0 && lastIndx != i){
                    nums[lastIndx] = nums[i];
                    nums[i] = 0;
                    lastIndx++;
                }else if(nums[i] != 0){
                    lastIndx ++;
                }
            }
        }
    };
    int main(){
        cout<<"Done";
        return 0;
    }