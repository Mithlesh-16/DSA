#include <bits/stdc++.h>
using namespace std;

class Solution {
    int left_cnt(int mid, vector<int> &nums){
        int cnt = 0, mid_cnt = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] <= mid){
                cnt++;
            }
        }
        return cnt;
    }
public:
    int findDuplicate(vector<int>& nums) {
        //applying binary search on the no from 1 to n, rather than on index
        int start = 1, end = nums.size();
        while(start <= end){
            int mid = start + (end - start)/2;
            
            //count which side of the mid has higher no of values present
            int cnt = left_cnt(mid, nums);
            if(cnt > mid){
                end = mid - 1;
            }else{
                start = mid + 1;
            }
        }
        return start;
    }

    int findDuplicate_using_cycle(vector<int> &nums){
        int slow = nums[0];
        int fast = nums[nums[0]];

        while(slow != fast){       //to find the intersection of the cycle
            slow = nums[slow];
            fast = nums[nums[fast]];
        }

        slow = 0;   
        while(slow != fast){        //to find the entry point of cycle
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};

