#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){

    ll t;
    cin>>t;

    while(t--){

        ll n = 0;
        cin>>n;

        ll cnt = 0;

        while(n > 2){
            cnt += n/3;
            n = n/3 + n%3;
        }

        cout<<cnt<<endl;
        
    }




    return 0;
}