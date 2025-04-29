#include <iostream>
using namespace std;

int main() {
    //bubble sort
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }

    for(int i = 0; i<n-1; i++){
        for(int j = 1; j<n-i; j++){
            if(arr[j-1]>arr[j])
            swap(arr[j-1], arr[j]);
        }
    }

    cout<<endl;
    for(int i = 0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

return 0;
}