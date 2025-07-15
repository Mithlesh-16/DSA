#include <iostream>
using namespace std;

class Node
{
    int data;
    Node *next;
    Node *random;

public:
    Node(int x)
    {
        this->data = x;
        this->next = nullptr;
        this->random = nullptr;
    }
};

int main()
{

    return 0;
}