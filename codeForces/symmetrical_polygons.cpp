#include <bits/stdc++.h>
using namespace std;

int main(){

    long long t;
    cin>>t;
    while(t--){

        long long n;
        cin>>n;
        map<long long, long long> mp;
        long long perimeter = 0;

        for(long long i = 0; i < n; i++){
            long long tmp;
            cin>>tmp;
            mp[tmp]++;
            perimeter += tmp;
        }
        bool flag = true;
        if(mp.size() <= n/2){
            cout<<perimeter<<endl;
            flag = false;
        }
        // long long odd_cnt = 0;
        vector<long long> odd_cnt;

        //case 1 : optimal perimeter
        long long p1 = perimeter;
        for(auto &i: mp){
            if(i.second % 2) {
                odd_cnt.push_back(i.first);
                p1 -= i.first;
                n--;
            }
        }

        
        
        //case 2: one unpaired side
        long long p2 = 0, p3 = 0;
        bool done2 = false, done3 = false;
        for(long long i = odd_cnt.size() - 1; i >= 0; i--){
            if(odd_cnt[i] < p1 and !done2){
                p2 = p1 + odd_cnt[i];
                n += 1;
                done2 = true;
            }
            long long j = i - 1;
            if(j >= 0 and odd_cnt[i] - odd_cnt[j] < p1 and !done3){
                p3 = p1 + odd_cnt[i] + odd_cnt[j];
                done3 = true;
                n += 2;
            }

            if(done3 and done2) break;
        }
        
        if(flag and n>= 3){
            cout<<max(p1, max(p2, p3))<<endl;
        }
        else cout<<0<<endl;

    }



    return 0;
}