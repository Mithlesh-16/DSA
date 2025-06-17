#include <bits/stdc++.h>
using namespace std;

int main() {

    // finding no. of natural no which are prime numbers in O(log n) time complexity
    // sieve of eratosthenes

    long long int n;
    cin>>n;

    //make a vector containing all the numbers and long long intialising every index to 1;
    vector<long long int> mapper(n, 1);
    mapper[0] = 0;
    mapper[1] = 0;

    for(long long int i = 2; i < n; i++){
        for(long long int j = i*2; j < n; j+=i){
            if(mapper[j]) mapper[j] = 0;
        }
    }

    long long int cnt = 0;
    for(long long int i = 0; i < n; i++){
        if(mapper[i]) {
            cout<<i<<" ";
            cnt++;
        }
    }
    cout<<endl;

    cout<<"no. of Primes b/w 1 and "<<n<< " : "<<cnt<<endl;

return 0;
}