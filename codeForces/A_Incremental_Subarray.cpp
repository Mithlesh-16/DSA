#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){

    ll t;
    cin>>t;

    while(t--){

        ll n, m;
        cin>>n>>m;
        vector<ll> v;
        ll prev = 0;
        bool inc = true;
        

        for(int i = 0; i < m; i++){
            ll tmp = 0;
            cin>>tmp;
            if(prev < tmp and inc){
                v.push_back(tmp);
            }else{
                inc = false;
            }
            prev = tmp;
        }

        if(!inc) {
            cout<<1<<endl;
            continue;
        }
        
        cout<< n - v[v.size()-1] + 1<<endl;
        


        
    }




    return 0;
}