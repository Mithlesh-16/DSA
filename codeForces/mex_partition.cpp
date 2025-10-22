#include<bits/stdc++.h>
using namespace std;

int main(){
    long long t;
    cin>>t;
    while(t --){
        int n;
        cin>>n;
        vector<int> v(n);
        for(int i = 0; i < n; i++){
            cin>>v[i];
        } 
        sort(v.begin(), v.end());
        if(v[0] == 0){
            int j = 1;
            for(int i = 0; i < n; i++){
                if(v[i] == j){
                    j++;
                }
            }
            cout<<j <<endl;
        }
        else if(v[0] != 0){
            cout<<0<<endl;
        }
    }
    return 0;
}