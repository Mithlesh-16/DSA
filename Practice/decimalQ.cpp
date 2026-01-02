#include <bits/stdc++.h>
using namespace std;

int main() {

    float num;
    cin>>num;
    int a, b;
    cin>>a>>b;

    //count the no of digits after decimal
    float num2 = num;
    num2 = num2 - (long long)num2;
    int no_of_digits = 0;

    while(num2 > 0){
        num2 = num2*10;
        no_of_digits++;
        num2 = num2 - (long long ) num2;
    }

    num = num * pow(10, no_of_digits);
    a = a * pow(10, no_of_digits);
    
    if(a/b == num and a%b == 0){
        cout<<"equal"<<endl;
    }
    else if(a/b >= num and a%b != 0){
        cout<<"Greater"<<endl;
    }
    else{
        cout<<"Less"<<endl;
    }

return 0;
}