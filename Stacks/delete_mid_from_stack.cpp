#include <iostream>
#include <stack>
using namespace std;

void delete_middle_elem(int count, stack<int> &s1, int size)
{
    // base case
    if (count == size / 2)
    {
        s1.pop();
        return;
    }

    int num = s1.top();
    s1.pop();
    // recursive calls
    delete_middle_elem(count + 1, s1, size);
    s1.push(num);
}

int main()
{

    stack<int> s1;
    s1.push(3);
    s1.push(4);
    s1.push(2);
    s1.push(0);
    s1.push(1);

    int count = 0;
    delete_middle_elem(count, s1, s1.size());

    while (!s1.empty())
    {
        cout << s1.top() << endl;
        s1.pop();
    }

    return 0;
}