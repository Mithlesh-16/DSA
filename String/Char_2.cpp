#include <bits/stdc++.h>
using namespace std;

int main(){
    //Q 2 - Reverse a String
    char name[20];
    cin>>name;
    int size = 0, i = 0;

    while (name[i] != '\0'){
        size++;
        i++;
    }
    cout<<size<<endl;

    int s = 0, e = size -1;
    while (s<=e){
        swap(name[s],name[e]);
        s++;
        e--;
    }
    cout<<name<<endl;
    cout<<"end"<<endl;
    
    return 0;
}