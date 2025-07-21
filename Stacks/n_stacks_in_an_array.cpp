#include <iostream>
using namespace std;

class n_stacks{
    int *arr; // Array to store elements of stacks
    int *top; // Array to store the top index of each stack
    int *next; // Array to store the next index in the free list
    int free_spot; // Index of the next free slot in the array

    n_stacks(int n, int size){
        arr = new int[size]; // Create an array of given size
        top = new int[n]; // Create an array to store the top index of each stack
        next = new int[size]; // Create an array to manage free slots

        for(int i = 0; i < n; i++){
            top[i] = -1; // Initialize all stacks as empty
        }
        for(int i = 0; i < size - 1; i++){
            next[i] = i + 1; // Link each index to the next
        }
        next[size - 1] = -1; // Last index points to -1 (no next)
        free_spot = 0; // Start with the first index as free
    }

    bool push(int stack_num, int value){
        if(free_spot == -1) return false;
        int index = free_spot;
        arr[index] = value;     //insert value
        free_spot = next[free_spot];    //update free_spot
        next[index] = top[stack_num - 1];   //update next
        top[stack_num - 1] = index;     //update top

        return true;

    }
    int pop(int stack_num){
        //check for empty stack
        if(top[stack_num - 1] == -1) 
            return -1;
        int index = top[stack_num - 1];
        top[stack_num - 1] = next[index];
        next[index] = free_spot;
        free_spot = index;
        return arr[index];
    }
};

int main() {


return 0;
}