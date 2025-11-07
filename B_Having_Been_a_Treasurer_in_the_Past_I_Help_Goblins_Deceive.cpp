#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){

    ll t;
    cin>>t;

    while(t--){

        ll n;
        cin>>n;
        string s;
        cin>>s;

        ll up_cnt = 0, dwn_cnt = 0;

        if(s.size() <= 2){
            cout<<0<<endl;
            continue;
        }

        for(ll i = 0; i < n; i++){
            if(s[i] == '-') up_cnt++;
            else dwn_cnt++;
        }

        if(up_cnt & 1){
            cout<<(up_cnt/2)*((up_cnt/2) + 1)*dwn_cnt;
        }else{
            cout<<(up_cnt/2)*(up_cnt/2)*dwn_cnt;
        }
        
        cout<<endl;
        
    }




    return 0;
}