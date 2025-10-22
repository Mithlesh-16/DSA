#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){

    ll t;
    cin>>t;

    while(t--){

        ll n;
        cin>>n;
        
        vector<ll> a(n), b(n, 1);
        int even_cnt = 0;
        for(ll i = 0; i< n; i++){
            cin>>a[i];
            if(a[i] % 2 == 0){
                even_cnt++;
            }
        }

    

        for(ll i = 0; i< n; i++){
            cin>>b[i];
        }
        bool flag = true;
        if(even_cnt >= 2){
            cout<<0<<endl;
        }
        else{
            int curr_cnt = 0;
            for(ll i = 0; i < n; i++){
                for(ll j = i + 1; j < n; j++){
                    ll tmp =  gcd(a[i], a[j]);

                    if(tmp > 1){
                        cout<<0<<endl;
                        flag = false;
                        break;
                    }

                    if(curr_cnt == 0){
                        tmp = gcd(a[i] + 1, a[j]);
                        if(tmp > 1) curr_cnt = 1;
                        else if(gcd(a[i], a[j] + 1) > 1){
                            curr_cnt = 1;
                        }
                    }
                }
            }

            if(curr_cnt and flag){
                cout<<1<<endl;
            }

            else if(flag){
                cout<<2<<endl;
            }


        }

        

        
    }




    return 0;
}