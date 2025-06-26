#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int k;
    cin >> k;

    for(int i= 0;i<k;i++){
        for(int j =i+1;j<n;j++){
            if(arr[j]>arr[i]){
                int temp = arr[i];
                arr[i]= arr[j];
                arr[j] = temp;
            }
        }
    }
    cout<<arr[k-1];


    return 0;
}