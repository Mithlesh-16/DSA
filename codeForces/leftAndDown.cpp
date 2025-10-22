#include <bits/stdc++.h>
using namespace std;

int main() {

    int t;
    cin>>t;

    while(t--){

        long long a, b, k;
        cin>>a>>b>>k;
        long long maxi = a, mini = b;
        if(a < b){
            mini = a;
            maxi = b;
        }

        if(mini == maxi){
            cout<<1<<endl;
        }
        else if(k >= maxi){
            cout<<1<<endl;
        }
        else{
                long long tmp = gcd(a, b);
                if(maxi/tmp <= k and mini/tmp <= k){
                    cout<<1<<endl;
                }
                else cout<<2<<endl;
        }


    }

return 0;
}