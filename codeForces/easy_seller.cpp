#include <bits/stdc++.h>
using namespace std;

int main() {

    int t = 0;
    cin>>t;
    while(t --){
        long long total_melons = 0;
        cin>> total_melons;

        long long i = 1;
        long long tmp = pow(3, i++);
        while(total_melons > tmp){
            tmp = pow(3, i++);
        }

        tmp = pow(3, --i);

        long long coins = 0;
        while(total_melons > 0 and i >=0){
            long long coins_cnt = pow(3, i + 1) + i*(pow(3, i - 1));
            coins += ((total_melons / tmp) * coins_cnt);
            total_melons = total_melons % tmp;
            tmp = pow(3, --i);
        }

        if(total_melons > 0){
            coins += total_melons * 3;
        }
        cout<<coins<<endl;
    }

return 0;
}