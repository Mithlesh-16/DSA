#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){

    ll t;
    cin>>t;

    while(t--){

        ll n, k;
        cin>>n>>k;

        vector<ll> v(n, -1);
        int cnt = 1;
        for(ll i = k - 1; i < n; ){
            v[i] = cnt;
            i += k;
            cnt++;
        }

        for(ll i = 0; i < n; i++){
            if(v[i] == -1){
                v[i] = cnt;
                cnt++;
            }
            cout<<v[i]<<" ";
        }
         
        cout<<endl;
        
        
    }




    return 0;
}