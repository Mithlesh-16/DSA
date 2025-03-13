#include<iostream>
using namespace std;
int main(){
    int t=0,i=0;
    cin>>t;
    while(i<t){

        int seated=0,m,a,b,c,left1=0,left2=0;
        cin>>m>>a>>b>>c;
        if(m>a){
            seated +=a;
            left1 = m-a;
        }else if(m<=a){
            seated += m;
        }
        if(m>b){
            seated +=b;
            left2 = m-b;
        }else if(m<=b){
            seated += m;
        }
        if(c <= left1+left2){
            seated+=c;
        }else {
            seated+=left1+left2;
        }
        cout<<seated<<endl;
        










        i++;
    }



    return 0;
}