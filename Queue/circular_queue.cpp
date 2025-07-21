#include <iostream>
using namespace std;

class circular_Queue{
    int *arr;
    int front;
    int back;
    int size;

    circular_Queue(int n){
        arr = new int[n];
        front = back = -1;
    }

    bool push(int x){
        if(front == -1){
            front = back = 0;
            arr[front] = x;
        }
        else if()
    }
};


int main() {


return 0;
}