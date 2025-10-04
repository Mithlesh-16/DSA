#include <iostream>
#include <bits/stdc++.h>
using namespace std;






// 632. Smallest Range Covering Elements from K Lists

// You have k lists of sorted integers in non-decreasing order. 
// Find the smallest range that includes at least one number from each of the k lists.

// We define the range [a, b] is smaller than range [c, d] if b - a < d - c or a < c if b - a == d - c.

 

// Example 1:

// Input: nums = [[4,10,15,24,26],[0,9,12,20],[5,18,22,30]]
// Output: [20,24]
// Explanation: 
// List 1: [4, 10, 15, 24,26], 24 is in range [20,24].
// List 2: [0, 9, 12, 20], 20 is in range [20,24].
// List 3: [5, 18, 22, 30], 22 is in range [20,24].

// Example 2:

// Input: nums = [[1,2,3],[1,2,3],[1,2,3]]
// Output: [1,1]








class node{
    public:
    int i;
    int j;
    int data;
    node(int i, int j, int data){
        this -> i = i;
        this -> j = j;
        this -> data = data;
    }
};

class compare{
    public:
    bool operator()(node* a, node* b){
        return a -> data > b -> data;
    }
};


class solution{
    public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<int> ans;
        //here, compare is a comparator function
        priority_queue<node*, vector<node*>, compare> minHeap;

        //step 1: 
        int maxi = INT_MIN;
            int mini = 0;
            int ans_min = INT_MAX;
            int ans_max = INT_MIN;
            int range = INT_MAX;

            //step 1:
            for(int i = 0; i < nums.size(); i++){
                maxi = max(maxi, nums[i][0]);
                minHeap.push(new node(i, 0, nums[i][0]));
            }

            while(!minHeap.empty()){
                node* top = minHeap.top();
                mini = top -> data;
                minHeap.pop();
                int i = top -> i;
                int j = top -> j;

                if(range > maxi - mini or(range == maxi - mini and ans_min > mini)){
                    ans_min = mini;
                    ans_max = maxi;
                    range = maxi - mini;
                }

                if(j + 1 < nums[i].size()){
                    maxi = max(maxi, nums[i][j + 1]);
                    minHeap.push(new node(i, j + 1, nums[i][j + 1]));
                }
                else break;  
            }

            ans.push_back(ans_min);
            ans.push_back(ans_max);
            return ans;
    }

};

int main() {


return 0;
}