#include<iostream>
using namespace std;
int main(){
    int pivot=0,s=0;                                //pivot is smallest Number
    int arr[5]={3,8,10,1,17};
    int ans;
    int e=5-1;              
    int mid=s+(e-s)/2;
    while(e>s){
        if(arr[mid]>=arr[0]){
            s=mid+1;
        }else{
            e=mid;
        }
        mid=s+(e-s)/2;
    }
    ans=s;
    // ans=e;                                         //e,s both same
    cout<<"Pivot equal to "<<ans;
    return 0;
}