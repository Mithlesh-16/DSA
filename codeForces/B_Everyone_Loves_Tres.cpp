#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){

    ll t;
    cin>>t;

    while(t--){

        int n;
        cin>>n;

        string odd = "36366";
        if(n == 1 || n == 3){
            cout<<-1<<endl;
        }
        else if(n%2){
            string ans = "";
            for(int i = 1; i <= n-5; i++){
                ans+="3";
            }
            ans += odd;
            cout<<ans<<endl;
        }
        else{

            string ans = "";
            for(int i = 1; i <= n - 2; i++){
                ans += "3";
            }
            ans += "66";
            cout<<ans<<endl;
        }

        
    }




    return 0;
}