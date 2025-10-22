#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){

    ll t;
    cin>>t;

    while(t--){

        ll n, k;
        cin>>n>>k;
        map<ll, ll> mp;

        for(int i = 0; i < n; i++){
            ll tmp;
            cin>>tmp;
            mp[tmp]++;
        }
        
        vector<int> ans;
        for(ll i; i < k; i++){
            for(int i = 0; i < n; i++){
                if(mp.find(i) == mp.end()){
                    ans.push_back(i);
                }
                if()
            }
        }

        
    }




    return 0;
}