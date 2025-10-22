#include <bits/stdc++.h>
using namespace std;

int main(){

    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;

        vector<int> v(n);
        for(int i = 0; i < n; i++){
            cin>>v[i];
        }

        sort(v.begin(), v.end());

        int j = 0, operations = 0;
        bool flag = false;
        int same_op = 0;

        for(int i = 0; i < n and j <= k; i++){
            flag = false;
            while(i < n and v[i] == j and j == k){
                i++;
                same_op++;
                flag = true;
            }

            while(i < n and v[i] == j and j != k){
                i++;
                flag = true;
            }

            if(flag){
                j++;
                i--;
                continue;
            }
            
            if(j == k) break;
            
            if(j < v[i] and j != k){
                if(k < v[i]){
                    operations += k - j;
                    j = k;
                    break;
                }
                operations += v[i] - j;
                j = v[i];
                i--;
            }
        }

        if(j < k){
            operations += k - j;
        }

        if(operations < same_op){
            operations = same_op;
        }
        
        cout<<operations<<endl;
    }

    return 0;
}