#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){

    ll t;
    cin>>t;

    while(t--){

        ll n;
        cin>>n;

        string s = "";
        string a_str = "a";
        string e_str = "e";
        string i_str = "i";
        string o_str = "o";
        string u_str = "u";
        string t = "aeiou";

        for(ll i = 1; i < n/5; i++){
            a_str += "a";
            e_str += "e";
            i_str += "i";
            o_str += "o";
            u_str += "u";
        }

        if(n%5 == 0){
            cout<<a_str + e_str + i_str + o_str + u_str<<endl;
            continue;
        }else if(n/5 == 0){
            cout<<t.substr(0, n%5)<<endl;
            continue;
        }

        ll rest = n%5;
        if(rest == 1){
            a_str += "a";
        }else if(rest == 2){
            a_str += "a";
            e_str += "e";
        }else if(rest == 3){
            a_str += "a";
            e_str += "e";
            i_str += "i";
        }else{
            a_str += "a";
            e_str += "e";
            i_str += "i";
            o_str += "o";
        }
        // s += t.substr(0, n - s.size());
        s += a_str + e_str + i_str + o_str + u_str;
        cout<<s<<endl;
    }




    return 0;
}