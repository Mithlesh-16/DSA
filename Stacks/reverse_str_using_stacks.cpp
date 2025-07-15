#include <iostream>
#include <stack>
using namespace std;

int main()
{
    string s = "Mithlesh";
    stack<char> s1;

    int i = 0;
    while (s[i])
    {
        s1.push(s[i]);
        i++;
    }

    s = "";
    while (--i >= 0)
    {
        s += s1.top();
        s1.pop();
    }

    cout << s << endl;

    return 0;
}