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
        vector<ll> v_max(n, 0);
        ll prev_max = 0;

        for(ll i = 0; i< n; i++){
            cin>>v[i];
            v_max[i] = max(prev_max, v[i]);
            prev_max = v_max[i];
        }

        ll cnt = 0;
        for(ll i = 1; i < n; i+= 2){
                v[i] = v_max[i];
                if(v[i - 1] >= v[i]){
                    cnt += ((v[i - 1] - v[i]) + 1); 
                }
                
                if(i + 1 < n and v[i] <= v[i + 1]){
                        cnt += ((v[i + 1] - v[i]) + 1);
                        v[i + 1] = v[i] - 1;
                    }
            
        }

        cout<<cnt<<endl;
        
    }




    return 0;
}