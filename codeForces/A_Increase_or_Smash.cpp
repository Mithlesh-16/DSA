#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){

    ll t;
    cin>>t;

    while(t--){

        ll n;
        cin>>n;
        set<int> s;

        for(int i = 0; i < n; i++){
            ll tmp = 0;
            cin>>tmp;
            s.insert(tmp);
        }
        
        cout<<2*s.size() -1<<endl;

        
    }




    return 0;
}