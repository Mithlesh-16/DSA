#include <bits/stdc++.h> // Includes necessary headers (iostream, vector, etc.)
using namespace std;

/**
 * @class n_stacks
 * @brief Implements 'N' (n) stacks using a single shared array of size 'M' (m).
 *
 * This class uses an efficient method that avoids space wastage.
 * It does not divide the array into fixed chunks. Instead, it treats the
 * array as a pool of free slots and dynamically links elements together
 * to form the different stacks.
 */
class n_stacks{
    // --- Member Variables ---

    int* arr;     // The main array of size 'm' that will store all elements of all 'n' stacks.
    int* top;     // An array of size 'n'. top[i] stores the index (in 'arr') of the top element of the i-th stack.
    int* next;    // An array of size 'm'. This is the core of the logic.
                  // It serves two purposes:
                  // 1. For a free slot 'i', next[i] stores the index of the *next* free spot (forms a linked list of free slots).
                  // 2. For an element 'i' that's *in* a stack, next[i] stores the index of the *previous* element in that same stack.
    int freespot; // Stores the index of the first available free slot in 'arr'. This acts as the "head" of the free list.

    public:
    /**
     * @brief Constructor for n_stacks.
     * @param n The number of stacks to create.
     * @param m The total size of the shared array.
     */
    n_stacks(int n, int m){
        // Allocate memory for the three arrays
        arr = new int [m];  // Main data array
        top = new int [n];  // Top-of-stack pointers
        next = new int [m]; // "Magic" array for linking
        
        // --- Initialization ---

        // 1. Initialize the 'top' array.
        // -1 is a sentinel value indicating that a stack is empty.
        for(int i = 0; i < n; i++){
            top[i] = -1;
        }

        // 2. Initialize the 'next' array to form the "free list".
        // We chain all slots together, as initially all are free.
        // 0 -> 1 -> 2 -> 3 -> ... -> m-2 -> m-1 -> -1
        freespot = 0; // The first free slot is at index 0.
        for(int i = 0; i < m - 1; i++){
            next[i] = i+1; // Each slot points to the next one.
        }
        next[m - 1] = -1; // The last slot points to -1, marking the end of the free list.
    }

    /**
     * @brief Pushes a value onto a specific stack.
     * @param i The stack number (0-based) to push onto.
     * @param val The value to push.
     * @return true if the push was successful, false if the stack is full (overflow).
     */
    bool push(int i, int val){
        // Step 1: Check for stack overflow.
        // If freespot == -1, it means the free list is empty and there are no more slots.
        if(freespot == -1){
            cout<<"Stack Overflow!!";
            return false;
        }

        // --- A free spot is available, proceed with push ---

        // Step 2: Grab the first available free spot.
        int index = freespot; // 'index' is the slot we will use. (Your code calls this 'temp')

        // Step 3: Update 'freespot' to point to the *next* available slot.
        // This effectively "pops" 'index' from the free list.
        freespot = next[index];

        // Step 4: Insert the actual data value into the 'arr' at the chosen index.
        arr[index] = val;

        // Step 5: Link the new element to the old top of the stack 'i'.
        // The 'next' pointer for our new element ('index') is set to point to
        // whatever was *previously* the top of stack 'i' (which is top[i]).
        // This links the new top to the rest of its stack.
        next[index] = top[i];

        // Step 6: Update the 'top' pointer for stack 'i'.
        // The top of stack 'i' is now the 'index' we just used.
        // (***NOTE: Your original code had 'top[i] = freespot;', which is a bug.
        // It should be 'top[i] = index;' or 'top[i] = temp;' as 'temp' holds the index we used.)
        top[i] = index; // This is the corrected line.

        return true; // Successfully pushed.
    }

    /**
     * @brief Pops a value from a specific stack.
     * @param i The stack number (0-based) to pop from.
     * @return The popped value, or -1 if the stack is empty (underflow).
     */
    int pop(int i){
        // Step 1: Check for stack underflow.
        // If top[i] == -1, the i-th stack is empty.
        if(top[i] == -1){
            cout << "Stack Underflow!!";
            return -1; // Return a sentinel value for error.
        }

        // --- The stack is not empty, proceed with pop ---

        // Step 2: Get the index of the top element of stack 'i'.
        int index = top[i]; // (Your code calls this 'tmp')

        // Step 3: Update the 'top' pointer for stack 'i'.
        // The new top of stack 'i' is now the *next* element in its list.
        // We find this index from next[index], which we set during the push operation.
        top[i] = next[index];

        // Step 4: Add the popped slot ('index') back to the front of the free list.
        // The 'next' pointer of our newly freed slot ('index') now points to the
        // *old* head of the free list (which was 'freespot').
        next[index] = freespot;

        // Step 5: Update 'freespot' to be the index of the slot we just freed.
        // This makes 'index' the new head of the free list.
        freespot = index;

        // Step 6: Return the value that was at the top.
        return arr[index];
    }  

    // Destructor to free allocated memory (Good Practice)
    ~n_stacks() {
        delete[] arr;
        delete[] top;
        delete[] next;
    }
};

int main() {
    // Example usage:
    // Create 3 stacks in a shared array of size 10
    n_stacks my_stacks(3, 10);

    // Push elements onto stack 0
    my_stacks.push(0, 10);
    my_stacks.push(0, 20);

    // Push elements onto stack 2
    my_stacks.push(2, 100);
    my_stacks.push(2, 200);

    // Pop from stack 0
    cout << "Popped from stack 0: " << my_stacks.pop(0) << endl; // Should be 20

    // Pop from stack 2
    cout << "Popped from stack 2: " << my_stacks.pop(2) << endl; // Should be 200

    // Pop from stack 0 again
    cout << "Popped from stack 0: " << my_stacks.pop(0) << endl; // Should be 10

    // Try to pop from empty stack 1
    my_stacks.pop(1); // Should print "Stack Underflow!!"

    return 0;
}
