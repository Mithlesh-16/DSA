#include <iostream>
using namespace std;

int main() {

    long long int n;
    cin>>n;

    long long int cnt = 0;
    for(long long i = 5; n/i >= 1; i*= 5 ){
        cnt +=  n/i;
    }

    cout<<cnt<<endl;

return 0;
}