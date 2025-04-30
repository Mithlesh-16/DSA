#include <bits/stdc++.h>
using namespace std;

void merge_two(int *arr, int s, int e)
{
    int mid = (s + e) / 2;   
    if(arr[mid] <= arr[mid + 1]) return;                       
    int len1 = mid - s + 1;
    int len2 = e - mid;  
    
    //create two arrays 
    int *arr1 = new int [len1];
    int *arr2 = new int [len2];

    //copy both arrays
    int i = 0, j = 0, k = s;
    for(int i = 0; i<len1; i++){
        arr1[i] = arr[k++];
    }
    
    k = mid + 1;
    for(int i = 0; i<len2; i++){
        arr2[i] = arr[k++];
    }


    //merging both arrays
    k = s;
    while(i<len1 && j<len2){

        if(arr1[i] <= arr2[j]) arr[k++] = arr1[i++];

        if(arr1[i] > arr2[j]) arr[k++] = arr2[j++];
    }
    while(i<len1 ){
        arr[k++] = arr1[i++];
    }
    while(j<len2 ){
        arr[k++] = arr2[j++];
    }
    
}

void merge_sort(int *arr, int s, int e)
{
    if (s >= e)
        return;
    int mid = (s + e) / 2;
    
    //sort left part 
    merge_sort(arr, s, mid);

    //sort right part
    merge_sort(arr, mid + 1, e);

    //merge both parts
    merge_two(arr, s, e);
}

int main()
{

    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    merge_sort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}