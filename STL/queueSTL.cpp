#include<iostream>
#include<queue>

using namespace std;
//FIRST IN, FIRST OUT
int main(){
    queue<string> q;

    q.push("love");
    q.push("Babbar");
    q.push("Kumar");

    cout<<"First Element = "<<q.front()<<endl;
    q.pop();
    cout<<"First Element = "<<q.front()<<endl;
    cout<<q.size()<<endl;
    q.pop();




    return 0;
}