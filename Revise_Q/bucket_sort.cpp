#include <bits/stdc++.h>
using namespace std;

void bucket_sort(vector<int> &nums){
    int bucket_size = nums.size();
    int arr[10][bucket_size] = {0};
    
    int max_val = *max_element(nums.begin(), nums.end());
    int count_digits = 0;
    while(max_val > 0){
        count_digits++;
        max_val = max_val/10;
    }

    cout<<count_digits<<endl;

    //no of iterations will be equal to max no of digits
    for(int i = 0; i < count_digits; i++){
        
        
        
    }
    
}

int main() {

    


return 0;
}