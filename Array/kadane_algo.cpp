#include <iostream>
using namespace std;

int max_subarr_sum(vector<int> &arr){
    int sum = INT_MIN, curr_sum = 0;
    
    for(int i = 0; i < arr.size();i++){
        curr_sum += arr[i];
        sum = max(sum, curr_sum);
        if(curr_sum < 0) curr_sum =0;
    
    }

    return sum;

}