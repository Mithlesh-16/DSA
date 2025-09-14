#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {

    int t = 0;
    cin>>t;
    while(t--){

        string a, b, c;
        int len1 = 0, len2 = 0;
        cin>>len1>>a>>len2>>b>>c;
        for(int i = 0; i < len2; i++){
            if(c[i] == 'V'){
                a = b[i] + a;
            }
            else a = a+b[i];
        }

        cout<<a<<endl;

    }


return 0;
}