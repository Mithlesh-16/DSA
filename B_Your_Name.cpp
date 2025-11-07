#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){

    ll t;
    cin>>t;

    while(t--){

        int n;
        cin>>n;
        string s, t;
        cin>>s>>t;

        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        if(s == t){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }


        
    }




    return 0;
}