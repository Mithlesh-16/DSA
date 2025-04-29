#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t=0, i =0;
    cin>>t;
    while(i<t){
        long long x;
        int k;
        cin>>x>>k;
        int flag = 1;
         
        if(x == 1 && k==2){
            flag = 1;
        }
        else if(x == 2 && k == 1){
            flag = 1;
        }
        else if(x == 1){
            cout<<"NO"<<endl;
            flag = 0;
        }
        else if(k>1){
            cout<<"NO"<<endl;
            flag = 0;
        }
        else if(x&1){
            if (x == 2 || x == 3){
                flag = 1;
            }
            else if (x % 2 == 0){
                flag = 0;
                cout<<"NO"<<endl;
            }
            else{
                for (int i = 3; i <= sqrt(x); i += 2) {
                    if (x % i == 0){
                        flag = 0;
                        cout<<"NO"<<endl;
                        break;
                    }
                }
            }
        }
        else{
            cout<<"NO"<<endl;
            flag = 0;
        }

        if(flag) cout<<"YES"<<endl;
        
        i++;
    }


return 0;
}