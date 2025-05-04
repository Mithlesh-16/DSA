#include <iostream>
using namespace std;

int main() {

    int t;
    cin>>t;
    while(t--){

        int n;
        cin>>n;
        if(n%2 == 0) cout<<-1<<endl;
        else{
            cout<<n<<" ";
            for(int i = 1; i<n; i++){
                cout<<i<<" ";
            }
            cout<<endl;
        }

    }

return 0;
}