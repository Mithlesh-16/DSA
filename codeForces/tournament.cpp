#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int main() {

    int t = 0;
    cin>>t;
    while(t--){
        int n, j, k;
        cin>>n>>j>>k;
        vector<int> strength(n, 0);
        for(int i = 0; i < n; i++){
            cin>>strength[i];
        }
        int target = strength[j-1];
        sort(strength.begin(), strength.end());
        if(k == n) {
            cout<<"yes"<<endl;
        }
        else if(target == strength[n-1]){
            cout<<"yes"<<endl;
        }
        else if(target < strength[n-1] && k>1){
            cout<<"yes"<<endl;
        }else if(target < strength[n-1] && k == 1){
            cout<<"no"<<endl;
        }
        
        
    }


return 0;
}