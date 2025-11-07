#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){

    ll t;
    cin>>t;

    while(t--){

        ll n, x;
        cin>>n>>x;

        ll curr = 0;
        vector<ll> v;
        bool flag = false;

        for(ll i = 0; i < n; i++){
            if(x != curr){
                v.push_back(curr);
            }else{
                curr++;
                flag = true;
                v.push_back(curr);
            }
            curr++;
        }

        if(flag)
            v[v.size() - 1] = x;

        for(ll i = 0; i < v.size(); i++){
            cout<<v[i]<<" ";
        }

        cout<<endl;
        
    }




    return 0;
}