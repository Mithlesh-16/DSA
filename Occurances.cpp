#include<iostream>
#include<vector>
using namespace std;
int main(){
    int arr[9]={1,1,4,5,5,5,6,6,7};             //sorted Arrays
    int s=0,target=0,ans=-1;
    int e=9-1;
    int mid=s+(e-s)/2;
    cin>>target;
    while(e>=s){
        if(arr[mid]==target){
            ans=mid;
        }
        if(arr[mid]>=target){ // (<=) for last Occurance
            // s=mid+1;
            e=mid-1;

        }else{  
            // e=mid-1; //for last Occurence
            s=mid+1;
        }
        mid=s+(e-s)/2;
    }
    cout<<endl;
    cout<<ans;
    

    return 0;
}