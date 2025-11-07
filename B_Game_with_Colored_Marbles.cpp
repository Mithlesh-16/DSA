#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){

    ll t;
    cin>>t;

    while(t--){

        
        ll n;
        cin>>n;
        
        map<ll, ll>  mp;
        ll tmp = 0;

        for(ll i = 0; i < n; i++){
            cin>>tmp;
            mp[tmp]++;
        }

        ll cnt_1 = 0, score = 0;
        for(auto &it: mp){
            if(it.second == 1){
                cnt_1++;
            }
        }
        
        if(cnt_1 & 1){
            score += ((cnt_1/2) + 1)*2 + mp.size() - cnt_1;
        }else{
            score += (cnt_1/2) *2 + mp.size() - cnt_1;
        }

        cout<<score<<endl;

    }




    return 0;
}