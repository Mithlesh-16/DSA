#include <bits/stdc++.h>
using namespace std;

int partition(int arr[], int s, int e){

    //count smaller numbers
    int pivot = arr[s];
    int cnt = s;
    for(int i = s+1; i <= e; i++){
        if(arr[i] <= pivot) cnt++;
    }
    swap(arr[s], arr[cnt]);

    
    //two pointer approach
    int i = s, j = e;
    while(i<=j){
        if(arr[i]>pivot && arr[j]<=pivot) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
        else if(arr[i] <= pivot && arr[j] > pivot){
            i++;
            j--;
        }
        else if(arr[i]<= pivot){
            i++;
        }
        else if(arr[j] > pivot){
            j--;
        }
    
    }
    return cnt;

}

void quick_sort(int arr[], int s, int e){
    //base case
    if(s>=e){
        return;
    }

    //partition index 
    int p = partition(arr, s, e);

    //left part sort kare
    quick_sort(arr, s, p-1);

    //right part sort kare
    quick_sort(arr, p+1, e);

}

int main() {

    int n;
    cin>>n;
    int arr[n];

    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    
    quick_sort(arr, 0, n-1);

    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;


return 0;
}