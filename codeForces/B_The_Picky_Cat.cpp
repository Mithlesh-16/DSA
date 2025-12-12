#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){

    ll t;
    cin>>t;

    while(t--){

        ll n;
        cin>>n;
        vector<ll> v;
        ll med = -1;
        ll cnt = 0;
        for(ll i = 0; i < n; i++){
            ll tmp = 0;
            cin>>tmp;
            if(v.size() == 0){
                med = abs(tmp);
            }
            if(abs(tmp) < med) cnt++;
            v.push_back(abs(tmp));
        }
        ll med_index = -1;
        if(v.size()%2){
            med_index = v.size()/2 + 1;
        }else med_index = v.size()/2;

        if(v.size() - cnt >= med_index){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
        



        
    }




    return 0;
}