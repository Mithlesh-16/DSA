#include <iostream>
#include <vector>
using namespace std;

void merge_both(int arr[], int s, int e){

    int mid = s + (e - s)/2;
    //make 2 temporary arrays for storing both sorted arrays (part of arr) before merging 
    vector<int> temp1(mid - s + 1);
    vector<int> temp2(e - mid);

    int j = s;
    for(int i = 0; i < temp1.size(); i++){
        temp1[i] = arr[j++];
    }

    int k = mid + 1;
    for(int i = 0; i < temp2.size(); i++){
        temp2[i] = arr[k++];
    }

    //merging sorted arrays and putting it in right place in arr
    int i = 0;
    j = 0;
    for(; i < temp1.size() && j < temp2.size(); ){
        if(temp1[i] <= temp2[j]) arr[s++] = temp1[i++];
        else arr[s++] = temp2[j++];
    }
    while(i < temp1.size()){
        arr[s++] = temp1[i++]; 
    }
    while(j < temp2.size()){
        arr[s++] = temp2[j++]; 
    }
}

void merge_sort(int arr[], int s, int e){
    if(s >= e){
        return;
    }
    int mid = s + (e - s)/2;

    //Dividing Arrays
    merge_sort(arr, s, mid);
    merge_sort(arr, mid + 1, e);

    //merging both Arrays together
    merge_both(arr, s, e);
}

int main() {

    int arr[5] = {2,23,12,21,2};
    merge_sort(arr, 0, 4);

    // output arr
    for(int i = 0; i < 5; i++){
        cout<< arr[i]<< " ";
    }

return 0;
}