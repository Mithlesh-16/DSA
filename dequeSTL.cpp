#include <iostream>
#include <deque>

using namespace std;
//Doubly ended queue - DEQUE
//size 0 on erase but, max size remains same
int main(){
    deque<int> d;
    
    d.push_back(1);
    d.push_front(2);

    // d.pop_back();
    // d.pop_front();

    cout<<"Print First Element = "<<d.at(1)<<endl;
    cout<<d.front()<<endl;
    cout<<d.back()<<endl;
    cout<<"Empty or not = "<<d.empty()<<endl;

    for(int i:d){
        cout<<i<<" ";
    }
    cout<<endl;
    d.erase(d.begin(),d.begin()+1);
    for(int i:d){
        cout<<i<<" ";
    }

    return 0;
}