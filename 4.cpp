#include <iostream>
long long power(int,int);
using namespace std;
int main(){                     //Binary to decimal
    int biNum,n=0;
    cin>>biNum;
    int i=0;
    while(biNum!=0){
        if((biNum % 10)==1){
            n=n+power(2,i);
        }
        biNum=biNum/10;
        i++;
    }
    cout<<n;
    return 0;
}
long long power(int base,int pow){
    if(pow==0){
        return 1;
    }
    else{
        return base*power(base,pow-1);
    }
}