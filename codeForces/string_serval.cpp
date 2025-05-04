#include <bits/stdc++.h>
using namespace std;

int main() {

    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        
        string s;
        cin>>s;
        string rev = s;
        reverse(rev.begin(),rev.end());
        if(rev>s){
            cout<<"YES"<<endl;
        }
        else if(k == 0){
            cout<<"NO"<<endl;
        }
        else{
            //check if all char are equal 
            bool all_equal = true;
            for(int i = 1; i < n; i++){
                if(s[i] != s[0]){
                    all_equal = false;
                    break;
                } 
            }

            if(all_equal) cout<<"NO"<<endl;
            else cout<<"YES"<<endl;
        }



    }

return 0;
}