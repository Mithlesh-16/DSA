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
        vector<bool> visited(n, false);
        bool is_permutation = true;
        for(int i = 0; i < n; i++){
            cin>>v[i];
            if(!visited[v[i] - 1]){
                visited[v[i] - 1] = true;
            }else is_permutation = false;
        }
        if(!is_permutation){
            cout<<"NO"<<endl;
            continue;
        };
        
        for(int j = 1; j < n; j++){
            if(v[j - 1] - v[j] == 1){
                swap(v[j], v[j - 1]);
            }
        }
        
        for(int i = 1; i < n; i++){
            if(abs(v[i] - v[i - 1]) > 1){
                is_permutation = false;
                break;
            }
        }

        if(is_permutation){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }

        
    }

    return 0;
}