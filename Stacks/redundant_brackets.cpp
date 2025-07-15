#include <iostream>
#include <stack>
using namespace std;

bool redundant_brackets(string s)
{
    stack<int> s2;

    int i = 0;
    while (i < s.size())
    {
        if (s[i] == '(' or s[i] == '+' or s[i] == '-' or s[i] == '*' or s[i] == '/')
        {
            s2.push(s[i]);
        }
        else if (s[i] == ')')
        {
            if (s2.top() != '+' and s2.top() != '-' and s2.top() != '*' and s2.top() != '/')
            {
                return true;    //redundant brackets found
            }
            else
            {
                while (s2.top() != '(')
                {
                    s2.pop();
                }
                s2.pop();
            }
        }
        i++;
    }
    return false;
}

int main()
{
    string s = "";
    cin >> s;
    cout << redundant_brackets(s) << endl;

    return 0;
}