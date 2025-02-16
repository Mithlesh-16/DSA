#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int searchInsert(vector<int>& nums, int target) {
            int size = nums.size(), start = 0, end = size - 1,
            mid = start + (end - start) / 2,index=-1;
            if(target<nums[0]){
                    return 0;
                }
            if(target > nums[size-1]){
                    return size;
                }
            while (start <= end) {
                if (nums[mid] == target) {
                    return mid;
                }
                if (nums[mid] < target) {
                    if(mid<=size-2 && target<nums[mid+1]){
                        index = mid+1;
                    }
                    start = mid + 1;
                } else {
                    if(mid>=1 && target>nums[mid-1]){
                        index = mid;
                    }
                    end = mid - 1;
                }
                
                mid = (start + end)/ 2;
            }
            return index;
        }
    };
    int main(){
        cout<<"Done";
        return 0;
    }