#include <bits/stdc++.h>
using namespace std;

void insert_at_position(stack<int> &s, int num)
{
    // base case
    if (s.empty() || s.top() >= num)
    {
        s.push(num);
        return;
    }

    int tmp = s.top();
    s.pop();

    // recursive call
    insert_at_position(s, num);

    // backtracking
    s.push(tmp);
}

void sort_stack(stack<int> &s)
{
    // base case
    if (s.empty())
    {
        return;
    }

    int num = s.top();
    s.pop();

    // recursive call
    sort_stack(s);

    // backtracking
    insert_at_position(s, num);
}

void print_stack(stack<int> s)
{
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
}

int main()
{

    stack<int> s;
    int size;
    cin >> size;

    // making stack
    while (size > 0)
    {
        int tmp = 0;
        cin >> tmp;
        s.push(tmp);
        size--;
    }

    cout << "Before Sorting : " << endl;
    print_stack(s);
    cout << endl;

    sort_stack(s);

    cout << "After Sorting : " << endl;
    print_stack(s);
    cout << endl;

    return 0;
}