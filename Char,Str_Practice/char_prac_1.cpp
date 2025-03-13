#include <bits/stdc++.h>
using namespace std;

int main(){
    string name;
    cin>> name;
    cout<<name<<endl;

    //Q 1
    // Length of String
    cout<<name.size()<<endl;

    int i =0, count = 0;
    while(name[i] != '\0'){
        count++;
        i++;
    }
    cout<<count<<endl;



    return 0;
}