#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){

    ll t;
    cin>>t;

    while(t--){
        ll n ;
        cin>>n;
        string s = "";
        cin>>s;
        vector<int> v;
        int cnt = 0;
        for(ll i = 0; i < n; i++){
            if(s[i] == '1'){
            v.push_back(i+1);
                cnt++;
            }
        }

        cout<<cnt<<endl;
        for(int i = 0; i< v.size(); i++){
            cout<<v[i]<<" ";
        }

        cout<<endl;

        
    }




    return 0;
}