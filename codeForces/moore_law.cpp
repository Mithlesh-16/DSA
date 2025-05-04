#include <bits/stdc++.h>
using namespace std;

int main() {

    long long n,t;
    cin>>n>>t;

    long double ans = (long double)(int(int(2*n)/((long double)(365*2*24*3600)))%int(pow(10,6)));
    ans = (ans *t) + n;
    cout<<(long double)(ans)<<endl;


return 0;
}