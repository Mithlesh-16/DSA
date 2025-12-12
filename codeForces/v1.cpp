#include <bits/stdc++.h>
using namespace std;

int main(){

    int arr[100] = {0};
    
    int n;
    cout<<"The size of array : ";
    cin>>n;

    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    cout<<"insertion Index : "<<endl;

    int m;
    cin>>m;

    int val;
    cin>>val;
    
    int tmp = arr[m];
    arr[m] = val;

    for(int i = m+1; i < 100; i++){
        int tmp2 = arr[i];
        arr[i] = tmp;
        tmp = tmp2;
        if(i >= n){
            break;
        }
    }


    for(int i = 0; i < n+1; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}