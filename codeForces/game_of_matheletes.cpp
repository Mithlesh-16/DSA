#include <bits/stdc++.h>
using namespace std;



int main() {

    long long t;
    cin>>t;
    while(t--){

        long long n,k;
        cin>>n>>k;
        long long arr[n+1] = {0};
        long long s = 0;
        for(long long i = 1; i<n+1; i++){
            cin>>s;
            arr[s] += s;
        }

        // for(long long i = 1; i<n+1; i++){
        //     cout<<arr[i]<<" ";
        // }
        // cout<<endl;

       long long score = 0;
       long long cnt = 0;
       for(long long i = 1; i<n+1 && cnt<= n/2; i++){
            long long tgt = k-i;
            long long num = 0;
            if(arr[i]>0 && tgt<=n && tgt>0 && arr[tgt]>0){
                num = min(arr[i]/i, arr[tgt]/tgt);
                if(i == tgt) num = num/2;
                score += num;
                cnt += num;

                

                arr[i] = 0;
                arr[tgt] = 0;
            }
            // cout<<"--------------------------------"<<endl;
            //     cout<<"i : "<<i<<endl;
            //     cout<<"arr[i] : "<<arr[i]<<endl;
            //     cout<<"tgt : "<<tgt<<endl;
            //     cout<<"arr[tgt] : "<<arr[tgt]<<endl;
            //     cout<<"num : "<<num<<endl;
            //     cout<<"cnt : "<<cnt<<endl;
            //     cout<<"score : "<<score<<endl;
            //     cout<<"--------------------------------"<<endl;
       }
       cout<<score<<endl;
    }

return 0;
}