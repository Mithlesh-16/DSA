#include <iostream>
using namespace std;

int main() {

    int t;
    cin>>t;
    while(t--){

        long long n, k;
        cin>>n>>k;
        if(n%2 == 0 && k%2 == 0){
            cout<<((n%k == 0) ? n/k : (n/k)+1)<<endl;
        }

        else if(n%2 == 0){
            cout<<((n%(k-1) == 0) ? n/(k-1) : (n/(k-1))+1)<<endl;

        }
        else if(k%2 == 0){
            n = n-(k-1);
            cout<<((n%k == 0) ? (n/k)+1 : (n/k)+2)<<endl;
        }
        else{
            n = n-k;
            k = k-1;
            cout<<((n%k == 0) ? (n/k)+1 : (n/k)+2)<<endl;
        }



    }


return 0;
}