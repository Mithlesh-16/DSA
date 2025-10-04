#include <iostream>
#include <bits/stdc++.h>
using namespace std;

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

class comparator{
    public:
    bool operator()(node* a, node* b){
        return a -> data > b -> data;
    }

};


class Solution{

    public:
    vector<int> merge_k_sorted_arrays(vector<vector<int>> arr){
        vector<int> ans;
        priority_queue<node*, vector<node*>, comparator> minHeap;

        //step 1: push the first element of every array into minHeap;
        for(int i = 0; i < arr.size(); i++){
            node* tmp = new node(i, 0, arr[i][0]);
            minHeap.push(tmp);
        }

        //step 2 : run while loop untill the size of heap becomes zero
        while(minHeap.size()){
            node* tmp = minHeap.top();
            ans.push_back(tmp -> data);
            minHeap.pop();

            int i = tmp -> i;
            int j = tmp -> j;

            if(j+1 < arr[i].size()){
                minHeap.push(new node(i, j + 1, arr[i][j+1]));
            }
        }

        return ans;

    }

};

int main() {


return 0;
}