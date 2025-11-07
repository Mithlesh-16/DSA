#include <bits/stdc++.h>
using namespace std;

class n_queue{
    int *arr;
    int *front;
    int *rear;
    int *next;
    int freespot;
    
    public:

    n_queue(int n, int size){

        arr = new int[size];
        next = new int[size];
        front = new int[n];
        rear = new int[n];
        freespot = 0;

        for(int i = 0; i < n; i++){
            front[i] = -1;
            rear[i] = -1;
        }

        for(int i = 0; i < size; i++){
            next[i] = i+1;
        }
        next[size - 1] = -1;
    }

    bool push(int n, int val){
        if(freespot == -1){
            return false;
        }


        int index = freespot;
        if(front[n] == -1){
            front[n] = index;
        }else{
            next[rear[n]] = index;
        }

        rear[n] = index;
        arr[index] = val;
        freespot = next[index];
        next[index] = -1;

    }


    int pop(int n){
        if(front[n] == -1){
            return -1;
        }

        int index = front[n];
        front[n] = next[index];
        next[index] = freespot;
        freespot = index;
    
    }

};

int main() {


return 0;
}