#include <bits/stdc++.h>
using namespace std;

int main(){

    int t;
    cin>>t;
    while(t --){
        int n, m;
        cin>>n>>m;
        
        int a, b, c, d, score = 0;
        c = 0, d = 0;

        for(int i = 0; i < n; i++){
            cin>>a>>b;
            
            if((a - c) & 1){
                if(d == b){
                    score += (a - c - 1);
                }
                else score += (a - c);
            }else {
                if(d == b) score += (a - c);
                else score += (a - c - 1);
            }
            
            c = a, d = b;
        }

        if(c != m){
            score += (m - c);
        }
        
        cout<<score<<endl;

    }




    return 0;
}