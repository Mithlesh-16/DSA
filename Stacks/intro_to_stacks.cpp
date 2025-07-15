#include <iostream>
#include <stack>
using namespace std;

/// @note Stack Implementation can be done by both ways, namely -
/// @note i) Array
/// @note ii) Linked List

/// @brief array implementation of stacks
class stacks
{
private:
    int *arr;
    int size;
    int pos = -1;

public:
    stacks(int size)
    {
        this->size = size;
        arr[size];
    }

    bool isEmpty()
    {
        if (pos - size > 1)
            return true;
        else
            return false;
    }

    void push(int x)
    {
        if (pos < size)
        {
            pos++;
            arr[pos] = x;
        }
        else
        {
            cout << "Stack Overflow !!" << endl;
        }
    }

    void pop()
    {
        pos--;
    }

    int top()
    {
        if (pos >= 0 and pos < size)
        {
            cout << "Position : " << pos << endl;
            return arr[pos];
        }
        else
            return -1;
    }
};

/// @brief Linked List Implementation of Stacks

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

class Stacks
{
private:
    int size;
    int position = -1;
    Node *head = nullptr;
    Node *curr = nullptr;

public:
    Stacks(int size)
    {
        this->size = size;
    }

    void push(int data)
    {
        if (position < size - 1)
        {
            position++;
            Node *temp = new Node(data);
            if (curr)
                curr->next = temp;
            else
                head = temp;

            curr = temp;
        }
        else
            cout << "Stack Overflow !! " << endl;
    }

    void pop()
    {
        if (position >= 0)
        {
            Node *temp2 = head;
            while (temp2 and temp2->next != curr)
            {
                temp2 = temp2->next;
            }

            delete curr;
            curr = temp2;
            position--;
        }
        else
        {
            cout << " Stack not popped !! " << endl;
        }
    }

    int top()
    {
        if (curr)
            return curr->data;
        else
            return -1;
    }

    bool is_empty()
    {
        if (curr == nullptr)
            return true;
        else
            return false;
    }

    ~Stacks()
    {
        if (curr)
            cout << "Deleted node with data : " << curr->data << endl;
    }
};

int main()
{

    // inbuilt stack class
    stack<int> s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);

    cout << s1.empty() << endl;
    cout << s1.top() << endl;
    cout << s1.size() << endl;
    s1.pop();
    cout << s1.top() << endl;
    cout << s1.size() << endl;

    /// @brief Array stacks implementation

    stacks s2(5);
    s2.push(1);
    s2.push(2);
    s2.push(3);
    s2.push(4);
    s2.push(5);
    // s2.push(6);
    // s2.push(7);

    cout << "Top : " << s2.top() << endl;
    s2.pop();
    cout << "Top : " << s2.top() << endl;
    s2.pop();
    cout << "Top : " << s2.top() << endl;
    cout << "Empty : " << s2.isEmpty() << endl;

    /// @brief Linked List Stacks Implementation

    Stacks s3(6);
    s3.push(10);
    s3.push(11);
    s3.push(12);
    s3.push(13);
    s3.push(14);
    s3.push(15);
    cout << "Top : " << s3.top() << endl;
    s3.pop();
    cout << "Top : " << s3.top() << endl;
    s3.pop();
    cout << "Top : " << s3.top() << endl;
    s3.pop();
    cout << "Top : " << s3.top() << endl;
    s3.pop();
    cout << "Top : " << s3.top() << endl;
    s3.pop();
    cout << "Top : " << s3.top() << endl;
    s3.pop();
    cout << "Top : " << s3.top() << endl;
    s3.pop();
    cout << "Top : " << s3.top() << endl;
    cout << s3.is_empty() << endl;
    return 0;
}