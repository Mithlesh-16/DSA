#include<iostream>
using namespace std;
int main(){
    int t =0,i=0;
    cin>>t;
    while(i<t){
        string word;
        cin>>word;
        int size =word.size();

        word[size-2] = 'i';
        word[size-1] = ' ';
        cout<<word<<endl;





        i++;
    }


    return 0;
}