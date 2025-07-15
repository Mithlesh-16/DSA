#include <iostream>
#include <stack>
using namespace std;
bool match_parenthesis(stack<char> s1)
{
    if (s1.top() == ')' || s1.top() == '}' || s1.top() == ']')
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool valid_parenthesis(string s)
{
    int i = 0;
    stack<char> s1;
    while (i < s.size())
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
        {
            s1.push(s[i]);
        }
        else
        {
            if (match_parenthesis(s1))
            {
                s1.pop();
            }
            else
                return false;
        }
        if (s1.empty())
            return true;
        else
            return false;
    }
}

int main()
{

    string s = "";
    cin >> s;

    if (valid_parenthesis(s))
    {
        cout << "Valid Parenthesis !!" << endl;
    }
    else
    {
        cout << "Not a valid Parenthesis !!" << endl;
    }

    return 0;
}