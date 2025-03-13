#include <iostream>
using namespace std;
int main(){
    int t=0,i=0;
    cin>>t;
    while(i<t){
        string obsStr;
        cin>>obsStr;
        int size =obsStr.size();
        string new1 = obsStr;
        for(int i=0;i<size;i++){
            if(obsStr[i] == 'p'){
                new1[size-1-i] = 'q';
            }
            else if(obsStr[i] == 'q'){
                new1[size-1-i] = 'p';
            }else{
                new1[size-1-i] ='w';
            }
        }

        cout<<new1<<endl;




        i++;
    }





    return 0;
}