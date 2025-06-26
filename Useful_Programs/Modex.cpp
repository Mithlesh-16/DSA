#include <iostream>
using namespace std;

int main() {
        int x,y,n;
        cin>>x;
        y = 4;
        n = 2*x - 2;

        if (x == 0) return 0;
        int result = 1;
        while(y > 0){
            if(y & 1) result = (result % n * x % n) %n;
            x = (x*x) %n;
            y = y>>1;
        }

        cout<<result<<endl;


        // i++;
    // }
    

return 0;
}