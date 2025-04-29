#include <bits/stdc++.h>
using namespace std;

int main() {

    int m;
    cin>> m;

    int **arr = new int*[m];
    int arr2[m];

    for(int i = 0; i<m; i++){
        int n;
        cin>>n;
        arr2[i] = n;
        arr[i] = new int [n];
    }

    // for(int i=0; i<)
    for(int i = 0; i<m; i++){
        for(int j = 0; j<arr2[i]; j++){
            cin>>arr[i][j];
        }
    }

    for(int i = 0; i<m; i++){
        for(int j = 0; j<arr2[i]; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

return 0;
}