#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){

    ll t;
    cin>>t;

    while(t--){

        ll n, q;
        cin>>n>>q;
        string s;
        cin>>s;
        vector<ll> v(q);

        for(ll i = 0; i < q; i++){
            cin>>v[i];
        }
        
        bool all_a = false;
        ll time = 0;
        for(ll i = 0; i < s.size(); i++) {
            if(s[i] == 'B'){
                break;
            }
        }
        if(all_a){
            for(ll i = 0; i < v.size(); i++){
                cout<<v[i]<<endl;
            }
        }
        for(ll i = 0; i < v.size() and !all_a; i++){
            bool flag = true;
            time = 0;

            for(ll j = 0; v[i] != 0; j = j%s.size()){
                if(s[j] == 'B'){
                    v[i] /= 2;
                    time ++;
                    j++;
                }else{
                    v[i]--;
                    time++;
                    j++;
                }
                if(v[i] == 0){
                    cout<<time<<endl;
                    flag = false;
                    break;
                }
            }
            if(flag) cout<<time<<endl;
        }


        
    }




    return 0;
}