// #include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main() {

    int m,n;
    cin>>m>>n;
    int **arr = new int*[m];
    for(int i = 0; i<m; i++){
        arr[i] = new int [n];
    }

    for (int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            cin>>arr[i][j];
        }
    }
    for (int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            cout<<arr[i][j]<<" ";
        }
        delete []arr[i];          //memory free
        cout<<endl;
    }

    delete []arr;
    return 0;
}