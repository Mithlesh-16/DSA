#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){

    ll t;
    cin>>t;

    while(t--){

        ll n, k;
        cin>>n>>k;

        string s;
        cin>>s;
        ll prev = -k, cnt = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '1'){
                if(i >= prev + k){
                    cnt ++;
                }
                prev = i;
            }
        }
        
        cout<<cnt<<endl;

        
    }




    return 0;
}