#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){

    ll t;
    cin>>t;

    while(t--){

        ll n;
        cin>>n;
        vector<ll> v2(2*n, -1);
        ll sum = 0;

        for(ll i = 0; i < n; i++){
            for(ll j = 0; j < n; j++){
                ll tmp = 0;
                cin>>tmp;

                if(v2[i + j + 1] == -1){
                    v2[i+j+1] = tmp;
                    sum += tmp;
                }
            }
        }
    
        n = 2*n;
        v2[0] = (n*(n+1))/2 - sum;

        for(ll i = 0; i < n; i++){
            cout<<v2[i]<<" ";
        }

        cout<<endl;
        
    }


    return 0;
}