#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){

    ll t;
    cin>>t;

    while(t--){

        ll n;
        cin>>n;

        string s;
        cin>>s;
        
        if(s.size() <= 1){
            cout<<s<<endl;
            continue;
        }

        string t;
        t = s;
        sort(t.begin(), t.end());

        char min_char = ' ', max_char = ' ', tmp_char = t[0];
        ll tmp_cnt = 1, min_cnt = INT_MAX, max_cnt = INT_MIN;

        for(ll i = 1; i < n; i++){
            if(tmp_char != t[i]){
                if(min_cnt > tmp_cnt){
                    min_cnt = tmp_cnt;
                    min_char = tmp_char;
                }
                if(max_cnt <= tmp_cnt){
                    max_cnt = tmp_cnt;
                    max_char = tmp_char;
                }
                tmp_char = t[i];
                tmp_cnt = 1;
            }else{
                tmp_cnt++;
            }
        }

        if(min_cnt > tmp_cnt){
            min_cnt = tmp_cnt;
            min_char = tmp_char;
        }
        if(max_cnt <= tmp_cnt){
            max_cnt = tmp_cnt;
            max_char = tmp_char;
        }
        
        for(ll i = 0; i < n; ){
            if(s[i] == min_char){
                s[i] = max_char;
                break;
            }
            i++;
        }   

        cout<<s<<endl;
        
    }




    return 0;
}