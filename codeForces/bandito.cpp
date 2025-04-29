#include <iostream>
using namespace std;

int main() {

    int t;
    cin>>t;
    while(t--){
        int n, m, l, r;
        cin>>n>>m>>l>>r;
        
        if(m == n);
        else if(abs(l) >= m) {
            l = -m;
            r = 0;
        }
        else if(r >= m) {
            r = m;
            l = 0;
        }
        else {
            if(r >= m-abs(l)){
                r = m - abs(l);
            }else{
                l = -(m -r);
            }
        }
        cout<<l<<" "<<r<<endl;

    }

return 0;
}