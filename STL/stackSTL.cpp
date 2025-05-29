#include<iostream>
#include<stack>

//LAST IN, FIRST OUT in stack
using namespace std;
int main(){

    stack<string> s;
    s.push("Mithlesh");
    s.push("Kumar");
    s.push("Yadav");
    // s.pop();

    cout<<s.top()<<endl;
    cout<<s.size()<<endl;
    cout<<"Empty or Not = "<<s.empty()<<endl;


    return 0;
}