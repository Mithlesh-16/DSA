#include <bits/stdc++.h>
using namespace std;

class n_stacks{
    int *arr;
    int *top;
    int *next;
    int freespot;

    public:
    n_stacks(int n, int size){
        arr = new int[size];
        next = new int[n];
        top = new int[size];
        freespot = 0;

        for(int i = 0; i < n; i++){
            top[i] = -1;
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
        arr[index] = val;
        freespot = next[index];
        next[index] = top[n];
        top[n] = index;

    }

    int pop(int n){

        if(top[n] == -1){
            return -1;
        }

        int index = top[n];
        top[n] = next[index];
        next[index] = freespot;
        freespot = index;
        
    }

};

int main() {


return 0;
}