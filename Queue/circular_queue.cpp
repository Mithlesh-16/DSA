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
        size = n;
    }

    bool push(int x){
        if(front == -1){
            front = back = 0;
            arr[back] = x;
        }
        else if(front == 0 and back == size - 1){
            return false; // Queue is full
        }
        else if(back == size - 1 and front != 0){
            back = 0; // Wrap around to the beginning
            arr[back] = x;
        }
        else if(back + 1 == front){
            return false; // Queue is full
        }
        else{
            back++;
            arr[back] = x;
        }
    }

    int pop(){
        // check if empty
        if(front == -1){
            return -1; //queue is empty
        }
        else if(front == back){
            int tmp = arr[front];
            front = back = -1;
            return tmp;
        }
        else if(front == size - 1){
            int tmp = arr[front];
            front = 0;
            return tmp;
        }
        else{
            return arr[front++];
        }
    }
};


int main() {


return 0;
}