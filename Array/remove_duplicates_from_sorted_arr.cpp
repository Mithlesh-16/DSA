#include <iostream>
using namespace std;

//there can be atmost 2 same element if present in original array
int remove_duplicates(int* nums, int n){
    
    int insert_index = 1, cnt = 0;   /// insert_index gives the index where the next element will be inserted 
    
    for(int i = 1; i < n; i++){
        if(nums[i] != nums[i - 1] and cnt){
            cnt = 0;
            nums[insert_index++] = nums[i - 1];
            nums[insert_index++] = nums[i];
        }
        else if(nums[i] != nums[i - 1]){
            nums[insert_index++] = nums[i]; 
        }
        else{
            cnt++;
        }
    }
    if(cnt){
        nums[insert_index++] = nums[n - 1];
    }
    return insert_index;
}

int main() {

    int n;
    cout<<"Enter the size of Array : "<<endl;
    cin>>n;
    int arr[n];

    //inserting values
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    //displaying final array
    int size = remove_duplicates(arr, n);
    for(int i = 0; i < size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;


    return 0;
}