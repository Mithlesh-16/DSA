#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){

    ll t;
    cin>>t;

    

    while(t--){

        ll n;
        cin>>n;

        vector<ll> v(n);
        for(ll i = 0; i < n; i++){
            cin>>v[i];
        }

        for(ll i = 0; i < n; i++){
            cout<<n+1 - v[i]<<" ";
        }

        cout<<endl;
        
    }




    return 0;
}