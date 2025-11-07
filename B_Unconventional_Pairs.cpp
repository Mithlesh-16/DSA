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
        
        sort(v.begin(), v.end());


        ll maxi = INT_MIN;
        for(ll i = 1; i < n; i+= 2){
            maxi = max(maxi, abs(v[i] - v[i - 1]));
        }

        cout<<maxi<<endl;
        
    }




    return 0;
}