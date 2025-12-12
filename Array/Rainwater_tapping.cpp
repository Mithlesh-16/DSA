#include <bits/stdc++.h>
using namespace std;


long long getTrappedWater(long long* arr, int n) {
    // Write your code here.
    //find u here
    // int u_cnt = 0,

    int tmp = arr[0],flag = 0;
    for(int i = 0; i < n; ){
        for(int j = i+1; j<n; j++){
            if(tmp <= arr[j]){
                if(j-i == 1){
                    tmp = arr[j];
                    i+=2;
                    flag = 1;
                    break;
                }
                tmp = arr[j];
                flag = 1;
                i = j;
            }

        }
        flag = 0;
        if(!flag) tmp--;
    }
    
                    




    
    
}

int main() {





return 0;
}