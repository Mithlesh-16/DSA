#include<iostream>
#include<queue>

//max heap related
using namespace std;
int main(){

    //max heap
    priority_queue<int> maxi;
    maxi.push(1);
    maxi.push(3);
    maxi.push(2);
    maxi.push(0);

    int n = maxi.size();
    for(int i = 0; i<n;i++){
        cout<<maxi.top()<<" ";
        maxi.pop();
    }
    cout<<endl;



    //min heap
    priority_queue<int,vector<int>,greater<int>> mini;

    mini.push(5);
    mini.push(1);
    mini.push(0);
    mini.push(2);
    mini.push(3);

    int n2 = mini.size();
    for(int i = 0;i<n2;i++){
        cout<<mini.top()<<" ";
        mini.pop();
    }
    cout<<endl;
    cout<<mini.empty()<<endl;






    return 0;
}