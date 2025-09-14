#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {

    int t = 0;
    cin>>t;
    while(t --){

        long long int n = 0;
        cin>>n;
        
        int i = 1;
        long long divisor = pow(10,i++);
        int count = 0;
        vector<long long int> ans;
        while(n > divisor){

            divisor += 1;
            if(n % divisor == 0){
                ans.push_back(n / divisor);
                count++;
            }

            divisor = pow(10,i++);
        }
        cout<<count<<endl;
        
        for(int i = ans.size() - 1; i >=0; i--){
            cout<<ans[i]<<" ";
        }

    }


return 0;
}