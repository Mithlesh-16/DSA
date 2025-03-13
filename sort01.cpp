#include <iostream>
#include <vector>
using namespace std;
int main(){
    vector<int> arr(8);
    arr={1,1,0,0,0,0,1,0};
    int i=0,j=7;
    for(int i=0;i<j;){
        while(arr[i]==0 && i<j){
            i++;
        }
        while(arr[j]==1 && i<j){
            j--;
        }
        //matlab ki arr[i]==1 or arr[j]==0 hai
        if(i<j){
            swap(arr[i],arr[j]);
            i++;
            j--;
        }
    }
    for(int i=0;i<arr.size();i++){
        cout<<arr[i];
    }


    return 0;
}