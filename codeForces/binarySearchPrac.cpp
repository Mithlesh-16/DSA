#include<iostream>
using namespace std;
string binarySearch(int *,int,int);
int main(){
    int n,k;
    cin>>n>>k;

    int arr[n]={0};

    for(int i =0;i<n;i++){
        cin>> arr[i];
    }

    int queries = 0;
    for(int i =0;i<k;i++){
        cin>>queries;
        
        cout<<binarySearch(arr,n,queries)<<endl;
    }



    return 0;
}

string binarySearch(int* arr,int size,int elem){
    int s = 0,e = size-1;
    while(s<=e){
        int mid =s+(e-s)/2;
        if(arr[mid]==elem){
            return "YES";
        }
        if(elem>arr[mid]){
            s = mid+1;
        }else{
            e = mid-1;
        }
    }
    return "NO";

}

