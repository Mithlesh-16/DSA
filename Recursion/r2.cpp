#include <iostream>
using namespace std;

int max(int &maxi, int arr[], int n){
        if(maxi < arr[n]){
            maxi = arr[n];
        }
        if(n == 0) return maxi;

        return max(maxi, arr, n-1);

    
}

int main() {

    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    int maxi = 0;

    cout<<max(maxi, arr, n-1)<<endl;


return 0;
}