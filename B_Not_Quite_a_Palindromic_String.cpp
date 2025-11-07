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

        ll cnt_1 = 0, cnt_0 = 0;
        
        for(ll i = 0; i < n; i++){
            if(s[i] == '0')cnt_0++;
            else cnt_1++;
        }

        cnt_1 = cnt_1/2;
        cnt_0 = cnt_0/2;
        for(ll i = 0; i < k; i++){
            if(cnt_1 > cnt_0) cnt_1--;
            else cnt_0--;
        }

        if(cnt_0 == cnt_1) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        
    }




    return 0;
}