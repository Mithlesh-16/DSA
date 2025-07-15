#include <iostream>
using namespace std;

#include <bits/stdc++.h>
class TwoStack
{

public:
    int pos1 = -1, pos2 = size, size = 0;
    int *arr;
    // Initialize TwoStack.
    TwoStack(int s)
    {
        size = s;
        pos2 = s;
        arr = new int[s];
    }

    // Push in stack 1.
    void push1(int num)
    {
        // stack 1
        if (pos2 - pos1 > 1)
        {
            pos1++;
            arr[pos1] = num;
        }
    }

    // Push in stack 2.
    void push2(int num)
    {
        if (pos2 - pos1 > 1)
        {
            pos2--;
            arr[pos2] = num;
        }
    }

    // Pop from stack 1 and return popped element.
    int pop1()
    {
        if (pos1 >= 0)
        {
            pos1--;
            return arr[pos1 + 1];
        }
        else
            return -1;
    }

    // Pop from stack 2 and return popped element.
    int pop2()
    {
        if (pos2 <= size - 1)
        {
            pos2 += 1;
            return arr[pos2 - 1];
        }
        else
            return -1;
    }
};

int main()
{

    return 0;
}