#include <bits/stdc++.h>
using namespace std;

int main() {

    int t;
    cin>>t;
    while(t --){
        
        int n, k;
        cin>>n>>k;
        
        int cnt_1 = 0;
        bool flag = false;
        string v;
        cin>>v;
        int m = n;
        vector<int> v1(n);
        for(int i = 0; i < n; i++){
            if(v[i] == '1'){
                v[i] = 'a';
                cnt_1++;
            }else{
                v1[i] = m;
                cnt_1 = 0;
                m--;
            } 
            
            if(cnt_1 >= k){
                flag = true;
                break;
            }
        }

        if(flag) {
            cout<<"NO"<<endl;
        }
        else {
            cout<<"YES"<<endl;
            for(int i = 0; i< n; i++){
                if(v[i] == 'a'){
                    v1[i] = m;
                    m--;
                }
                cout<<v1[i]<<" ";
            }
            cout<<endl;
        }
        


    }

return 0;
}