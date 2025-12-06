#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){

    ll t;
    cin>>t;

    while(t--){

        int n;
        cin>>n;

        vector<int> v(n);
        vector<int> odd, even;
        bool flag = 0;
        int index = 0;

        for(int i = 0; i < n; i++){
            cin>>v[i];
            if(v[i] == 1 and !flag){
                flag = 1;
                index = i;
            }
            if(v[i] & 1) odd.push_back(v[i]);
            else even.push_back(v[i]);
        }

        if(flag and (index +1 < n)){
            cout<<v[index]<<" "<<v[index + 1]<<endl;
            continue;
        }
        else if(flag and index - 1>= 0){
            cout<<v[index]<<" "<<v[index - 1]<<endl;
            continue;
        }

        for(int i = 0; i < n and !flag; i++){
            int a = v[i];
            if(a & 1){
                for(int i = 0; i < odd.size(); i++){
                    if(a < odd[i] and (odd[i] % a)% 2 == 0){
                        cout<<a<<" "<<odd[i]<<endl;
                        flag = 1;
                        break;
                    }
                }
            }else{
                for(int i = 0; i < even.size(); i++){
                    if(a < even[i] and (even[i] % a) % 2 == 0){
                        cout<<a<<" "<<even[i]<<endl;
                        flag = 1;
                        break;
                    }
                }
            }
            if(even.size() == n or odd.size() == n) break;
        }

        if(!flag){
            cout<<-1<<endl;
        }
        
    }

    return 0;
}