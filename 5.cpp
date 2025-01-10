#include<iostream>
using namespace std;
int main(){                         //negative no to binary
    int n;
    cin>>n;
    cout<<(n&1)<<endl;
    cout<<~(n&1)<<endl;
    cout<<!(n&1)<<endl;
    return 0;
}