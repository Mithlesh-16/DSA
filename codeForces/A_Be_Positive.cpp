#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){

    ll t;
    cin>>t;

    while(t--){

        ll n;
        cin>>n;
        map<int, int> v;

        for(ll i = 0; i < n; i++){
            int tmp;
            cin>>tmp;
            v[tmp]++;
        }

        ll cnt = 0;
        if(v.find(-1) != v.end()){
            if(v[-1] % 2)
            cnt+= 2;
        }
        if(v.find(0) != v.end()){
            cnt+= v[0];
        }

        cout<<cnt<<endl;
        
    }




    return 0;
}