#include <iostream>
#include <stack>
using namespace std;
void insert_at_bottom(int temp, stack<int> &s)
{
    // base case
    if (s.empty())
    {
        s.push(temp);
        return;
    }
    int temp2 = s.top();
    s.pop();
    insert_at_bottom(temp, s);
    s.push(temp2);
}

void reverse_stack(stack<int> &s)
{
    // base case
    if (s.empty())
        return;

    int temp = s.top();
    s.pop();
    reverse_stack(s);
    insert_at_bottom(temp, s);
}

void print_stacks(stack<int> s)
{
    // print stacks
    while (!s.empty())
    {
        cout << s.top() << endl;
        s.pop();
    }
}

int main()
{

    stack<int> s;
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);
    s.push(7);
    print_stacks(s);

    cout << "after reversal : " << endl;
    reverse_stack(s);

    print_stacks(s);

    return 0;
}