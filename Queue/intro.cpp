#include <iostream>
#include <queue>
using namespace std;

    //q.front(); gives the front element
    //q.back(); gives the back element
    //q.pop(); removes the front element
    //q.push(50); // adds an element to the back of the queue
    //q.size(); // returns the number of elements in the queue
    //q.empty(); // checks if the queue is empty

int main() {

    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    cout<<"front of q : "<<q.front()<<"size : "<<q.size()<<endl;
    q.pop();
    cout<<"back of queue : "<<q.back()<<endl;
    

    return 0;
}