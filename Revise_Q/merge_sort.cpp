#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &nums, int start, int end){
    int mid = (start + end) /2;

    vector<int> left;
    vector<int> right;

    for(int i = start; i <= mid; i++){
        left.push_back(nums[i]);
    }

    for(int i = mid + 1; i <= end; i++){
        right.push_back(nums[i]);
    }

    int i = 0, j = 0, index = start;
    while(i < left.size() and j < right.size()){
        if(left[i] < right[j]){
            nums[index++] = left[i++];
            
        }
        else if(left[i] > right[j]){
            nums[index++] = right[j++];
        }
        else {
            nums[index++] = left[i++];
        }
    }

    while(i < left.size()){
        nums[index++] = left[i++];
    }
    while(j < right.size()){
        nums[index++] = right[j++];
    }
}

void merge_sort(vector<int> &nums, int start, int end){
    if(start >= end){
        return ;
    }

    int mid = (start + end)/2;
    merge_sort(nums, start, mid);
    merge_sort(nums, mid + 1, end);

    merge(nums, start, end);
}

int main() {
    vector<int> nums = {1, 9, 3, 2, 34, 23, 23, 89, 07, 3, 5};

    merge_sort(nums, 0, nums.size() - 1);

    for(int i = 0; i < nums.size(); i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;

return 0;
}