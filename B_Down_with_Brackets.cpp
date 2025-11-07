#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){

    ll t;
    cin>>t;

    while(t--){

        string s;
        cin>>s;

        stack<char> st;
        bool flag = true;
        for(ll i = 0; i < s.size(); i++){
            if(s[i] == '(')st.push(s[i]);
            else {
                if(st.top() == '(') st.pop();
            }

            if(st.size() == 0 and i != s.size() - 1){
                cout<<"YES"<<endl;
                flag = false;
                break;
            }
        }

        if(flag) cout<<"NO"<<endl;

        
    }




    return 0;
}