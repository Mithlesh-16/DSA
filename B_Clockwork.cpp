#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){

    ll t;
    cin>>t;

    while(t--){

        ll n;
        cin>>n;
        bool is_possible = true;
        for(ll i = 0; i < n and n > 1; i++){
            ll tmp = 0;
            cin>>tmp;

            if((n - i - 1)*2 >= tmp or tmp <= 2 or (i - 0)*2 >= tmp){
                is_possible = false;
            }
            
        }
        
        if(is_possible){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
        
    }




    return 0;
}