#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int n, i =0;
    cin>>n;
    int arr[n] = {0};
    while(i<n-1){
        int a;
        cin>>a;
        arr[a-1] = 1;
        i++;
    }
    
    for (int i =0;i<n;i++){
        if(arr[i] == 0){
            cout<< i+1<<endl;
        }
    }
    
    
    return 0;
}
