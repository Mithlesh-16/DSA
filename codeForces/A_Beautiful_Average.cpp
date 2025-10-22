#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){

    ll t;
    cin>>t;

    while(t--){
        ll n;
        cin>>n;

        deque<ll> dq;
        ll sum = 0;
        for(ll i = 0; i < n; i++){
            ll tmp = 0;
            cin>>tmp;
            dq.push_back(tmp);
            sum+= tmp;
        }

        if (n == 0) {
            cout << 0 << endl;
            continue;
        }

        ll total_avg = sum / n;
        ll m = n;
        for(ll i = 0; i < n; i++){
            if(!dq.empty() && dq.front() <= dq.back()){
                sum -= dq.front();
                m--;
                if (m > 0) {
                    total_avg = max(total_avg, sum / m);
                }
                dq.pop_front();

            } else if(!dq.empty()){
                sum -= dq.back();
                m--;

                if (m > 0) {
                    total_avg = max(total_avg, sum / m);
                }
                dq.pop_back();
            }
        }
        cout << total_avg << endl;
    }

    return 0;
}