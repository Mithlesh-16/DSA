#include <bits/stdc++.h>
using namespace std;

int main() {

    int t;
    cin>>t;
    while(t--){

        int n, k;
        cin>>n>>k;

        vector <int> v(k+1,0);

        int brnd = 0,cost = 0;
        for(int i = 0; i<k; i++){
            cin>>brnd>>cost;
            v[brnd] += cost;
        }        
        

        sort(v.begin(), v.end(), greater<int> ());
        int profit = 0;
        for(int i = 0; i<v.size() && i<n; i++){
            profit += v[i];
        }

        cout<<profit<<endl;




    }


return 0;
}