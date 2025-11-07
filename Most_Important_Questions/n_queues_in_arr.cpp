#include <bits/stdc++.h>
using namespace std;

class n_queues{

    int* front;
    int* arr;
    int* next;
    int* back;
    int freespot;

    public:
    n_queues(int n, int m){
        front = new int[n];
        arr = new int[m];
        freespot = 0;
        next = new int[m];
        back = new int[n];

        for(int i = 0; i < m; i++){
            next[i] = i+1;

        }
        next[m - 1] = -1;

        for(int i = 0; i < n; i++){
            front[i] = -1;
            back[i] = -1;
        }
    }

    bool push(int i, int val){

        if(freespot == -1){
            cout << "Queue Overflow!!" << endl;
            return false;
        }

        int index = freespot;
        freespot = next[index]; // Get the next free spot
        arr[index] = val;       // Store the data

        // This is the new node, it's the end of the line, so its 'next' is -1
        next[index] = -1; 

        if(front[i] == -1){
            // --- Case 1: The queue is empty ---
            // The new node is both the front and the back
            front[i] = index;
            back[i] = index;
        }
        else{
            // --- Case 2: The queue is NOT empty ---
            // 1. Link the *old* back node to our *new* node
            next[back[i]] = index;
            // 2. Update the 'back' pointer to *be* our new node
            back[i] = index;
        }
        
        return true;
    }

    int pop(int i){

        if(front[i] == -1){
            return -1;
        }

        int index = front[i];
        
        front[i] = next[index];
        if(front[i] == -1){
            back[i] = -1;
        }
        next[index] = freespot;
        freespot = index;
        
        return arr[index];
    }
};

int main() {


return 0;
}